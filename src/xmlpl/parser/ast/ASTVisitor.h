#ifndef ASTVISITOR_H
#define ASTVISITOR_H

#include <BasicUtils/BasicException.h>

class Argument;
class ArrayExpr;
class Assignment;
class BinaryExpr;
class BlockStmt;
class BreakStmt;
class CaseStmt;
class Cast;
class Constant;
class ContinueStmt;
class DefaultCase;
class Empty;
class ExpressionStmt;
class FilterExpr;
class ForeachStmt;
class ForStmt;
class FunctionCall;
class FunctionDecl;
class IfStmt;
class ImportDecl;
class IntPredicate;
class NameTest;
class NativeBlock;
class PackageDecl;
class PathExpr;
class Predicates;
class Program;
class RedirectStmt;
class ReturnStmt;
class SequenceExpr;
class Step;
class SwitchStmt;
class ThrowStmt;
class TryStmt;
class TypeTest;
class UnaryExpr;
class VariableDecl;
class VariableRef;
class VersionOr;
class VersionRange;
class WhileStmt;
class XMLAttr;
class XMLComment;
class XMLElement;
class XMLPI;
class XMLQName;

class ASTVisitor {
public:
  virtual ~ASTVisitor() {}
  virtual void visitAST(Argument *) {THROW("Not Supported!");}
  virtual void visitAST(ArrayExpr *) {THROW("Not Supported!");}
  virtual void visitAST(Assignment *) {THROW("Not Supported!");}
  virtual void visitAST(BinaryExpr *) {THROW("Not Supported!");}
  virtual void visitAST(BlockStmt *) {THROW("Not Supported!");}
  virtual void visitAST(BreakStmt *) {THROW("Not Supported!");}
  virtual void visitAST(CaseStmt *) {THROW("Not Supported!");}
  virtual void visitAST(Cast *) {THROW("Not Supported!");}
  virtual void visitAST(Constant *) {THROW("Not Supported!");}
  virtual void visitAST(ContinueStmt *) {THROW("Not Supported!");}
  virtual void visitAST(DefaultCase *) {THROW("Not Supported!");}
  virtual void visitAST(Empty *) {THROW("Not Supported!");}
  virtual void visitAST(ExpressionStmt *) {THROW("Not Supported!");}
  virtual void visitAST(FilterExpr *) {THROW("Not Supported!");}
  virtual void visitAST(ForeachStmt *) {THROW("Not Supported!");}
  virtual void visitAST(ForStmt *) {THROW("Not Supported!");}
  virtual void visitAST(FunctionCall *) {THROW("Not Supported!");}
  virtual void visitAST(FunctionDecl *) {THROW("Not Supported!");}
  virtual void visitAST(IfStmt *) {THROW("Not Supported!");}
  virtual void visitAST(ImportDecl *) {THROW("Not Supported!");}
  virtual void visitAST(IntPredicate *) {THROW("Not Supported!");}
  virtual void visitAST(NameTest *) {THROW("Not Supported!");}
  virtual void visitAST(NativeBlock *) {THROW("Not Supported!");}
  virtual void visitAST(PackageDecl *) {THROW("Not Supported!");}
  virtual void visitAST(PathExpr *) {THROW("Not Supported!");}
  virtual void visitAST(Predicates *) {THROW("Not Supported!");}
  virtual void visitAST(Program *) {THROW("Not Supported!");}
  virtual void visitAST(RedirectStmt *) {THROW("Not Supported!");}
  virtual void visitAST(ReturnStmt *) {THROW("Not Supported!");}
  virtual void visitAST(SequenceExpr *) {THROW("Not Supported!");}
  virtual void visitAST(Step *) {THROW("Not Supported!");}
  virtual void visitAST(SwitchStmt *) {THROW("Not Supported!");}
  virtual void visitAST(ThrowStmt *) {THROW("Not Supported!");}
  virtual void visitAST(TryStmt *) {THROW("Not Supported!");}
  virtual void visitAST(TypeTest *) {THROW("Not Supported!");}
  virtual void visitAST(UnaryExpr *) {THROW("Not Supported!");}
  virtual void visitAST(VariableDecl *) {THROW("Not Supported!");}
  virtual void visitAST(VariableRef *) {THROW("Not Supported!");}
  virtual void visitAST(VersionOr *) {THROW("Not Supported!");}
  virtual void visitAST(VersionRange *) {THROW("Not Supported!");}
  virtual void visitAST(WhileStmt *) {THROW("Not Supported!");}
  virtual void visitAST(XMLAttr *) {THROW("Not Supported!");}
  virtual void visitAST(XMLComment *) {THROW("Not Supported!");}
  virtual void visitAST(XMLElement *) {THROW("Not Supported!");}
  virtual void visitAST(XMLPI *) {THROW("Not Supported!");}
  virtual void visitAST(XMLQName *) {THROW("Not Supported!");}
};
#endif // ASTVISITOR_H
