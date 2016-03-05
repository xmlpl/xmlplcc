#ifndef XMLATTR_H
#define XMLATTR_H

#include "Expression.h"

class XMLAttr;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<XMLAttr> RefXMLAttr;

class XMLAttr : public Expression {
  std::string value;

 public:
  XMLAttr(const XMLAttr &o) : Expression(o) {}
  XMLAttr(const XmlPLAST &o) : Expression(o) {}
  XMLAttr(const XmlPLAST &o, const std::string &value) :
    Expression(o), value(value) {}
  XMLAttr() {}
  virtual ~XMLAttr() {}

  virtual void setType(int type) {}
  virtual int getType() const {return XML_ATTR;}

  virtual const unsigned int getDataType() const {return ATTRIBUTE_TYPE;}
  virtual const bool isXML() const {return true;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // XMLATTR_H
