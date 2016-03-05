#ifndef THROWSTMT_H
#define THROWSTMT_H

#include "XmlPLAST.h"

class ThrowStmt;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<ThrowStmt> RefThrowStmt;

class ThrowStmt : public XmlPLAST {
 public:
  ThrowStmt(const ThrowStmt &o) : XmlPLAST(o) {}
  ThrowStmt(const XmlPLAST &o) : XmlPLAST(o) {}
  ThrowStmt() {}
  virtual ~ThrowStmt() {}

  virtual void setType(int type) {}
  virtual int getType() const {return THROW;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void validate();
  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // THROWSTMT_H
