#ifndef PACKAGEDECL_H
#define PACKAGEDECL_H

#include "XmlPLAST.h"

class PackageDecl;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<PackageDecl> RefPackageDecl;

class PackageDecl : public XmlPLAST {
  std::string namespaceStr;
  xmlpl::Version version;  

 public:
  PackageDecl(const PackageDecl &o) : XmlPLAST(o), namespaceStr(o.namespaceStr),
				      version(o.version) {}
  PackageDecl(const XmlPLAST &o) : XmlPLAST(o) {}
  PackageDecl(const std::string &namespaceStr, const xmlpl::Version &version) :
    namespaceStr(namespaceStr), version(version) {}
  PackageDecl() {}
  virtual ~PackageDecl() {}

  virtual void setType(int type) {}
  virtual int getType() const {return PACKAGE_DECL;}

  const std::string &getNamespace() const {return namespaceStr;}
  const xmlpl::Version &getVersion() const {return version;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // PACKAGEDECL_H
