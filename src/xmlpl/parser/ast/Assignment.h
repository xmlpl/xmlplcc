#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "Expression.h"

class Assignment;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<Assignment> RefAssignment;

class Assignment : public Expression {
 public:
  Assignment(const Assignment &o) : Expression(o) {}
  Assignment(const XmlPLAST &o) : Expression(o) {}
  Assignment() {}
  virtual ~Assignment() {}

  const unsigned int getDataType() const;

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  int convertAssignOp(int op) const;

  const std::string getOp() const {return getText();}

  virtual const bool hasEffect() const {return true;}

  virtual void validate();
  virtual void validateTypes(const unsigned int type1, const unsigned int type2) const;

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // ASSIGNMENT_H
