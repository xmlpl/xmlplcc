#ifndef VERSIONOR_H
#define VERSIONOR_H

#include "XmlPLAST.h"

class VersionOr;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<VersionOr> RefVersionOr;

class VersionOr : public XmlPLAST {
 public:
  VersionOr(const VersionOr &o) : XmlPLAST(o) {}
  VersionOr(const XmlPLAST &o) : XmlPLAST(o) {}
  VersionOr() {}
  virtual ~VersionOr() {}

  virtual void setType(int type) {}
  virtual int getType() const {return VERSION_OR;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}

  // VersionExpression
  virtual bool matches(const xmlpl::Version &version) const;
};
#endif // VERSIONOR_H
