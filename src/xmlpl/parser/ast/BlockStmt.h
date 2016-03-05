#ifndef BLOCKSTMT_H
#define BLOCKSTMT_H

#include "XmlPLAST.h"

class BlockStmt;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<BlockStmt> RefBlockStmt;

class BlockStmt : public XmlPLAST {
 public:
  BlockStmt(const BlockStmt &o) : XmlPLAST(o) {}
  BlockStmt(const XmlPLAST &o) : XmlPLAST(o) {}
  BlockStmt() {}
  virtual ~BlockStmt() {}

  virtual void setType(int type) {}
  virtual int getType() const {return BLOCK;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}

  // C++ generation routines
};
#endif // BLOCKSTMT_H
