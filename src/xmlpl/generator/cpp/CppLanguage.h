#ifndef CPPLANGUAGE_H
#define CPPLANGUAGE_H

#include <xmlpl/Language.h>

namespace xmlpl {
  class CppLibraryImporter;
  class CppBuilder;

  class CppLanguage : public Language {
    CppLibraryImporter *libraryImporter;
    CppBuilder *builder;

  public:
    CppLanguage() : libraryImporter(0), builder(0) {}

    virtual std::string getName() const {return "c++";}
    virtual CodeGenerator *createCodeGenerator(std::ostream &out,
					       const std::string sourceFile);
    virtual LibraryImporter *getLibraryImporter();
    virtual Builder *getBuilder();

    virtual void declareBuiltins(Environment *env);
  };
};
#endif // CPPLANGUAGE_H
