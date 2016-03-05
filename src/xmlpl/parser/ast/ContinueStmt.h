#ifndef CONTINUESTMT_H
#define CONTINUESTMT_H

#include "XmlPLAST.h"

class ContinueStmt;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<ContinueStmt> RefContinueStmt;

class ContinueStmt : public XmlPLAST {
 public:
  ContinueStmt(const ContinueStmt &o) : XmlPLAST(o) {}
  ContinueStmt(const XmlPLAST &o) : XmlPLAST(o) {}
  ContinueStmt() {}
  virtual ~ContinueStmt() {}

  virtual void setType(int type) {}
  virtual int getType() const {return CONTINUE;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // CONTINUESTMT_H
