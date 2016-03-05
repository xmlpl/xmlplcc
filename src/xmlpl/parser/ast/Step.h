#ifndef STEP_H
#define STEP_H

#include "Filterable.h"

class Step;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<Step> RefStep;

class Step : public Filterable {
public:
  typedef enum {
    UNKNOWN_AXIS,

    // Reverse Axes
    ANCESTOR_AXIS,
    ANCESTOR_OR_SELF_AXIS,
    PARENT_AXIS,
    PRECEDING_AXIS,
    PRECEDING_SIBLING_AXIS,

    // Forward Axes
    ATTRIBUTE_AXIS,
    CHILD_AXIS,
    DESCENDANT_AXIS,
    DESCENDANT_OR_SELF_AXIS,
    FOLLOWING_AXIS,
    FOLLOWING_SIBLING_AXIS,
    SELF_AXIS
  } axis_t;

private:
  axis_t axis;

public:
  Step(const XmlPLAST &o) : Filterable(o), axis(UNKNOWN_AXIS) {}
  Step() : axis(UNKNOWN_AXIS) {}
  virtual ~Step() {}

  virtual void setType(int type) {}
  virtual int getType() const {return STEP;}

  axis_t getAxis() const {return axis;}
  void setAxis(axis_t axis) {this->axis = axis;}

  virtual RefXmlPLAST getFilterChild() const {return getChild()->getNext();}
  virtual void setFilterChild(RefXmlPLAST child) {getChild()->setNextSibling(&*child);}

  virtual void validateIncomingType(const unsigned int type);
  virtual const bool isExpression() const {return false;}

  virtual void validate();
  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

protected:
  static unsigned int getTestType(XmlPLAST *test);
  static const char *getAxisName(axis_t axis);
};
#endif // STEP_H
