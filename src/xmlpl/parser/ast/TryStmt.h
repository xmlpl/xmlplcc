#ifndef TRYSTMT_H
#define TRYSTMT_H

#include "XmlPLAST.h"

class TryStmt;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<TryStmt> RefTryStmt;

class TryStmt : public XmlPLAST {
 public:
  TryStmt(const TryStmt &o) : XmlPLAST(o) {}
  TryStmt(const XmlPLAST &o) : XmlPLAST(o) {}
  TryStmt() {}
  virtual ~TryStmt() {}

  virtual void setType(int type) {}
  virtual int getType() const {return TRY;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // TRYSTMT_H
