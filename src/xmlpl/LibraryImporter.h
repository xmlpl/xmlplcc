#ifndef LIBRARYIMPORTER_H
#define LIBRARYIMPORTER_H

#include "Location.h"
#include "parser/environment/Environment.h"
#include "parser/environment/Name.h"
#include "parser/environment/VersionExpression.h"

#include <map>
#include <string>

class Environment;

namespace xmlpl {
  class LibraryImporter {
  public:
    typedef std::map<std::string, std::string> libraries_t;
  private:
    libraries_t libraries;
  public:
    virtual ~LibraryImporter() {}

    virtual bool addLibrary(const std::string &library, const std::string &ns);
    virtual libraries_t::const_iterator librariesBegin() const {return libraries.begin();}
    virtual libraries_t::const_iterator librariesEnd() const {return libraries.end();}

    virtual const std::vector<EnvEntryRef> import(const Name &path,
						  const VersionExpression *ve,
						  Environment &env,
						  const Location &location) = 0;
  };
};
#endif // LIBRARYIMPORTER_H
