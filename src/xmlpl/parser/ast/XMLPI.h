#ifndef XMLPI_H
#define XMLPI_H

#include "Expression.h"

class XMLPI;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<XMLPI> RefXMLPI;

class XMLPI : public Expression {
 public:
  XMLPI(const XMLPI &o) : Expression(o) {}
  XMLPI(const XmlPLAST &o) : Expression(o) {}
  XMLPI() {}
  virtual ~XMLPI() {}

  virtual void setType(int type) {}
  virtual int getType() const {return XML_PI;}

  virtual const unsigned int getDataType() const {return PI_TYPE;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();
  virtual const bool isXML() const {return true;}
  virtual const bool isSelfAppending() const {return getTargetType().hasAppend();}

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // XMLPI_H
