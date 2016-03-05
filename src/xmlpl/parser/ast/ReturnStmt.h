#ifndef RETURNSTMT_H
#define RETURNSTMT_H

#include "XmlPLAST.h"

class ReturnStmt;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<ReturnStmt> RefReturnStmt;

class ReturnStmt : public XmlPLAST {
 public:
  ReturnStmt(const ReturnStmt &o) : XmlPLAST(o) {}
  ReturnStmt(const XmlPLAST &o) : XmlPLAST(o) {}
  ReturnStmt() {}
  virtual ~ReturnStmt() {}

  virtual void setType(int type) {}
  virtual int getType() const {return RETURN;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // RETURNSTMT_H
