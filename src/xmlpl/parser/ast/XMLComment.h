#ifndef XMLCOMMENT_H
#define XMLCOMMENT_H

#include "Expression.h"

class XMLComment;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<XMLComment> RefXMLComment;

class XMLComment : public Expression {
 public:
  XMLComment(const XMLComment &o) : Expression(o) {}
  XMLComment(const XmlPLAST &o) : Expression(o) {}
  XMLComment() {}
  virtual ~XMLComment() {}

  virtual void setType(int type) {}
  virtual int getType() const {return XML_COM;}

  virtual const unsigned int getDataType() const {return COMMENT_TYPE;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();
  virtual const bool isXML() const {return true;}
  virtual const bool isSelfAppending() const {return getTargetType().hasAppend();}

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // XMLCOMMENT_H
