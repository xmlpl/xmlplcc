#ifndef XMLQNAME_H
#define XMLQNAME_H

#include "XmlPLAST.h"

class XMLQName;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<XMLQName> RefXMLQName;

class XMLQName : public XmlPLAST {
  std::string prefix;
  std::string name;

 public:
  XMLQName(const XMLQName &o) : XmlPLAST(o) {}
  XMLQName(const XmlPLAST &o) : XmlPLAST(o) {}
  XMLQName() {}
  virtual ~XMLQName() {}

  virtual void setType(int type) {}
  virtual int getType() const {return XML_QNAME;}

  virtual const unsigned int getDataType() const {return QNAME_TYPE;}

  void setPrefix(const std::string prefix) {this->prefix = prefix;}
  std::string getPrefix() const {return prefix;}
  void setName(const std::string name) {this->name = name;}
  std::string getName() const {return name;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // XMLQNAME_H
