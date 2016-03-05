#ifndef CASESTMT_H
#define CASESTMT_H

#include "XmlPLAST.h"

class CaseStmt;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<CaseStmt> RefCaseStmt;

class CaseStmt : public XmlPLAST {
 public:
  CaseStmt(const CaseStmt &o) : XmlPLAST(o) {}
  CaseStmt(const XmlPLAST &o) : XmlPLAST(o) {}
  CaseStmt() {}
  virtual ~CaseStmt() {}

  virtual const unsigned int getDataType() const;

  virtual void setType(int type) {}
  virtual int getType() const {return CASE;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // CASESTMT_H
