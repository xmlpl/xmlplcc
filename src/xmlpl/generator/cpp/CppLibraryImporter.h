#ifndef CPPLIBRARYIMPORTER_H
#define CPPLIBRARYIMPORTER_H

#include <xmlpl/LibraryImporter.h>

#include <vector>

namespace xmlpl {
  class Symbol;
  class LibraryInfo;

  class CppLibraryImporter : public LibraryImporter {
  public:
    CppLibraryImporter();
    virtual ~CppLibraryImporter();

    virtual const std::vector<EnvEntryRef> import(const Name &name,
						  const VersionExpression *ve,
						  Environment &env,
						  const Location &location);

    virtual const std::string findLibrary(const Name &name, const VersionExpression *ve,
					  Version &version, bool &isSymbolName,
					  const Location &location);

  protected:
    const LibraryInfo *getLibraryInfo(const std::string &filename, const Location &location);

    const std::vector<EnvEntryRef> importLibrary(const Name &name, const LibraryInfo *info,
						 Environment &env, const Location &location);
    const Symbol *findSymbol(const Symbol *table, const unsigned int size, const char *name);
    EnvEntryRef importSymbol(const Symbol *symbol, const Name &name, Environment &env,
			     const Location &location);
  };
};
#endif // CPPLIBRARYIMPORTER_H
