#ifndef CONSTANT_H
#define CONSTANT_H

#include "Expression.h"

class Constant;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<Constant> RefConstant;

class Constant : public Expression {
  unsigned int dataType;

 public:
  Constant(const Constant &o) : Expression(o), dataType(o.dataType) {}
  Constant(const XmlPLAST &o) : Expression(o), dataType(UNKNOWN_TYPE) {}
  Constant() : dataType(UNKNOWN_TYPE) {}
  virtual ~Constant() {}

  virtual void setType(int type) {}
  virtual int getType() const {return CONSTANT;}

  void setDataType(unsigned int dataType) {this->dataType = dataType;}
  const unsigned int getDataType() const {return dataType;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // CONSTANT_H
