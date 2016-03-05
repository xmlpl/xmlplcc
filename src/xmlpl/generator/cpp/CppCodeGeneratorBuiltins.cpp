#include "CppCodeGenerator.h"

#include <xmlpl/parser/environment/Environment.h>
#include <xmlpl/parser/environment/Type.h>

#include <BasicUtils/BasicException.h>

using namespace xmlpl;
using namespace std;

void CppCodeGenerator::sequenceSizeBuiltin(FunctionCall *functionCall) {
  XmlPLAST *child = functionCall->getChild();
  
  out << "(int)";
  child->visit(this);
  out << ".size()";
}

void CppCodeGenerator::sequenceResizeBuiltin(FunctionCall *functionCall) {
  XmlPLAST *seq = functionCall->getChild();
  XmlPLAST *expr = seq->getNext();
  
  seq->visit(this);
  out << ".resize(";
  expr->visit(this);
  out << ")";
}

void CppCodeGenerator::stringLengthBuiltin(FunctionCall *functionCall) {
  XmlPLAST *child = functionCall->getChild();
  
  out << "(int)";
  child->visit(this);
  out << ".length()";
}

void CppCodeGenerator::prefixBuiltin(FunctionCall *functionCall) {
  XmlPLAST *arg1 = functionCall->getChild();
  XmlPLAST *arg2 = arg1->getNext();

  out << "createPrefix(";
  arg1->visit(this);
  out << ", ";
  arg2->visit(this);
  out << ")";
}

void CppCodeGenerator::qnameBuiltin1(FunctionCall *functionCall) {
  XmlPLAST *arg1 = functionCall->getChild();
  XmlPLAST *arg2 = arg1->getNext();

  out << "createQName(";
  arg1->visit(this);
  out << ", ";
  arg2->visit(this);
  out << ")";
}

void CppCodeGenerator::qnameBuiltin2(FunctionCall *functionCall) {
  XmlPLAST *arg1 = functionCall->getChild();

  out << "createQName(&Prefix::EMPTY, ";
  arg1->visit(this);
  out << ")";
}

#define BUILTIN1(n, t, a1, f) {\
  const unsigned int args[] = {a1};\
  env->declareBuiltin(n, t, args_t(args, args + 1),\
                      new BuiltinFunctor<CppCodeGenerator>(&CppCodeGenerator::f));\
}

#define BUILTIN2(n, t, a1, a2, f) {\
  const unsigned int args[] = {a1, a2};\
  env->declareBuiltin(n, t, args_t(args, args + 2),\
                      new BuiltinFunctor<CppCodeGenerator>(&CppCodeGenerator::f));\
}

void CppCodeGenerator::declareBuiltins(Environment *env) {
  // Sequence size functions
  for (unsigned int i = 0; Type::types[i]; i++)
    if (Type::isSequence(Type::types[i])) {
      BUILTIN1("size", INTEGER_TYPE, Type::types[i], sequenceSizeBuiltin);
      BUILTIN2("resize", VOID_TYPE, Type::types[i], INTEGER_TYPE, sequenceResizeBuiltin);
    }

  // String length builtin
  BUILTIN1("length", INTEGER_TYPE, STRING_TYPE, stringLengthBuiltin);

  // Constructor builtins
  BUILTIN2("Prefix", PREFIX_TYPE, STRING_TYPE, STRING_TYPE, prefixBuiltin);
  BUILTIN2("QName", QNAME_TYPE, PREFIX_TYPE, STRING_TYPE, qnameBuiltin1);
  BUILTIN1("QName", QNAME_TYPE, STRING_TYPE, qnameBuiltin2);
}
