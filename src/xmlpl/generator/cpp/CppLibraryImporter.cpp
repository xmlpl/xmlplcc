#include "CppLibraryImporter.h"

#include <string>

#include <sys/types.h>
#include <sys/stat.h>
#include <glob.h>
#include <unistd.h>
#include <ltdl.h>

#include <BasicUtils/BasicException.h>

#include <xmlpl/ErrorHandler.h>
#include <xmlpl/Utils.h>
#include <xmlpl/Options.h>
#include <xmlpl/parser/environment/Environment.h>

#include <xmlpl/cpp/runtime/LibraryInfo.h>

using namespace std;
using namespace xmlpl;

CppLibraryImporter::CppLibraryImporter() {lt_dlinit();}

CppLibraryImporter::~CppLibraryImporter() {lt_dlexit();}


const vector<EnvEntryRef> CppLibraryImporter::import(const Name &name,
						     const VersionExpression *ve,
						     Environment &env,
						     const Location &location) {
  // Find library
  bool isSymbolName;
  Version version;
  string filename = findLibrary(name, ve, version, isSymbolName, location);

  if (filename == "") {
    ErrorHandler::error("import failed, library '" + name.getFullRealName() +
			"' not found", location);
    return vector<EnvEntryRef>();
  }

  const LibraryInfo *info = getLibraryInfo(filename, location);
  if (!info) return vector<EnvEntryRef>();

  // Check version
  if (version != info->version)
    ErrorHandler::warning(string("library '") + filename +
			  "' installed incorrectly, file name does not match version " +
			  info->version.toString(),
			  location);

  // Check namespace
  string expectedNS = (isSymbolName ? name.getRealPrefix() : name.getFullRealName()) +
    "-" + version.toString();
  if (expectedNS != info->namespaceStr)
    ErrorHandler::warning(string("library '") + filename +
			  "' installed incorrectly, file name does not match namespace",
			  location);

  // Add to list of libraries
  addLibrary(filename, info->namespaceStr);

  // Adjust name if we are importing a whole library rather than a single symbol
  Name pathName;
  if (!isSymbolName) {
    pathName.setRealPrefix(name.getFullRealName());
    if (name.hasPseudonym()) pathName.setPrefix(name.getFullName());

  } else pathName = name;


  pathName.setNamespace(info->namespaceStr);

  return importLibrary(pathName, info, env, location);
}

const string CppLibraryImporter::findLibrary(const Name &name,
					     const VersionExpression *ve,
					     Version &version,
					     bool &isSymbolName,
					     const Location &location) {
  const vector<string> &libraryPath = Options::getInstance()->getLibraryPath();
  vector<string>::const_iterator it;
  struct stat stat_buf;

  for (it = libraryPath.begin(); it != libraryPath.end(); it++) {

    vector<string> namePath;
    Name::parsePath(name.getFullRealName(), namePath);
    string pathname;
    for (unsigned int i = 0; i < namePath.size(); i++) {
      string prefix = *it + pathname + "/lib" + namePath[i] + "-";
      string suffix = ".la";
      string pattern = prefix + "*" + suffix;

      glob_t globbuf;
      if (glob(pattern.c_str(), 0, 0, &globbuf) == 0) {

	if (i + 2 < namePath.size()) {
	  ErrorHandler::warning(string("import path shadowed by: ") + globbuf.gl_pathv[0],
				location);
	  break;

	} else {
	  isSymbolName = i + 1 != namePath.size();

	  // Find correct version
	  string filename;

	  for (size_t i = 0; i < globbuf.gl_pathc; i++) {
	    string::size_type len =
	      strlen(globbuf.gl_pathv[i]) - (prefix.length() + suffix.length());
	    // TODO validate version parsing
	    Version v = string(&globbuf.gl_pathv[i][prefix.length()], len);

	    if ((!ve || ve->matches(v)) && version < v) {
	      version = v;
	      filename = globbuf.gl_pathv[i];
	    }
	  }

	  return filename;
	}
      }

      pathname += "/" + namePath[i];

      if (stat((*it + "/" + pathname).c_str(), &stat_buf) != 0) break;
      if (!S_ISDIR(stat_buf.st_mode)) break;
    }
  }

  return "";
}

const LibraryInfo *CppLibraryImporter::getLibraryInfo(const string &filename,
						      const Location &location) {
  // Open library
  lt_dlhandle handle = lt_dlopen(filename.c_str());

  if (!handle) {
    ErrorHandler::error("could not open '" + filename + "': " + lt_dlerror());
    return 0;
  }

  // Access xmlpl library info
  lt_ptr libraryInfoPtr = lt_dlsym(handle, LIBRARY_INFO_NAME);

  if (!libraryInfoPtr) {
    ErrorHandler::error("could not access xmlpl library info in '" + filename + "': " +
			lt_dlerror(), location);
    return 0;
  }

  return (const LibraryInfo *)libraryInfoPtr;
}

const vector<EnvEntryRef> CppLibraryImporter::importLibrary(const Name &name,
							    const LibraryInfo *info,
							    Environment &env,
							    const Location &location) {
  vector<EnvEntryRef> entries;
  
  // Import Symbols
  if (name.getName() != "") {
    const Symbol *symbol = findSymbol(info->table, info->tableSize,
				      name.getRealName().c_str());
    if (!symbol) {
      ErrorHandler::error(string("cannot find symbol '") + name.getRealName() +
			  "' in '" + name.getRealPrefix() + "'");
      return entries;
    }

    EnvEntryRef entry = importSymbol(symbol, name, env, location);
    if (entry != 0) entries.push_back(entry);

  } else {

    for (unsigned int i = 0; i < info->tableSize; i++) {
      EnvEntryRef entry =
	importSymbol(&info->table[i], name, env, location);
      if (entry != 0) entries.push_back(entry);
    }
  }

  return entries;
}

const Symbol *CppLibraryImporter::findSymbol(const Symbol *table, const unsigned int size,
					     const char *name) {
  int l = 0;
  int r = size - 1;
  int mid;
  int compare;

  while (l <= r) {
    mid = (l + r) / 2;

    compare = strcmp(name, table[mid].name);

    if (compare == 0) return &table[mid];
    if (compare < 0) r = mid - 1;
    else l = mid + 1;
  }

  return 0;
}

EnvEntryRef CppLibraryImporter::importSymbol(const Symbol *symbol, const Name &n,
					     Environment &env, const Location &location) {
  Name name = n;
  if (name.getName() == "") {
    name.setRealName(symbol->name);
    if (name.hasPseudonym()) name.setName(symbol->name);
  }

  ErrorHandler::debug(ErrorHandler::DEBUG_IMPORT,
		      string("importing ") + name.getFullRealName() +
		      (name.hasPseudonym() ? " as " + name.getFullName() : ""));


  if (symbol->isVariable())
    return env.declareVariable(name, symbol->type, symbol->isConstant(), location);

  else if (symbol->isFunction()) {
    args_t args;
    if (symbol->args)
      for (unsigned int i = 0; symbol->args[i].flags; i++) {
	const Symbol &arg = symbol->args[i];
	args.push_back(Arg(arg.type, arg.isByReference(), arg.name));
      }

    return env.declareFunction(name, symbol->type, args, location);

  }

  ErrorHandler::error("unexpected symbol type in library", location);
  return 0;
}
