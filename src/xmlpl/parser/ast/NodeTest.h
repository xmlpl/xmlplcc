#ifndef NODETEST_H
#define NODETEST_H

#include "XmlPLAST.h"

class NodeTest;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<NodeTest> RefNodeTest;

class NodeTest : public XmlPLAST {
  const unsigned int typeTest;

public:
  NodeTest(const NodeTest &o) : XmlPLAST(o), typeTest(o.typeTest) {}
  NodeTest(const XmlPLAST &o) : XmlPLAST(o), typeTest(ELEMENT_TYPE) {}
  NodeTest() : typeTest(ELEMENT_TYPE) {}
  virtual ~NodeTest() {}

  virtual void setType(int type) {}
  virtual int getType() const {return NODE_TEST;}

  virtual std::string getName() const {return getText();}

  const unsigned int getDataType() const {return BOOLEAN_TYPE;}

  void setTypeTest(const unsigned int typeTest) {this->typeTest = typeTest;}
  const unsigned int getTypeTest() const {return typeTest;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // NODETEST_H
