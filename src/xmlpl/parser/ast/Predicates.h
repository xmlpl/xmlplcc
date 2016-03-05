#ifndef PREDICATES_H
#define PREDICATES_H

#include "Filterable.h"

class Predicates;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<Predicates> RefPredicates;

class Predicates : public Filterable {
  bool requiresPosition;
  bool hasFilter;

 public:
  Predicates(const XmlPLAST &o) : Filterable(o), requiresPosition(false), hasFilter(false) {}
  Predicates() : requiresPosition(false), hasFilter(false) {}
  virtual ~Predicates() {}

  virtual void setType(int type) {}
  virtual int getType() const {return PREDICATES;}

  virtual RefXmlPLAST getFilterChild() const {return hasFilter ? getChild() : 0;}
  virtual void setFilterChild(RefXmlPLAST child);

  RefXmlPLAST getFirstPredicate() const
  {return hasFilter ? getChild()->getNext() : getChild();}

  virtual void setRequiresPosition(const bool requiresPosition)
  {this->requiresPosition = requiresPosition;}
  virtual bool getRequiresPosition() const {return requiresPosition;}

  virtual void validateIncomingType(const unsigned int type);
  virtual void setTargetType(const TargetType &targetType, bool resetOk = false);
  virtual const bool isExpression() const {return false;}

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();
};
#endif // PREDICATES_H
