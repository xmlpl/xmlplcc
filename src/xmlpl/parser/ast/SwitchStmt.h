#ifndef SWITCHSTMT_H
#define SWITCHSTMT_H

#include "XmlPLAST.h"

class SwitchStmt;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<SwitchStmt> RefSwitchStmt;

class SwitchStmt : public XmlPLAST {
 public:
  SwitchStmt(const SwitchStmt &o) : XmlPLAST(o) {}
  SwitchStmt(const XmlPLAST &o) : XmlPLAST(o) {}
  SwitchStmt() {}
  virtual ~SwitchStmt() {}

  virtual const unsigned int getDataType() const;

  virtual void setType(int type) {}
  virtual int getType() const {return SWITCH;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void validate();
  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // SWITCHSTMT_H
