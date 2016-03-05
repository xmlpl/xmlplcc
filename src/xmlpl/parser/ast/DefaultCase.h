#ifndef DEFAULTCASE_H
#define DEFAULTCASE_H

#include "XmlPLAST.h"

class DefaultCase;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<DefaultCase> RefDefaultCase;

class DefaultCase : public XmlPLAST {
 public:
  DefaultCase(const DefaultCase &o) : XmlPLAST(o) {}
  DefaultCase(const XmlPLAST &o) : XmlPLAST(o) {}
  DefaultCase() {}
  virtual ~DefaultCase() {}

  virtual void setType(int type) {}
  virtual int getType() const {return DEFAULT;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // DEFAULTCASE_H
