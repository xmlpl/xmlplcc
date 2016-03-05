#ifndef SEQUENCEEXPR_H
#define SEQUENCEEXPR_H

#include "Expression.h"

class SequenceExpr;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<SequenceExpr> RefSequenceExpr;

class SequenceExpr : public Expression {
  unsigned int dataType;

 public:
  SequenceExpr(const SequenceExpr &o) : Expression(o), dataType(o.dataType) {}
  SequenceExpr(const XmlPLAST &o) : Expression(o), dataType(SEQUENCE_FLAG) {}
  SequenceExpr() : dataType(SEQUENCE_FLAG) {}
  virtual ~SequenceExpr() {}

  virtual void setType(int type) {}
  virtual int getType() const {return SEQUENCE_EXPR;}

  const void setDataType(const unsigned int dataType) {this->dataType = dataType;}
  const unsigned int getDataType() const {return dataType;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual const bool isSelfAppending() const {return getTargetType().hasAppend();}

  virtual void setTargetType(const TargetType &targetType, bool resetOk = false);
  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // SEQUENCEEXPR_H
