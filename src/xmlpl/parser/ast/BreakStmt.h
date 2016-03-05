#ifndef BREAKSTMT_H
#define BREAKSTMT_H

#include "XmlPLAST.h"

class BreakStmt;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<BreakStmt> RefBreakStmt;

class BreakStmt : public XmlPLAST {
 public:
  BreakStmt(const BreakStmt &o) : XmlPLAST(o) {}
  BreakStmt(const XmlPLAST &o) : XmlPLAST(o) {}
  BreakStmt() {}
  virtual ~BreakStmt() {}

  virtual void setType(int type) {}
  virtual int getType() const {return BREAK;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // BREAKSTMT_H
