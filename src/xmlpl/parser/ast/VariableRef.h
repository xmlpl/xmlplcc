#ifndef VARIABLEREF_H
#define VARIABLEREF_H

#include "Expression.h"
#include <xmlpl/parser/environment/EnvEntry.h>

class VariableRef;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<VariableRef> RefVariableRef;

class VariableRef : public Expression {
  EnvEntryRef entry;
  bool release;

 public:
  VariableRef(const VariableRef &o) : Expression(o), entry(o.entry), release(o.release) {}
  VariableRef(const XmlPLAST &o) : Expression(o), release(false) {}
  VariableRef() : release(false) {}
  virtual ~VariableRef() {}

  virtual void setType(int type) {}
  virtual int getType() const {return VAR_REF;}
  void setRelease(const bool release) {this->release = release;}
  bool getRelease() const {return release;}

  void setEnvEntry(EnvEntryRef entry) {this->entry = entry;}
  EnvEntryRef getEnvEntry() const {return entry;}
  const Name getName() const {if (entry != 0) return entry->getName(); else return "";}
  const unsigned int getDataType() const
  {if (entry != 0) return entry->getType(); else return UNKNOWN_TYPE;}

  virtual const bool isConstant() const {return entry == 0 || entry->isConstant();}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // VARIABLEREF_H
