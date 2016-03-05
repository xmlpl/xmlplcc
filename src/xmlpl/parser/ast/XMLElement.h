#ifndef XMLELEMENT_H
#define XMLELEMENT_H

#include "Expression.h"

class XMLElement;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<XMLElement> RefXMLElement;

class XMLElement : public Expression {
  unsigned int envDepth;

 public:
  XMLElement(const XmlPLAST &o) : Expression(o), envDepth(0) {}
  XMLElement() : envDepth(0) {}
  virtual ~XMLElement() {}

  virtual void setType(int type) {}
  virtual int getType() const {return XML_ELEM;}

  virtual const unsigned int getDataType() const {return ELEMENT_TYPE;}

  virtual const bool isXML() const {return true;}
  virtual const bool isSelfAppending() const {return getTargetType().hasAppend();}
  virtual void setEnvDepth(const unsigned int envDepth) {this->envDepth = envDepth;}
  virtual unsigned int getEnvDepth() const {return envDepth;}
  virtual bool functionize() {return true;}

  virtual void validate();
  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();
};
#endif // XMLELEMENT_H
