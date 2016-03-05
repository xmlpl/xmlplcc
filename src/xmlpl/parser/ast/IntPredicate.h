#ifndef INTPREDICATE_H
#define INTPREDICATE_H

#include "Filterable.h"

class IntPredicate;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<IntPredicate> RefIntPredicate;

class IntPredicate : public Filterable {
 public:
  IntPredicate(const XmlPLAST &o) : Filterable(o) {}
  IntPredicate() {}
  virtual ~IntPredicate() {}

  virtual void setType(int type) {}
  virtual int getType() const {return INT_PREDICATE;}

  virtual RefXmlPLAST getFilterChild() const {return getChild()->getNext();}
  virtual void setFilterChild(RefXmlPLAST child) {getChild()->setNextSibling(&*child);}

  virtual void validateIncomingType(const unsigned int type);

  virtual bool getRequiresPosition() const {return true;}
  virtual const bool isExpression() const {return false;}

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();
};
#endif // INTPREDICATE_H
