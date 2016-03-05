#include "CppBuilder.h"

#include <xmlpl/Utils.h>
#include <xmlpl/Options.h>
#include <xmlpl/Language.h>
#include <xmlpl/LibraryImporter.h>

#include <config.h>

using namespace xmlpl;
using namespace std;

CppBuilder::CppBuilder() {
  CXX = Utils::getEnvVar("CXX", "g++");
  LIBTOOL = Utils::getEnvVar("LIBTOOL", "libtool");
  RM = Utils::getEnvVar("RM", "rm -f");
}


void CppBuilder::buildStandalone(string input, string output, list<string> &buildArgs,
				 list<string> &linkArgs) {
  // Build Object File
  string objFile = buildObject(input, buildArgs);

  // Link Executable
   list<string> args;

  args.push_back("libxmlpl_cpp_runtime-config");
  args.push_back("--libs");

  Utils::argsFromCommand(args);

  args.push_front(CXX);
  args.push_front("--mode=link");
  if (Options::getInstance()->getVerbosity() == 0) args.push_front("--quiet");
  args.push_front(LIBTOOL);

  args.push_back("-o");
  if (output != "") args.push_back(output);
  else args.push_back(Utils::removeSuffix(input));

  args.push_back(objFile);

  args.splice(args.end(), linkArgs);

  // Add imported libraries and fine cheeses
  addImportedLibraries(args);

  Utils::runCommand(args);

  if (!Options::getInstance()->getSaveTemps())
    clean(objFile);
}

void CppBuilder::buildLibrary(string input, string output, list<string> &buildArgs,
			      list<string> &linkArgs) {
  // Build Object File
  string objFile = buildObject(input, buildArgs);

  // Link Library
  list<string> args;

  args.push_back(LIBTOOL);
  if (Options::getInstance()->getVerbosity() == 0) args.push_back("--quiet");
  args.push_back("--mode=link");
  args.push_back(CXX);

  args.push_back("-avoid-version");

  args.push_back("-o");
  if (output != "") args.push_back(output);
  else args.push_back(string("lib") + Utils::changeSuffix(input, "la"));

  args.splice(args.end(), linkArgs);
  
  args.push_back(objFile);

  // Add imported libraries and fine cheeses
  addImportedLibraries(args);

  Utils::runCommand(args);

  if (!Options::getInstance()->getSaveTemps())
    clean(objFile);
}

std::string CppBuilder::buildObject(string input, list<string> &buildArgs) {
  list<string> args;
  args.push_back("libxmlpl_cpp_runtime-config");
  args.push_back("--cflags");

  Utils::argsFromCommand(args);

  args.push_front(CXX);
  args.push_front("--mode=compile");
  if (Options::getInstance()->getVerbosity() == 0) args.push_front("--quiet");
  args.push_front(LIBTOOL);

  args.splice(args.end(), buildArgs);

  args.push_back("-c");
  args.push_back(input);

  Utils::runCommand(args);

  // Compute object file name
  string objFile = Utils::changeSuffix(input, "lo");

  // Libtool will ouput to the current directory
  string::size_type pos = objFile.find_last_of('/');
  if (pos != string::npos) return objFile.substr(pos + 1);
  return objFile;
}

void CppBuilder::clean(string filename) {
  list<string> args;

  args.push_back(LIBTOOL);
  if (Options::getInstance()->getVerbosity() == 0) args.push_back("--quiet");
  args.push_back("--mode=clean");
  args.push_back(RM);

  args.push_back(filename);
  
  Utils::runCommand(args);
}

void CppBuilder::addImportedLibraries(list<string> &args) {
  LibraryImporter *importer = Options::getInstance()->getLanguage()->getLibraryImporter();

  LibraryImporter::libraries_t::const_iterator it;
  for (it = importer->librariesBegin(); it != importer->librariesEnd(); it++)
    args.push_back(it->second);
}
