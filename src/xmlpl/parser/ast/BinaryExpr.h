#ifndef BINARYEXPR_H
#define BINARYEXPR_H

#include "Expression.h"

class BinaryExpr;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<BinaryExpr> RefBinaryExpr;

class BinaryExpr : public Expression {
  unsigned int dataType;

 public:
  BinaryExpr(const BinaryExpr &o) : Expression(o), dataType(o.dataType) {}
  BinaryExpr(const XmlPLAST &o) : Expression(o), dataType(UNKNOWN_TYPE) {}
  BinaryExpr() : dataType(UNKNOWN_TYPE) {}
  virtual ~BinaryExpr() {}

  virtual const unsigned int getDataType() const {return dataType;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  std::string getOp() const;

  virtual void validate();
  unsigned int validate(const unsigned int leftType, const unsigned int rightType);
  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // BINARYEXPR_H
