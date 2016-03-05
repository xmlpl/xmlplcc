#ifndef TYPETEST_H
#define TYPETEST_H

#include "XmlPLAST.h"

class TypeTest;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<TypeTest> RefTypeTest;

class TypeTest : public XmlPLAST {
  unsigned int typeTest;

public:
  TypeTest(const TypeTest &o) : XmlPLAST(o), typeTest(o.typeTest) {}
  TypeTest(const XmlPLAST &o) : XmlPLAST(o), typeTest(UNKNOWN_TYPE) {}
  TypeTest() : typeTest(UNKNOWN_TYPE) {}
  virtual ~TypeTest() {}

  virtual void setType(int type) {}
  virtual int getType() const {return TYPE_TEST;}

  const unsigned int getDataType() const {return BOOLEAN_TYPE;}

  void setTypeTest(const unsigned int typeTest) {this->typeTest = typeTest;}
  const unsigned int getTypeTest() const {return typeTest;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // TYPETEST_H
