#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "XmlPLAST.h"

class Expression : public XmlPLAST {
  TargetType targetType;

 public:
  Expression(const Expression &o) : XmlPLAST(o), targetType(o.targetType) {}
  Expression(const XmlPLAST &o) : XmlPLAST(o), targetType(UNKNOWN_TYPE) {}
  Expression() : targetType(UNKNOWN_TYPE) {}
  virtual ~Expression() {}

  virtual const bool isExpression() const {return true;}

  virtual void setTargetType(const TargetType &targetType, bool resetOk = false) {
    ASSERT_OR_THROW("target type already set!",
		    this->targetType.getType() == UNKNOWN_TYPE || resetOk);
    this->targetType = targetType;
  }
  virtual bool isTargetTypeSet() const {return targetType.getType() != UNKNOWN_TYPE;}
  virtual const TargetType getTargetType() const {
    return isTargetTypeSet() ? targetType : getDataType();
  }
};
#endif // EXPRESSION_H
