#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include "parser/ast/ASTVisitor.h"
#include "parser/ast/XmlPLASTTypes.h"
#include <iostream>

namespace xmlpl {

  class CodeGenerator : public ASTVisitor, public  XmlPLLexerTokenTypes {
  protected:
    std::ostream &out;
    const std::string sourceFile;
    
  public:
    CodeGenerator(std::ostream &out, const std::string sourceFile) :
      out(out), sourceFile(sourceFile) {}
    virtual ~CodeGenerator() {}
  };
};
#endif // CODEGENERATOR_H
