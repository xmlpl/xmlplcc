#ifndef FORSTMT_H
#define FORSTMT_H

#include "XmlPLAST.h"

class ForStmt;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<ForStmt> RefForStmt;

class ForStmt : public XmlPLAST {
 public:
  ForStmt(const ForStmt &o) : XmlPLAST(o) {}
  ForStmt(const XmlPLAST &o) : XmlPLAST(o) {}
  ForStmt() {}
  virtual ~ForStmt() {}

  virtual void setType(int type) {}
  virtual int getType() const {return FOR;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // FORSTMT_H
