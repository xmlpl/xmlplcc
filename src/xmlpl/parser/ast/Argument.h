#ifndef ARGUMENT_H
#define ARGUMENT_H

#include "XmlPLAST.h"
#include <xmlpl/parser/environment/Arg.h>

class Argument;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<Argument> RefArgument;

class Argument : public XmlPLAST {
  Arg arg;

 public:
  Argument(const XmlPLAST &o) : XmlPLAST(o) {}
  Argument() {}
  virtual ~Argument() {}

  virtual void setType(int type) {}
  virtual int getType() const {return ARGUMENT;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  void setArg(const Arg &arg) {this->arg = arg;}
  const Arg &getArg() const {return arg;}
  const unsigned int getDataType() const {return arg.type;}

  virtual void validate();
  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // ARGUMENT_H
