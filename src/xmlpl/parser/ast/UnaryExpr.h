#ifndef UNARYEXPR_H
#define UNARYEXPR_H

#include "Expression.h"

class UnaryExpr;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<UnaryExpr> RefUnaryExpr;

class UnaryExpr : public Expression {
  bool post;
  unsigned int dataType;

 public:
  UnaryExpr(const XmlPLAST &o) : Expression(o), post(false), dataType(UNKNOWN_TYPE) {}
  UnaryExpr() : post(false), dataType(UNKNOWN_TYPE) {}
  virtual ~UnaryExpr() {}

  virtual const unsigned int getDataType() const {return dataType;}

  const std::string getOp() const {return getText();}
  void setPost(const bool post) {this->post = post;}
  bool getPost() const {return post;}

  virtual const bool hasEffect() const;

  virtual void validate();
  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();
};
#endif // UNARYEXPR_H
