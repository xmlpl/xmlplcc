#ifndef VARIABLEDECL_H
#define VARIABLEDECL_H

#include "XmlPLAST.h"
#include <xmlpl/parser/environment/EnvEntry.h>

class VariableDecl;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<VariableDecl> RefVariableDecl;

class VariableDecl : public XmlPLAST {
  EnvEntryRef entry;
  
 public:
  VariableDecl(const VariableDecl &o) : XmlPLAST(o), entry(o.entry) {}
  VariableDecl(const XmlPLAST &o) : XmlPLAST(o) {}
  VariableDecl() {}
  virtual ~VariableDecl() {}

  virtual void setType(int type) {}
  virtual int getType() const {return VAR_DECL;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  void setEntry(EnvEntryRef entry) {this->entry = entry;}
  EnvEntryRef getEntry() const {return entry;}

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // VARIABLEDECL_H
