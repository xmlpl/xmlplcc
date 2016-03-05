#ifndef ARRAYEXPR_H
#define ARRAYEXPR_H

#include "Expression.h"

class ArrayExpr;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<ArrayExpr> RefArrayExpr;

class ArrayExpr : public Expression {
  unsigned int dataType;

 public:
  ArrayExpr(const ArrayExpr &o) : Expression(o), dataType(o.dataType) {}
  ArrayExpr(const XmlPLAST &o) : Expression(o), dataType(UNKNOWN_TYPE) {}
  ArrayExpr() : dataType(UNKNOWN_TYPE) {}
  virtual ~ArrayExpr() {}

  virtual void setType(int type) {}
  virtual int getType() const {return ARRAY_EXPR;}

  virtual const unsigned int getDataType() const {return dataType;}
  virtual const bool isConstant() const {return !getChild() || getChild()->isConstant();}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void validate();
  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // ARRAYEXPR_H
