#ifndef VERSIONRANGE_H
#define VERSIONRANGE_H

#include "XmlPLAST.h"

#include <xmlpl/cpp/runtime/Version.h>

class VersionRange;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<VersionRange> RefVersionRange;

class VersionRange : public XmlPLAST {
  xmlpl::Version version;
  xmlpl::Version max;
  int op;

 public:
  VersionRange(const VersionRange &o) :
    XmlPLAST(o), version(o.version), max(o.max), op(o.op) {}
  VersionRange(const XmlPLAST &o) : XmlPLAST(o), op(0) {}
  VersionRange() : op(0) {}
  virtual ~VersionRange() {}

  virtual void setType(int type) {}
  virtual int getType() const {return VERSION_RANGE;}

  virtual void setOp(int op) {this->op = op;}
  virtual int getOp() const {return op;}

  const void setVersion(const xmlpl::Version &version) {this->version = version;}
  const xmlpl::Version &getVersion() const {return version;}
  const xmlpl::Version &getMin() const {return version;}
  const void setMax(const xmlpl::Version &max) {this->max = max;}
  const xmlpl::Version &getMax() const {return max;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}

  // VersionExpression
  virtual bool matches(const xmlpl::Version &version) const;
};
#endif // VERSIONRANGE_H
