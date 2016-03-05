#ifndef EXPRESSIONSTMT_H
#define EXPRESSIONSTMT_H

#include "XmlPLAST.h"

class ExpressionStmt;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<ExpressionStmt> RefExpressionStmt;

class ExpressionStmt : public XmlPLAST {
  TargetType targetType;
  bool emitValue;

 public:
  ExpressionStmt(const ExpressionStmt &o) : XmlPLAST(o), emitValue(o.emitValue) {}
  ExpressionStmt(const XmlPLAST &o) : XmlPLAST(o), emitValue(true) {}
  ExpressionStmt() : emitValue(true) {}
  virtual ~ExpressionStmt() {}

  virtual void setType(int type) {}
  virtual int getType() const {return EXPR_STMT;}

  virtual const unsigned int getDataType() const;
  void setEmitValue(const bool emitValue) {this->emitValue = emitValue;}
  bool getEmitValue() const {return emitValue;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void setTargetType(const TargetType &targetType, bool resetOk = false);
  virtual const TargetType getTargetType() const {return targetType;}
  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // EXPRESSIONSTMT_H
