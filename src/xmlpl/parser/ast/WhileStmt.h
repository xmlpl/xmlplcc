#ifndef WHILESTMT_H
#define WHILESTMT_H

#include "XmlPLAST.h"

class WhileStmt;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<WhileStmt> RefWhileStmt;

class WhileStmt : public XmlPLAST {
 public:
  WhileStmt(const WhileStmt &o) : XmlPLAST(o) {}
  WhileStmt(const XmlPLAST &o) : XmlPLAST(o) {}
  WhileStmt() {}
  virtual ~WhileStmt() {}

  virtual void setType(int type) {}
  virtual int getType() const {return WHILE;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // WHILESTMT_H
