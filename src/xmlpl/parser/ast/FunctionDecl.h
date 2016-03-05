#ifndef FUNCTIONDECL_H
#define FUNCTIONDECL_H

#include "XmlPLAST.h"
#include <xmlpl/parser/environment/EnvEntry.h>

class FunctionDecl;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<FunctionDecl> RefFunctionDecl;

class FunctionDecl : public XmlPLAST {
  EnvEntryRef entry;
  bool forwardDecl;

 public:
  FunctionDecl(const XmlPLAST &o) : XmlPLAST(o), forwardDecl(true) {}
  FunctionDecl() : forwardDecl(true) {}
  virtual ~FunctionDecl() {}

  virtual void setType(int type) {}
  virtual int getType() const {return FUNC_DECL;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  void setEntry(const EnvEntryRef entry) {this->entry = entry;}
  EnvEntryRef getEntry() const {return entry;}
  void setForwardDecl(const bool forwardDecl) {this->forwardDecl = forwardDecl;}
  bool isForwardDecl() const {return forwardDecl;}

  RefXmlPLAST getBlock() const;

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // FUNCTIONDECL_H
