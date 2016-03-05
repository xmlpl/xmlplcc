#ifndef FILTEREXPR_H
#define FILTEREXPR_H

#include "Filterable.h"

class FilterExpr;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<FilterExpr> RefFilterExpr;

class FilterExpr : public Filterable {
  unsigned int envDepth;
  bool doFunctionize;

 public:
  FilterExpr(const XmlPLAST &o) :
		Filterable(o), envDepth(0), doFunctionize(true) {}
  FilterExpr() : envDepth(0), doFunctionize(true) {}
  virtual ~FilterExpr() {}

  virtual void setType(int type) {}
  virtual int getType() const {return FILTER_EXPR;}

  virtual RefXmlPLAST getFilterChild() const {return getChild()->getNext();}
  virtual void setFilterChild(RefXmlPLAST child) {getChild()->setNextSibling(&*child);}

  virtual const bool isSelfAppending() const {return getTargetType().hasAppend();}
  virtual const bool isSelfCasting() const {return true;}
  virtual void setEnvDepth(const unsigned int envDepth) {this->envDepth = envDepth;}
  virtual unsigned int getEnvDepth() const {return envDepth;}
  virtual void setFunctionize(const bool doFunctionize)
  {this->doFunctionize = doFunctionize;}
  virtual bool functionize() {return doFunctionize;}

  virtual void validate();
  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();
};
#endif // FILTEREXPR_H
