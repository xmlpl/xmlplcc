#ifndef PROGRAM_H
#define PROGRAM_H

#include "BlockStmt.h"
#include <xmlpl/parser/environment/EnvEntry.h>
#include <xmlpl/cpp/runtime/Version.h>

class Program;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<Program> RefProgram;

class Program : public BlockStmt {
  std::vector<EnvEntryRef> localSymbols;

 public:
  Program(const Program &o) : BlockStmt(o), localSymbols(o.localSymbols) {}
  Program(const XmlPLAST &o) : BlockStmt(o) {}
  Program(const std::vector<EnvEntryRef> &localSymbols) : localSymbols(localSymbols) {}
  Program() {}
  virtual ~Program() {}

  virtual void setType(int type) {}
  virtual int getType() const {return PROGRAM;}

  const std::vector<EnvEntryRef> &getLocalSymbols() const {return localSymbols;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // PROGRAM_H
