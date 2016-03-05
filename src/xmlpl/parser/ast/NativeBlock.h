#ifndef NATIVEBLOCK_H
#define NATIVEBLOCK_H

#include "XmlPLAST.h"

class NativeBlock;

typedef ANTLR_USE_NAMESPACE(antlr)ASTRefCount<NativeBlock> RefNativeBlock;

class NativeBlock : public XmlPLAST {
 public:
  NativeBlock(const NativeBlock &o) : XmlPLAST(o) {}
  NativeBlock(const XmlPLAST &o) : XmlPLAST(o) {}
  NativeBlock() {}
  virtual ~NativeBlock() {}

  virtual void setType(int type) {}
  virtual int getType() const {return NATIVE;}

  static ANTLR_USE_NAMESPACE(antlr)RefAST factory();

  virtual void serializeXML(XMLSerializer &serializer);
  virtual void visit(ASTVisitor *v) {v->visitAST(this);}
};
#endif // NATIVEBLOCK_H
