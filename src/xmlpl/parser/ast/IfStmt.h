#ifndef IFSTMT_H
#define IFSTMT_H

#include "XmlPLAST.h"

class IfStmt;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<IfStmt> RefIfStmt;

class IfStmt : public XmlPLAST {
 public:
  IfStmt(const IfStmt &o) : XmlPLAST(o) {}
  IfStmt(const XmlPLAST &o) : XmlPLAST(o) {}
  IfStmt() {}
  virtual ~IfStmt() {}

  virtual void setType(int type) {}
  virtual int getType() const {return IF;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // IFSTMT_H
