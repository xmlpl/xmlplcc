#ifndef FUNCTIONCALL_H
#define FUNCTIONCALL_H

#include "Expression.h"
#include <xmlpl/parser/environment/EnvEntry.h>

class FunctionCall;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<FunctionCall> RefFunctionCall;

class FunctionCall : public Expression {
  EnvEntryRef entry;

 public:
  FunctionCall(const FunctionCall &o) : Expression(o), entry(o.entry) {}
  FunctionCall(const XmlPLAST &o) : Expression(o) {}
  FunctionCall() {}
  virtual ~FunctionCall() {}

  virtual void setType(int type) {}
  virtual int getType() const {return FCALL;}

  void setEnvEntry(EnvEntryRef entry) {this->entry = entry;}
  EnvEntryRef getEnvEntry() const {return entry;}
  const Name getName() const {if (entry != 0) return entry->getName(); else return "";}
  const unsigned int getDataType() const
  {return entry == 0 ? UNKNOWN_TYPE : entry->getType();}

  virtual const bool hasEffect() const {return true;}
  virtual const bool isSelfAppending() const {
    return xmlpl::Type::isSequence(getDataType()) && getTargetType().hasAppend();
  }

  virtual void validate();
  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // FUNCTIONCALL_H
