#ifndef REDIRECTSTMT_H
#define REDIRECTSTMT_H

#include "XmlPLAST.h"

class RedirectStmt;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<RedirectStmt> RefRedirectStmt;

class RedirectStmt : public XmlPLAST {
  unsigned int dataType;

 public:
  RedirectStmt(const XmlPLAST &o) : XmlPLAST(o), dataType(UNKNOWN_TYPE) {}
  RedirectStmt() : dataType(UNKNOWN_TYPE) {}
  virtual ~RedirectStmt() {}

  virtual void setType(int type) {}
  virtual int getType() const {return REDIRECT;}

  void setDataType(const unsigned int dataType) {this->dataType = dataType;}
  virtual const unsigned int getDataType() const {return dataType;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // REDIRECTSTMT_H
