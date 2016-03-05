#ifndef NAMETEST_H
#define NAMETEST_H

#include "XmlPLAST.h"

class NameTest;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<NameTest> RefNameTest;

class NameTest : public XmlPLAST {
  std::string name;
  std::string prefix;

public:
  NameTest(const NameTest &o) : XmlPLAST(o) {}
  NameTest(const XmlPLAST &o) : XmlPLAST(o) {}
  NameTest() {}
  virtual ~NameTest() {}

  virtual void setType(int type) {}
  virtual int getType() const {return NAME_TEST;}

  void setName(const std::string &name) {this->name = name;}
  std::string getName() const {return name;}
  void setPrefix(const std::string &prefix) {this->prefix = prefix;}
  std::string getPrefix() const {return prefix;}

  const unsigned int getDataType() const {return BOOLEAN_TYPE;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // NAMETEST_H
