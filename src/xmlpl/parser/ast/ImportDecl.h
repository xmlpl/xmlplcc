#ifndef IMPORTDECL_H
#define IMPORTDECL_H

#include "XmlPLAST.h"
#include <xmlpl/parser/environment/Name.h>
#include <xmlpl/parser/environment/EnvEntry.h>

#include <vector>

class ImportDecl;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<ImportDecl> RefImportDecl;

class ImportDecl : public XmlPLAST {
  Name name;
  std::vector<EnvEntryRef> entries;

 public:
  ImportDecl(const ImportDecl &o) : XmlPLAST(o), name(o.name) {}
  ImportDecl(const XmlPLAST &o) : XmlPLAST(o) {}
  ImportDecl() {}
  virtual ~ImportDecl() {}

  virtual void setType(int type) {}
  virtual int getType() const {return IMPORT_DECL;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  void setName(const Name &name) {this->name = name;}
  const Name &getName() const {return name;}

  void setEntries(const std::vector<EnvEntryRef> &entries) {this->entries = entries;}
  const std::vector<EnvEntryRef> &getEntries() const {return entries;}

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // IMPORTDECL_H
