#ifndef CAST_H
#define CAST_H

#include "Expression.h"
#include <xmlpl/parser/environment/Type.h>

class Cast;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<Cast> RefCast;

class Cast : public Expression {
  unsigned int dataType;

 public:
  Cast(const Cast &o) : Expression(o), dataType(o.dataType) {}
  Cast(const XmlPLAST &o) : Expression(o), dataType(UNKNOWN_TYPE) {}
  Cast() : dataType(UNKNOWN_TYPE) {}
  virtual ~Cast() {}

  virtual void setType(int type) {}
  virtual int getType() const {return CAST;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  const unsigned int getFrom() const {return getChild()->getDataType();}
  const unsigned int getTo() const {return dataType;}

  virtual const unsigned int getDataType() const {return dataType;}
  virtual void setDataType(const unsigned int dataType) {this->dataType = dataType;}

  virtual const bool hasEffect() const {return getChild() && getChild()->hasEffect();}
  virtual const bool isSelfAppending() const {
    return getTargetType().hasAppend() &&
      ((xmlpl::Type::isSequence(getFrom()) && xmlpl::Type::isSequence(getTo())) ||
      (xmlpl::Type::isNodeSeq(getTo())) ||
      (getChild() && getChild()->isSelfAppending()));
  }

  virtual void validate();
  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // CAST_H
