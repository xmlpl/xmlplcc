#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "CodeGenerator.h"
#include "LibraryImporter.h"
#include "Builder.h"

#include <string>
#include <map>

class Environment;

namespace xmlpl {
  class Language {
  public:
    typedef std::map<std::string, Language *> language_map_t;

  private:
    static language_map_t languageMap;

  public:
		virtual ~Language() {}

    static Language *get(const std::string name);
    static void add(Language *language);
    static language_map_t::const_iterator begin() {return languageMap.begin();}
    static language_map_t::const_iterator end() {return languageMap.end();}

    virtual std::string getName() const = 0;
    virtual CodeGenerator *createCodeGenerator(std::ostream &out,
					       const std::string sourceFile) = 0;
    virtual LibraryImporter *getLibraryImporter() = 0;
    virtual Builder *getBuilder() = 0;
    
    virtual void declareBuiltins(Environment *env) = 0;
  };
};
#endif // LANGUAGE_H
