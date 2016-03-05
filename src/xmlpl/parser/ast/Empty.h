#ifndef EMPTY_H
#define EMPTY_H

#include "XmlPLAST.h"

class Empty;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<Empty> RefEmpty;

class Empty : public XmlPLAST {
 public:
  Empty(const Empty &o) : XmlPLAST(o) {}
  Empty(const XmlPLAST &o) : XmlPLAST(o) {}
  Empty() {}
  virtual ~Empty() {}

  virtual void setType(int type) {}
  virtual int getType() const {return EMPTY;}

  virtual const unsigned int getDataType() const {return VOID_TYPE;}
  virtual void setTargetType(const TargetType &targetType, bool resetOk = false) {}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // EMPTY_H
