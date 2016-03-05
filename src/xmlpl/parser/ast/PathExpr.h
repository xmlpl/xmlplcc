#ifndef PATHEXPR_H
#define PATHEXPR_H

#include "Filterable.h"

class PathExpr;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<PathExpr> RefPathExpr;

class PathExpr : public Filterable {
  unsigned int envDepth;
  bool doFunctionize;

 public:
  PathExpr(const XmlPLAST &o) : Filterable(o), envDepth(0),
				doFunctionize(true) {}
  PathExpr() : envDepth(0), doFunctionize(true) {}
  virtual ~PathExpr() {}

  virtual void setType(int type) {}
  virtual int getType() const {return PATH;}

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
#endif // PATHEXPR_H
