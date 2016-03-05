#ifndef XmlPLAST_H
#define XmlPLAST_H

#include <list>
#include <set>

#include <antlr/CommonAST.hpp>
#include <antlr/SemanticException.hpp>

#include <xmlpl/cpp/runtime/XMLSerializer.h>

#include <xmlpl/Location.h>
#include <xmlpl/parser/XmlPLLexerTokenTypes.hpp>
#include <xmlpl/parser/TargetType.h>
#include <xmlpl/parser/environment/VersionExpression.h>

#include <BasicUtils/BasicException.h>

#include "ASTVisitor.h"

// Bad Bad Bad
using namespace xmlpl;

class XmlPLAST;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<XmlPLAST> RefXmlPLAST;

class XmlPLAST : public ANTLR_USE_NAMESPACE(antlr)CommonAST,
		 public VersionExpression,
		 public XmlPLLexerTokenTypes, public TargetTypeFlags {
  Location location;
  
 public:
  XmlPLAST(const XmlPLAST &other) :
    CommonAST(other), location(other.location) {}
  XmlPLAST() {}

  virtual ~XmlPLAST() {}

  virtual const Location &getLocation() const {
    if (location.line == 0 && getFirstChild())
      return RefXmlPLAST(getFirstChild())->getLocation();
    return location;
  }

  virtual void setLocation(const Location &location)
    {this->location = location;}

  virtual void semanticError(const std::string &msg) const;
  virtual void semanticWarning(const std::string &msg) const;

  virtual void initialize(int t, const ANTLR_USE_NAMESPACE(std)string &txt) {
    CommonAST::initialize(t, txt);
  }

  virtual void initialize(ANTLR_USE_NAMESPACE(antlr)RefToken t) {
    CommonAST::initialize(t);
    location = Location(t->getLine(), t->getColumn());
  }

  virtual void initialize(RefXmlPLAST ast) {
    CommonAST::initialize(ANTLR_USE_NAMESPACE(antlr)RefAST(ast));
    location = ast->getLocation();
  }

  // provide a clone of the node (no sibling/child pointers are copied)
  virtual ANTLR_USE_NAMESPACE(antlr)RefAST clone(void) {
    return ANTLR_USE_NAMESPACE(antlr)RefAST(new XmlPLAST(*this));
  }

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory(void) {
    return ANTLR_USE_NAMESPACE(antlr)RefAST(RefXmlPLAST(new XmlPLAST()));
  }
  
  XmlPLAST *getChild() const {
    if (!getFirstChild()) return 0;
    else return (XmlPLAST *)getFirstChild().get();
  }

  XmlPLAST *getNext() const {
    if (!getNextSibling()) return 0;
    else return (XmlPLAST *)getNextSibling().get();
  }

  // XMLCereal routines
  virtual void addCommonAttributes(XMLSerializer::attributes_t &attrs);
  virtual void serializeChildren(XMLSerializer &serializer);
  virtual void serializeXML(XMLSerializer &serializer);

  // TODO implement these functions in AST nodes.
  //virtual const bool isDeclaration() const {return false;}
  //virtual const bool isStatement() const {return false;}
  virtual const bool isExpression() const {return false;}
  virtual const bool isXML() const {return false;}
  virtual const bool hasEffect() const {return false;}
  virtual const bool isSelfAppending() const {return false;}
  virtual const bool isSelfCasting() const
    {return getTargetType().hasAppend() && isSelfAppending();}
  virtual const bool isConstant() const {return true;}

  virtual const bool isFilterable() const {return false;}
  virtual void filterWith(RefXmlPLAST ast);
  virtual void validateIncomingType(const unsigned int type);
  virtual void setFunctionize(const bool);
  virtual bool functionize() {return false;}
  virtual bool getRequiresPosition() const {return false;}

  virtual void setEnvDepth(const unsigned int envDepth);
  virtual unsigned int getEnvDepth() const;

  virtual const unsigned int getDataType() const;
  virtual void setTargetType(const TargetType &targetType,
			     bool resetOk = false);
  virtual bool isTargetTypeSet() const;
  virtual const TargetType getTargetType() const;
  virtual void validate() {}

  virtual void visit(ASTVisitor *v) {THROW("Not Supported");}

  // VersionExpression
  virtual bool matches(const xmlpl::Version &version) const;
};

#endif // XmlPLAST_H
