#ifndef FOREACHSTMT_H
#define FOREACHSTMT_H

#include "XmlPLAST.h"

class ForeachStmt;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<ForeachStmt> RefForeachStmt;

class ForeachStmt : public XmlPLAST {
 public:
  ForeachStmt(const ForeachStmt &o) : XmlPLAST(o) {}
  ForeachStmt(const XmlPLAST &o) : XmlPLAST(o) {}
  ForeachStmt() {}
  virtual ~ForeachStmt() {}

  virtual void setType(int type) {}
  virtual int getType() const {return FOREACH;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // FOREACHSTMT_H
