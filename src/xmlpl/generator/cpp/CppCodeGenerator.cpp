#include "CppCodeGenerator.h"
#include "CppLanguage.h"

#include <xmlpl/Options.h>
#include <xmlpl/Utils.h>
#include <xmlpl/parser/TargetType.h>
#include <xmlpl/parser/environment/TypeTables.h>
#include <xmlpl/parser/environment/Type.h>
#include <xmlpl/cpp/runtime/LibraryInfo.h>

#include <BasicUtils/BasicException.h>
#include <BasicUtils/BasicString.h>

#include <stdio.h>

using namespace std;
using namespace xmlpl;

void CppCodeGenerator::genHeader() {
  string msg =
    "This file was automatically generated by the XmlPL compiler, xmlplcc";
  if (sourceFile != "")
    msg += ", from the source file '" + sourceFile + "'";

  msg += ". Editing this file directly is not recommended! ";
  msg += "Edit the XmlPL source instead. See http://xmlpl.org/ ";
  msg += "for more information about the XmlPL language.";

  printBoxComment(out, msg);
  out << endl;
}

void CppCodeGenerator::genStandalone(Program *program) {
  mainFunc = 0;

  // Children
  visitChildren(program);

  if (!mainFunc) throw BasicException("function main() not declared");

  // Namespace
  namespaceOff();

  out << TAB << "int main(int argc, char *argv[]) {" << endl;
  tabUp();

  if (Options::getInstance()->getDebugMode())
    out << TAB << "BasicDebugger::initStackTrace(argv[0]);" << endl;
  out << TAB << "xmlplInit();" << endl;
  out << endl;

  out << TAB << "try {" << endl;
  tabUp();


  EnvEntryRef mainEntry = mainFunc->getEntry();
  const args_t &mainArgs = mainEntry->getArgs();

  bool docArg = false;
  bool args = false;

  bool argsValid = true;
  args_t::const_iterator it = mainArgs.begin();
  if (mainArgs.size() > 2) argsValid = false;
  else if (mainArgs.size() == 1) {
    if (it->type == STRING_SEQ_TYPE) args = true;
    else if (it->type == DOCUMENT_TYPE) docArg = true;
    else argsValid = false;

  } else if (mainArgs.size() == 2) {
    if (it->type == DOCUMENT_TYPE) docArg = true;
    else argsValid = false;
    it++;
    if (it->type == STRING_SEQ_TYPE) args = true;
    else argsValid = false;
  }

  if (!argsValid)
    throwException(string("main function is only allowed one of the ") +
		   "following argument signatures:\n" +
		   "\tmain()\n" +
		   "\tmain(string[] args)\n" +
		   "\tmain(document in)\n" +
		   "\tmain(document in, string[] args)",
		   mainFunc);

  if (docArg) {
    out << TAB << "IStreamDataSource input(std::cin);" << endl;
    out << TAB << "LibXML2XMLSource source(&input, DOMFactory::getInstance());"
	<< endl;
    out << TAB << "DOMBuilder builder(*DOMFactory::getInstance(), source);"
	<< endl;
    out << endl;
  }

  if (args) {
    out << TAB << "StringSequence args;" << endl;
    out << TAB << "for (int i = 0; i < argc; i++)" << endl;
    tabUp();
    // TODO Resolve possible escape characters in args at run-time
    out << TAB << "args.append(String(argv[i]));" << endl;
    tabDown();
    out << endl;
  }

  string mainStr = getCPPNameStr("main");
  if (namespaceHash != "")
    mainStr = namespaceHash + "::" + mainStr;

  bool firstArg = true;
  if (mainEntry->getType() == NODE_SEQ_TYPE ||
      mainEntry->getType() == STRING_SEQ_TYPE) {
    out << TAB << "LibXML2XMLStream target(std::cout);" << endl << endl;

    out << TAB << mainStr << "(target";
    firstArg = false;

  } else if (mainEntry->getType() == INTEGER_TYPE) {
    out << TAB << "return ";
    out << mainStr << "(";

  } else
    throwException(string("main function must return either ") +
		   "node[], string[] or integer!", mainFunc);

  if (docArg) {
    if (firstArg) firstArg = false;
    else out << ", ";
    out << "builder.adoptRoot()";
  }

  if (args) {
    if (firstArg) firstArg = false;
    else out << ", ";
    out << "args";
  }
  out << ");" << endl << endl;

  if (Type::isSequence(mainEntry->getType()))
    out << TAB << "return 0;" << endl;

  tabDown();
  out << TAB << "} catch (const Exception &e) {" << endl;
  tabUp();
  out << TAB << "std::cerr << e << std::endl;" << endl;
  tabDown();
  out << TAB << "} catch (const BasicException &e) {" << endl;
  tabUp();
  out << TAB << "std::cerr << e << std::endl;" << endl;
  tabDown();
  out << TAB << "}" << endl << endl;
  out << TAB << "return 1;" << endl;

  tabDown();
  out << TAB << "}" << endl;
}

void CppCodeGenerator::genLibrary(Program *program) {
  XmlPLAST *child = program->getChild();
  if (child->getType() == PACKAGE_DECL) {
    child->visit(this);
    child = child->getNext();
  }

  // Namespace
  ASSERT_OR_THROW("Libraries require a namespace!", namespaceStr != "");

  out << "#define XMLPL_NS " << namespaceHash << endl;

  // Children
  for (; child; child = child->getNext())
    child->visit(this);

  // Namespace
  namespaceOff();

  // Get local symbols
  const vector<EnvEntryRef> &entries = program->getLocalSymbols();

  // Symbol table
  for (unsigned int i = 0; i < entries.size(); i++) {
    EnvEntryRef entry = entries[i];
    
    if (entry->getEntryType() == EnvEntry::FUNC_ENTRY) {
      unsigned int overloadCount = 0;

      while (entry != 0) {
	if (!entry->getArgs().empty()) {
	  
	  out << TAB << "const Symbol "
	      << getCPPNameStr(entry->getName().getName())
	      << "_args" << overloadCount << "[] = {" << endl;
	  tabUp();

	  args_t::const_iterator arg;
	  for (arg = entry->getArgs().begin();
	       arg != entry->getArgs().end();
	       arg++) {
	    out << TAB << "{"
		<< "Symbol::ARGUMENT"
		<< (arg->byReference ? " | Symbol::BYREFERENCE" : "") << ", "
		<< arg->type << ", "
		<< getCPPString(arg->name.getName()) << ", "
		<< "0}, " << endl;
	  }
	  
	  out << TAB << "{0, 0, 0, 0}" << endl;
	  tabDown();
	  out << "};" << endl;
	}

	overloadCount++;
	entry = entry->getNext();
      }
    }
  }

  out << endl;

  // Function Symbols
  out << TAB << "const Symbol symbolTable[] = {" << endl;
  tabUp();

  unsigned int tableSize = 0;
  for (unsigned int i = 0; i < entries.size(); i++) {
    EnvEntryRef entry = entries[i];
    
    switch (entry->getEntryType()) {
    case EnvEntry::FUNC_ENTRY: {
      unsigned int overloadCount = 0;
      while (entry != 0) {
	
	if (tableSize) out << "," << endl;
	out << TAB << "{"
	    << "Symbol::FUNCTION, "
	    << entry->getType() << ", "
	    << getCPPString(entry->getName().getName()) << ", ";

	if (!entry->getArgs().empty())
	  out << getCPPNameStr(entry->getName().getName()) << "_args" << overloadCount;
	else out << "0";
	out << "}";

	tableSize++;
	overloadCount++;
	entry = entry->getNext();
      }
      break;
    }

    case EnvEntry::VAR_ENTRY: {
      if (tableSize) out << "," << endl;
      out << TAB << "{"
	  << "Symbol::VARIABLE" << (entry->isConstant() ? " | Symbol::CONSTANT" : "") << ", "
	  << entry->getType() << ", "
	  << getCPPString(entry->getName().getName()) << ", "
	  << "0}";
      tableSize++;

      break;
    }
    }
  }
  out << endl;
  tabDown();
  out << TAB << "};" << endl << endl;

  out << TAB << "LibraryInfo " << LIBRARY_INFO_NAME << " = {" << endl;
  tabUp();
  out << TAB << getCPPString(namespaceStr) << "," << endl;
  out << TAB << getCPPString(namespaceHash) << "," << endl;
  out << TAB << "Version(" << version.getMajor() << ", " << version.getMinor()
      << ", " << version.getRevision() << ")," << endl;
  out << TAB << tableSize << "," << endl;
  out << TAB << "symbolTable" << endl;
  tabDown();
  out << TAB << "};" << endl;
}


void CppCodeGenerator::visitAST(Argument *argument) {
  out << getTypeName(argument->getDataType()) << " "
      << getCPPNameStr(argument->getArg().name.getName());
}

void CppCodeGenerator::visitAST(ArrayExpr *arrayExpr) {
  XmlPLAST *expr = arrayExpr->getChild();
  XmlPLAST *pred = expr->getNext();

  expr->visit(this);
  out << "[";
  pred->visit(this);
  out << "]";
}

void CppCodeGenerator::visitAST(Assignment *assignment) {
  XmlPLAST *left = assignment->getChild();
  XmlPLAST *right = left->getNext();

  if (assignment->getType() == COMMA_ASSIGN) {
    left->visit(this);
    out << ".add(";
    right->visit(this);
    out << ")";

  } else {
    left->visit(this);
    out << " " << assignment->getOp() << " ";
    
    if (right->getChild()) out << "(";
    right->visit(this);
    if (right->getChild()) out << ")";
  }
}

void CppCodeGenerator::visitAST(BinaryExpr *binaryExpr) {
  XmlPLAST *left = binaryExpr->getChild();
  XmlPLAST *right = left->getNext();

  bool realMod = false;
  if (left->getDataType() == REAL_TYPE &&
      right->getDataType() == REAL_TYPE &&
      binaryExpr->getType() == XmlPLAST::MOD) {
    out << "fmod(";
    realMod = true;
  }    

  if (left->getChild()) out << "(";
  left->visit(this);
  if (left->getChild()) out << ")";

  if (realMod) out << ", ";
  else out << " " << binaryExpr->getOp() << " ";

  if (right->getChild()) out << "(";
  right->visit(this);
  if (right->getChild()) out << ")";

  if (realMod) out << ")";
}

void CppCodeGenerator::visitAST(BlockStmt *blockStmt) {
  out << TAB << "{" << endl;
  tabUp();

  visitChildren(blockStmt);

  tabDown();
  out << TAB << "}" << endl << endl;
}

void CppCodeGenerator::visitAST(BreakStmt *breakStmt) {
  out << TAB << "break;" << endl;
}

inline void badCast(Cast *cast) {
  THROW(cast->getLocation().toString() + ": unsupported cast from " +
	Type::get(cast->getFrom()).getName() + " to " +
	Type::get(cast->getTo()).getName());
}

void CppCodeGenerator::visitAST(Cast *cast) {
  unsigned int to = cast->getTo();
  unsigned int from = cast->getFrom();

  if (cast->getChild()->isSelfCasting()) {
    visitChildren(cast);
    return;
  }

  if (Type::isSequence(from)) {

    if (Type::isSequence(to)) {
      if (cast->getTargetType().hasAppend()) {
	out << TAB << "TargetCast<" << getTypeName(from & ~SEQUENCE_FLAG) << ", "
	    << getTypeName(to & ~SEQUENCE_FLAG) << ", "
	    << "To" << getTypeCPPName(to & ~SEQUENCE_FLAG) << ">(target).append(";

	visitChildren(cast);
	out << ");" << endl;

      } else {
	out << "ToSequence<" << getTypeName(from & ~SEQUENCE_FLAG) << ", "
	    << getTypeName(to & ~SEQUENCE_FLAG) << ", "
	    << "To" << getTypeCPPName(to & ~SEQUENCE_FLAG) << ">::cast(";

	visitChildren(cast);
	out << ")";
      }

      return;
    }

    if (to == (from & ~SEQUENCE_FLAG)) {
      out << "(";
      visitChildren(cast);
      out << ").first()";

    } else switch (to) {
    case BOOLEAN_TYPE:
      visitChildren(cast);
      out << ".empty()";
      break;
      
    case VOID_TYPE:
      visitChildren(cast);
      break;
      
    default: badCast(cast);
    }
    
    return;
  }

  if (Type::isSequence(to)) {
    if (from == (to & ~SEQUENCE_FLAG)) {
      out << getTypeCPPName(to) << "(";
      visitChildren(cast);
      out << ")";

    } else if (from == NULL_TYPE) out << getTypeCPPName(to) << "()";
    else badCast(cast);
    return;
  }

  // Special append cases
  if (cast->getTargetType().hasAppend()) {
    switch (to) {
    case NODE_TYPE:
      if (Type::isNode(from)) {
	out << TAB << "target.append(ToNode::cast(";
	visitChildren(cast);
	out << "));" << endl;
	
      } else switch (from) {
      case STRING_TYPE:
	out << TAB << "target.text(";
	visitChildren(cast);
	out << ");" << endl;
	break;
	
      case PREFIX_TYPE:
      case QNAME_TYPE:
      case INTEGER_TYPE:
      case REAL_TYPE:
      case BOOLEAN_TYPE:
	out << TAB << "target.text(ToString::cast(";
	visitChildren(cast);
	out << "));" << endl;
	break;

      case NULL_TYPE: break;
      default: badCast(cast);
      }
      return;

    case TEXT_TYPE:
      switch (from) {
      case STRING_TYPE:
	out << TAB << "target.text(";
	visitChildren(cast);
	out << ");" << endl;
	break;
	
      case PREFIX_TYPE:
      case QNAME_TYPE:
      case INTEGER_TYPE:
      case REAL_TYPE:
      case BOOLEAN_TYPE:
	out << TAB << "target.text(ToString::cast(";
	visitChildren(cast);
	out << "));" << endl;
	break;
	
      case NULL_TYPE: break;
      default: badCast(cast);
      }
      return;
    }

    // Don't append null nodes
    if (from == NULL_TYPE && Type::isNode(to)) return;
  }

  if (from == NULL_TYPE) out << getTypeCPPName(to) << "Null()";
  else if (to == VOID_TYPE) visitChildren(cast);
  else {
    out << "To" << getTypeCPPName(to) << "::cast(";
    visitChildren(cast);
    out << ")";    
  }
}

void CppCodeGenerator::visitAST(CaseStmt *caseStmt) {
  XmlPLAST *caseConst = caseStmt->getChild();
  XmlPLAST *stmt = caseConst->getNext();

  if (caseConst->getDataType() == INTEGER_TYPE) {
    out << TAB << "case ";
    caseConst->visit(this);
    out << ":" << endl;

  } else if (caseConst->getDataType() == STRING_TYPE) {
    out << TAB << "// case " << getCPPString(caseConst->getText()) << ":" << endl;

    out << TAB << "if (!match && switchValue == ";
    caseConst->visit(this);
    out << ") match = true;" << endl;

    out << TAB << "if (match) {" << endl;

  } else {
    // TODO support Regex case
    THROW(string("Unsupported case type ") +
	  Type::get(caseConst->getDataType()).getName() + "!");
  }

  tabUp();
  while (stmt) {
    stmt->visit(this);
    stmt = stmt->getNext();
  }
  tabDown();

  if (caseConst->getDataType() == STRING_TYPE)
    out << TAB << "}" << endl;
}

void CppCodeGenerator::visitAST(Constant *constant) {
  const unsigned int type = constant->getDataType();

  if (type == BOOLEAN_TYPE) {
    out << constant->getText();

  } else if (type == NULL_TYPE) {
    THROW("Should have been handled in cast!");

  } else if (type == INTEGER_TYPE) {
    out << constant->getText();

  } else if (type == REAL_TYPE) {
    out << "(Real_t)" << constant->getText();

  } else if (type == STRING_TYPE) {
    out << "String(" << getCPPString(constant->getText()) << ")";

  } else THROW("Unrecognized type!");
}

void CppCodeGenerator::visitAST(ContinueStmt *continueStmt) {
  out << TAB << "continue;" << endl;
}

void CppCodeGenerator::visitAST(DefaultCase *defaultCase) {
  visitChildren(defaultCase);
}

void CppCodeGenerator::visitAST(Empty *empty) {
  out << TAB << ";" << endl;
}

void CppCodeGenerator::emitExpr(XmlPLAST *expr) {
  if (!expr->isSelfAppending()) out << TAB;

  if (expr->getTargetType().hasAppend() && !expr->isSelfAppending()) {
    unsigned int targetType = expr->getTargetType().getType();
    unsigned int type = expr->getDataType();

    if ((targetType == NODE_TYPE || targetType == TEXT_TYPE) && type == Type::STRING_TYPE)
      out << "target.text(";
    else out << "target.append(";
    
    expr->visit(this);
    out << ")";

  } else expr->visit(this);


  if (!expr->isSelfAppending()) out << ";" << endl;
}

void CppCodeGenerator::visitAST(ExpressionStmt *expressionStmt) {
  emitExpr(expressionStmt->getChild());
}

void CppCodeGenerator::visitAST(ForStmt *forStmt) {
  XmlPLAST *init = forStmt->getChild();
  XmlPLAST *cond = init->getNext();
  XmlPLAST *inc = cond->getNext();
  XmlPLAST *stmt = inc->getNext();

  out << TAB << "for (";
  if (init->getType() != EMPTY) init->visit(this);
  out << "; ";
  if (cond->getType() != EMPTY) cond->visit(this);
  out << "; ";  
  if (inc->getType() != EMPTY) inc->visit(this);
  out << ")";

  if (stmt->getType() != BLOCK && stmt->getChild()) out << " {";
  out << endl;
  tabUp();

  stmt->visit(this);

  tabDown();
  if (stmt->getType() != BLOCK && stmt->getChild()) out << TAB << "}" << endl;
}

void CppCodeGenerator::visitAST(FilterExpr *filterExpr) {
  if (functionize(filterExpr)) {

    XmlPLAST *expr = filterExpr->getChild();
    XmlPLAST *child = filterExpr->getFilterChild();

    out << TAB << "{" << endl;
    tabUp();
    
    out << TAB << getTypeName(expr->getDataType()) << " localContext = ";
    expr->visit(this);
    out << ";" << endl;
    
    out << TAB << "for (unsigned int i = 0; i < localContext.size(); i++) {"
	<< endl;
    tabUp();

    pushContext("localContext[i]");
    child->visit(this);
    popContext();
    
    tabDown();
    out << TAB << "}" << endl;
    tabDown();
    out << TAB << "}" << endl;
  }
}

void CppCodeGenerator::visitAST(ForeachStmt *foreachStmt) {
  XmlPLAST *expr = foreachStmt->getChild();
  XmlPLAST *stmt = expr->getNext();

  out << TAB << "{" << endl;
  tabUp();

  out << TAB << getTypeName(expr->getDataType()) << " context = ";
  expr->visit(this);
  out << ";" << endl;
  
  out << TAB << "for (unsigned int i = 0; i < context.size(); i++) {" << endl;
  tabUp();

  pushContext("context[i]");
  stmt->visit(this);
  popContext();

  tabDown();
  out << TAB << "}" << endl;

  tabDown();
  out << TAB << "}" << endl;
}

void CppCodeGenerator::visitAST(FunctionCall *functionCall) {
  EnvEntryRef entry = functionCall->getEnvEntry();

  if (entry->getBuiltinFunctor()) {
    // Call builtin function handler
    entry->getBuiltinFunctor()->call(this, functionCall);
    return;
  }

  TargetType targetType = functionCall->getTargetType();
  unsigned int returnType = functionCall->getDataType();
  bool hasTarget = Type::isSequence(returnType);
  bool ecall = !targetType.hasAppend() && hasTarget;

  if (functionCall->isSelfAppending()) out << TAB;

  out << getCPPName(functionCall->getName(), ecall ? "ECALL_" : "") << "(";

  bool firstArg = true;

  if (hasTarget && !ecall) {
    firstArg = false;

    unsigned int from = returnType;
    unsigned int to = targetType.getType();

    if (from == to) out << "target";
    else out << "*(new TargetCast<" << getTypeName(from & ~SEQUENCE_FLAG) << ", "
	     << getTypeName(to & ~SEQUENCE_FLAG) << ", "
	     << "To" << getTypeCPPName(to & ~SEQUENCE_FLAG) << ">(target))";
  }

  for (XmlPLAST *child = functionCall->getChild(); child; child = child->getNext()) {
    if (firstArg) firstArg = false;
    else out << ", ";
    child->visit(this);
  }

  out << ")";

  if (functionCall->isSelfAppending()) out << ";" << endl;
}

void CppCodeGenerator::funcDeclPreprocess(XmlPLAST *ast) {
  while (ast) {
    funcDeclPreprocess(ast->getChild());

    if (ast->functionize()) {
      functionizeMode = FUNCTIONIZE_DECL;
      ast->visit(this);
    }

    ast = ast->getNext();
  }

  functionizeMode = FUNCTIONIZE_CALL;
}

void CppCodeGenerator::genFuncDecl(EnvEntryRef entry, bool ecall) {
  bool hasTarget = Type::isSequence(entry->getType());

  // Return Type
  if (hasTarget && !ecall) out << "Void_t ";
  else {
    if (ecall) {
      //out << "inline ";
      if (hasTarget) out << "Temp";
    }
    out << getTypeName(entry->getType()) << " ";
  }

  // Name
  if (ecall) out << "ECALL_";
  out << getCPPName(entry->getName().getRealName()) << "(";

  // Args
  bool firstArg = true;

  // Target Arg
  if (hasTarget & !ecall) {
    out << getTargetName(entry->getType()) << " &target";
    firstArg = false;
  }

  // Remaining Args
  args_t::const_iterator it;
  for (it = entry->getArgs().begin(); it != entry->getArgs().end(); it++) {
    if (firstArg) firstArg = false;
    else out << ", ";
    
    out << getTypeName(it->type) << " ";
    if (it->byReference) out << "&";
    out << getCPPNameStr(it->name.getName());
  }

  out << ")";
}

void CppCodeGenerator::visitAST(FunctionDecl *functionDecl) {
  // Namespace
  namespaceOn();

  EnvEntryRef entry = functionDecl->getEntry();
  bool hasTarget = Type::isSequence(entry->getType());

  if (entry->getName().getName() == "main")
    mainFunc = functionDecl;

  if (!functionDecl->isForwardDecl())
    out << TAB << "// Begin Function " << entry->getName() << endl;

  // ForwardDecl
  out << TAB;
  genFuncDecl(entry);
  out << ";" << endl;

  if (functionDecl->isForwardDecl()) {
    // Also forward declare the ECALL
    if (hasTarget) {
      out << TAB;
      genFuncDecl(entry, true);
      out << ";" << endl;
    }
    return;
  }

  if (hasTarget) {
    // Expression call (aka ECALL)
    out << TAB;
    genFuncDecl(entry, true);
    out << " {" << endl;
    tabUp();
    
    // Temporary result variable
    out << TAB << "Temp" << getTypeCPPName(entry->getType())
	<< " result;" << endl;
    
    // Actual call
    out << TAB << getCPPName(entry->getName().getRealName()) << "(";

    // Arguments
    out << "result";

    const args_t &args = entry->getArgs();
    for (unsigned int i = 0; i < args.size(); i++)
      out << ", " << getCPPName(args[i].name.getName());

    out << ");" << endl;
    
    // Return
    out << TAB << "return result;" << endl;

    tabDown();
    out << TAB << "}" << endl;
  }

  // Find and output path expressions as functions
  funcDeclPreprocess(functionDecl->getChild());

  out << TAB;
  genFuncDecl(entry);

  out << " {" << endl;
  tabUp();
  
  // Skip BlockStmt itself and visit children
  XmlPLAST *block = functionDecl->getBlock();
  visitChildren(block);
  
  tabDown();
  out << TAB << "}" << endl;

  out << TAB << "// End Function " << entry->getName() << endl;
  out << endl;
}

void CppCodeGenerator::visitAST(IfStmt *ifStmt) {
  XmlPLAST *condition = ifStmt->getChild();
  XmlPLAST *ifBlock = condition->getNext();
  XmlPLAST *elseBlock = ifBlock->getNext();

  out << TAB << "if (";
  condition->visit(this);
  out << ")";

  if (ifBlock->getType() != BLOCK && ifBlock->getChild()) out << " {";
  out << endl;
  tabUp();

  ifBlock->visit(this);

  tabDown();
  if (ifBlock->getType() != BLOCK && ifBlock->getChild()) out << TAB << "}" << endl;

  if (elseBlock) {
    out << TAB << "else";
    if (elseBlock->getType() != BLOCK && elseBlock->getChild()) out << " {";
    out << endl;
    tabUp();

    elseBlock->visit(this);

    tabDown();
    if (elseBlock->getType() != BLOCK && elseBlock->getChild()) out << TAB << "}" << endl;
  }
}

void CppCodeGenerator::visitAST(ImportDecl *importDecl) {
  const vector<EnvEntryRef> &entries = importDecl->getEntries();
  if (entries.empty()) return;

  ASSERT_OR_THROW("Import must have namespace!", importDecl->getName().getNamespace());

  // Namespace
  namespaceOff();

  out << TAB << "namespace " << hashNamespace(importDecl->getName().getNamespace())
      << " {" << endl;
  tabUp();

  for (unsigned int i = 0; i < entries.size(); i++) {
    EnvEntryRef entry = entries[i];

    // Skip symbols that were never referenced.
    if (!entry->getEnvRefCount()) continue;

    switch (entry->getEntryType()) {
    case EnvEntry::VAR_ENTRY:
      out << TAB << "extern ";
      out << getTypeName(entry->getType()) << " ";
      out << getCPPNameStr(entry->getName().getRealName());
      break;

    case EnvEntry::FUNC_ENTRY:
      out << TAB << "extern ";
      genFuncDecl(entry, true);
      out << ";" << endl;

      out << TAB << "extern ";
      genFuncDecl(entry);
      break;
    }

    out << "; // referenced " << entry->getEnvRefCount() << " times" << endl;
  }  

  tabDown();
  out << TAB << "};" << endl;
}

void CppCodeGenerator::visitAST(IntPredicate *intPredicate) {
  XmlPLAST *child = intPredicate->getFilterChild();
  XmlPLAST *pred = intPredicate->getChild();

  out << TAB << "if (" << getCPPNameStr("position") << " == ";

  if (pred->getChild()) out << "(";
  pred->visit(this);
  if (pred->getChild()) out << ")";

  out << ") {" << endl;
  tabUp();

  if (child) child->visit(this);
  else emitContext(intPredicate->getTargetType(), intPredicate->getDataType());

  tabDown();
  out << TAB << "}" << endl;

  out << TAB << getCPPNameStr("position") << "++;" << endl;
}

void CppCodeGenerator::visitAST(NameTest *nameTest) {
  XmlPLAST *prefix = nameTest->getChild();

  out << "nameTest(" << getRawContext() << "->getName(), ";

  if (prefix) prefix->visit(this);
  else if (nameTest->getPrefix() == "*") out << "&Prefix::ANY";
  else if (nameTest->getPrefix() != "") THROW("Regex not yet supported!");
  else out << "&Prefix::ANY";

  out << ", " << getCPPString(nameTest->getName()) << ")";
}

void CppCodeGenerator::visitAST(NativeBlock *nativeBlock) {
  out << TAB << "// Begin Native Block" << endl;
  out << nativeBlock->getText();
  out << TAB << "// End Native Block" << endl;
}

void CppCodeGenerator::visitAST(PackageDecl *packageDecl) {
  if (packageDecl->getNamespace() != "") {
    namespaceStr = packageDecl->getNamespace();
    namespaceHash = hashNamespace(packageDecl->getNamespace());
  }
  version = packageDecl->getVersion();
}

void CppCodeGenerator::visitAST(PathExpr *pathExpr) {
  if (functionize(pathExpr)) {

    XmlPLAST *expr = pathExpr->getChild();
    XmlPLAST *child = pathExpr->getFilterChild();
    unsigned int dataType = expr->getDataType();

    out << TAB << "{" << endl;
    tabUp();

    out << TAB << getTypeName(expr->getDataType()) << " localContext = ";
    expr->visit(this);
    out << ";" << endl;

    if (Type::isSequence(dataType)) {
      out << TAB << "for (unsigned int i = 0; i < localContext.size(); i++) {" << endl;
      tabUp();  
    }

    out << TAB << getTypeCPPName(dataType & ~SEQUENCE_FLAG)
	<< " *c0 = localContext" << (Type::isSequence(dataType) ? "[i]" : "")
	<< ".drop();" << endl;
    
    out << TAB << "if (c0) {" << endl;
    tabUp();
    
    string cookedContext = getTypeName(dataType) + "((" +
      getTypeCPPName(dataType) + " *)c0)";
    pushContext(cookedContext, "c0");
    
    child->visit(this);
    
    popContext();
    
    tabDown();
    out << TAB << "}" << endl;
    
    if (Type::isSequence(dataType)) {
      tabDown();
      out << TAB << "}" << endl;
    }

    tabDown();
    out << TAB << "}" << endl;
  }
}

void CppCodeGenerator::visitAST(Predicates *predicates) {
  XmlPLAST *child = predicates->getFilterChild();
  XmlPLAST *pred = predicates->getFirstPredicate();

  out << TAB << "if (";

  bool first = true;
  while (pred) {
    if (first) first = false;
    else out << " && ";

    if (pred->getChild()) out << "(";
    pred->visit(this);
    if (pred->getChild()) out << ")";
    
    pred = pred->getNext();
  }

  out << ") {" << endl;
  tabUp();

  if (child) child->visit(this);
  else emitContext(predicates->getTargetType(), predicates->getDataType());

  tabDown();
  out << TAB << "}" << endl;
}

void CppCodeGenerator::visitAST(Program *program) {
  genHeader();

  out << "#include <xmlpl/cpp/runtime/xmlpl.h>" << endl;
  out << "using namespace xmlpl;" << endl;
  out << endl;

  if (Options::getInstance()->getBuildLibrary()) genLibrary(program);
  else genStandalone(program);

  // Namespace
  namespaceOff();
}

void CppCodeGenerator::visitAST(RedirectStmt *redirectStmt) {
  out << TAB << "{" << endl;
  tabUp();

  XmlPLAST *expr = redirectStmt->getChild();
  XmlPLAST *child = expr->getNext();

  out << TAB << getTargetName(expr->getDataType() & ~TypeID::OSTREAM_FLAG)
      << " &target = *(";
  expr->visit(this);
  out << ");" << endl << endl;

  child->visit(this);

  out << TAB << "target.flush();" << endl;

  tabDown();
  out << TAB << "}" << endl;  
}

void CppCodeGenerator::visitAST(ReturnStmt *returnStmt) {
  out << TAB << "return ";
  visitChildren(returnStmt);
  out << ";" << endl;
}

void CppCodeGenerator::visitAST(SequenceExpr *sequenceExpr) {
  XmlPLAST *child = sequenceExpr->getChild();

  if (sequenceExpr->getTargetType().hasAppend()) {
    while (child) {
      emitExpr(child);
      child = child->getNext();
    }

  } else {
    out << getTypeName(sequenceExpr->getDataType()) << "()";

    while (child) {
      out << ".add(";
      child->visit(this);
      out << ")";

      child = child->getNext();
    }
  }
}


void CppCodeGenerator::visitAST(Step *step) {
  XmlPLAST *nodeTest = step->getChild();
  XmlPLAST *child = step->getFilterChild();

  string parent = getRawContext();
  string context = string("c") + BasicString(contextStack.size());
  unsigned int incomingType = step->getIncomingType();
  unsigned int dataType = step->getLocalDataType();
  unsigned int contextType = dataType & ~SEQUENCE_FLAG;
  bool parentTypeTest = false;

  string cookedContext = getTypeName(contextType) + "((" + getTypeCPPName(contextType) +
    " *)" + context + ")";
  pushContext(cookedContext, context);

  switch (step->getAxis()) {
  case Step::CHILD_AXIS: {

    // Parent type test
    if (incomingType != ELEMENT_TYPE && incomingType != DOCUMENT_TYPE) {
      out << TAB << "if (" << parent << "->getType() == TypeID::ELEMENT_TYPE || "
	  << parent << "->getType() == TypeID::DOCUMENT_TYPE) {" << endl;
      tabUp();
      parentTypeTest = true;
    }

    // Position
    if (child && child->getRequiresPosition())
      out << TAB << "int " << getCPPNameStr("position") << " = 0;" << endl;

    // Child Axis
    out << TAB << "for (Node *" << context << " = " << parent << "->getFirstChild(); "
	<< context << "; " << context << " = " << context << "->getNext())" << endl;
    tabUp();

    // Node test
    ASSERT_OR_THROW("Child axis must have node test!", nodeTest);
    out << TAB << "if (";
    nodeTest->visit(this);
    out << ") {" << endl;
    tabUp();

    break;
  }

  case Step::ATTRIBUTE_AXIS: {
    // Parent type test
    if (incomingType != ELEMENT_TYPE) {
      out << TAB << "if (" << parent << "->getType() == TypeID::ELEMENT_TYPE) {" << endl;
      tabUp();
      parentTypeTest = true;
    }

    // Position
    if (child && child->getRequiresPosition())
      out << TAB << "int " << getCPPNameStr("position") << " = 0;" << endl;

    // Attribute Axis
    out << TAB << "for (Node *" << context << " = " << parent << "->getFirstAttribute(); "
	<< context << "; " << context << " = " << context << "->getNext())" << endl;
    tabUp();

    // Node test
    ASSERT_OR_THROW("Attribute axis must have node test!", nodeTest);
    out << TAB << "if (";
    nodeTest->visit(this);
    out << ") {" << endl;
    tabUp();

    break;
  }

  case Step::PARENT_AXIS: {
    // Parent type test
    if (incomingType != ELEMENT_TYPE) {
      out << TAB << "if (" << parent << "->getType() == TypeID::ELEMENT_TYPE) {" << endl;
      tabUp();
      parentTypeTest = true;
    }

    out << TAB << "Element *" << context << " = " << parent << "->getParent();" << endl;
    out << TAB << "if (" << context << ") {" << endl;
    tabUp();
    break;
  }

  default:
    THROW(string("Unsupported axis type: ") + BasicString(step->getAxis()));
  }


  if (child) child->visit(this);
  else emitContext(step->getTargetType(), dataType);


  switch (step->getAxis()) {
  case Step::CHILD_AXIS:
  case Step::ATTRIBUTE_AXIS: {
    // Node test
    tabDown();
    out << TAB << "}" << endl;

    // Axis
    tabDown();
    break;
  }

  case Step::PARENT_AXIS: {
    // Axis
    tabDown();
    out << TAB << "}";
    break;
  }

  default:
    THROW(string("Unsupported axis type: ") + BasicString(step->getAxis()));
  }

  // Parent type test
  if (parentTypeTest) {
    tabDown();
    out << TAB << "}" << endl;
  }

  popContext();
}

void CppCodeGenerator::visitAST(SwitchStmt *switchStmt) {
  const unsigned int type = switchStmt->getDataType();
  XmlPLAST *expr = switchStmt->getChild();
  XmlPLAST *caseStmt = expr->getNext();

  if (type == STRING_TYPE) {
    // TODO optimize string switch with a binary search to determine an
    //      integer case number then jump into a normal integer switch
    //      statment.

    out << TAB << "{ // switch(";
    expr->visit(this);
    out << ")" << endl;

    tabUp();
    
    out << TAB << "String switchValue = ";
    expr->visit(this);
    out << ";" << endl;
    out << TAB << "bool match = false;" << endl << endl;
    out << TAB << "while (true) {" << endl;
    tabUp();

  } else if (type == INTEGER_TYPE) {
    out << TAB << "switch (";
    expr->visit(this);
    out << ") {" << endl;
  }

  while (caseStmt) {
    if (caseStmt->getType() == CASE)
      caseStmt->visit(this);

    else { // Default case
      if (type == INTEGER_TYPE) {
	out << TAB << "default:" << endl;
	tabUp();

      } else out << TAB << "// default:" << endl;
      
      caseStmt->visit(this);

      if (type == INTEGER_TYPE) tabDown();
   }

    out << endl;
    caseStmt = caseStmt->getNext();
  }

  if (type == STRING_TYPE) {
    out << TAB << "break;" << endl;
    tabDown();
    out << TAB << "}" << endl;
    tabDown();
    out << TAB << "}" << endl;
    
  } else
    if (type == INTEGER_TYPE) 
      out << TAB << "}" << endl;
}

void CppCodeGenerator::visitAST(ThrowStmt *throwStmt) {
  out << TAB << "throw Exception(";
  throwStmt->getChild()->visit(this);
  out << ", " << throwStmt->getLocation().line
      << ", " << throwStmt->getLocation().column
      << ");" << endl;
}

void CppCodeGenerator::visitAST(TryStmt *tryStmt) {
  XmlPLAST *tryBlock = tryStmt->getChild();
  XmlPLAST *catchBlock = tryBlock->getNext();

  out << TAB << "try ";
  tryBlock->visit(this);
  out << TAB << "catch (const Exception &e) {" << endl;
  tabUp();

  out << TAB << getTypeName(STRING_TYPE) << " "
      << getCPPNameStr("error") << " = e.getMessage();" << endl;
  out << TAB << getTypeName(INTEGER_TYPE) << " "
      << getCPPNameStr("line") << " = e.getLine();" << endl;
  out << TAB << getTypeName(INTEGER_TYPE) << " "
      << getCPPNameStr("column") << " = e.getColumn();" << endl;

  out << TAB;
  catchBlock->visit(this);
  tabDown();
  out << TAB << "}" << endl;
}

void CppCodeGenerator::visitAST(TypeTest *typeTest) {
  const unsigned int type = typeTest->getTypeTest();
  if (type == NODE_TYPE) out << "true";
  else if (type) out << getRawContext() << "->getType() == "
		     << Type::get(type).getIDString();
}

void CppCodeGenerator::visitAST(UnaryExpr *unaryExpr) {
  XmlPLAST *child = unaryExpr->getChild();

  if (!unaryExpr->getPost())
    out << unaryExpr->getOp();

  if (child->getChild()) out << "(";
  unaryExpr->getChild()->visit(this);
  if (child->getChild()) out << ")";

  if (unaryExpr->getPost())
    out << unaryExpr->getOp();  
}

void CppCodeGenerator::visitAST(VariableDecl *variableDecl) {
  // Namespace
  namespaceOn();

  XmlPLAST *child = variableDecl->getChild();
  EnvEntryRef entry = variableDecl->getEntry();

  out << TAB << getTypeName(entry->getType()) << " " << getCPPName(entry->getName());

  if (child) {
    out << " = ";
    child->visit(this);

  } else if (Type::isSequence(entry->getType())) {
  } else if (Type::isOStream(entry->getType())) {
    out << " = 0";
  } else {
    out << " = " << getTypeCPPName(entry->getType()) << "Null()";
  }

  out << ";" << endl;
}

void CppCodeGenerator::visitAST(VariableRef *variableRef) {
  if (variableRef->getName().getName() == ".") out << getContext();
  else out << getCPPName(variableRef->getName());

  if (variableRef->getRelease()) out << ".adopt()";
}

void CppCodeGenerator::visitAST(WhileStmt *whileStmt) {
  XmlPLAST *condition = whileStmt->getChild();
  XmlPLAST *whileBlock = condition->getNext();

  out << TAB << "while (";
  condition->visit(this);
  out << ")";

  if (whileBlock->getType() != BLOCK && whileBlock->getChild()) out << " {";
  out << endl;
  tabUp();

  whileBlock->visit(this);

  tabDown();
  if (whileBlock->getType() != BLOCK && whileBlock->getChild()) out << TAB << "}" << endl;
}

void CppCodeGenerator::visitAST(XMLAttr *xmlAttr) {
  XmlPLAST *qname = xmlAttr->getChild();
  XmlPLAST *value = qname->getNext();

  if (xmlAttr->getTargetType().hasAppend())
    out << TAB << "target.attribute(";
  else out << "createAttribute(";

  qname->visit(this);
  out << ", ";
  value->visit(this);
  out << ")";

  if (xmlAttr->getTargetType().hasAppend())
    out << ";" << endl;
}

void CppCodeGenerator::visitAST(XMLComment *xmlComment) {
  XmlPLAST *child = xmlComment->getChild();

  if (xmlComment->getTargetType().hasAppend())
    out << TAB << "target.comment(";
  else out << "CommentRef(createComment(";

  if (!child) out << "\"\"";
  else if (!child->getNext()) child->visit(this);
  else {
    unsigned int count = 0;
    while (child) {
      count++;
      child = child->getNext();
    }
    child = xmlComment->getChild();

    out << "String::concat(" << count;
    while (child) {
      out << ", ";
      child->visit(this);
      out << ".get()";
      child = child->getNext();
    }

    out << ")";
  }
  
  out << ")";

  if (xmlComment->getTargetType().hasAppend())
    out << ";" << endl;
  else out << ")";
}

void CppCodeGenerator::visitAST(XMLElement *xmlElement) {
  if (functionize(xmlElement)) {
    XmlPLAST *qname = xmlElement->getChild();
    XmlPLAST *child = qname->getNext();

    out << TAB << "target.startElement(";
    qname->visit(this);
    out << ");" << endl;
    
    if (child) {
      out << TAB << "{" << endl;
      tabUp();
      
      out << TAB << "NodeTarget &tmp = target.getChildTarget();"
	  << endl;
      out << TAB << "NodeTarget &target = tmp;" << endl;
      
      while (child) {
	child->visit(this);
	child = child->getNext();
      }
      
      tabDown();
      out << TAB << "}" << endl;
    }
    out << TAB << "target.endElement();" << endl;    
  }
}

void CppCodeGenerator::visitAST(XMLPI *xmlPI) {
  XmlPLAST *target = xmlPI->getChild();
  XmlPLAST *child = target->getNext();

  if (xmlPI->getTargetType().hasAppend())
    out << TAB << "target.pi(";
  else out << "PIRef(createPI(";

  target->visit(this);
  out << ", ";

  if (!child) out << "\"\"";
  else if (!child->getNext()) child->visit(this);
  else {
    unsigned int count = 0;
    while (child) {
      count++;
      child = child->getNext();
    }
    child = target->getNext();
    
    out << "String::concat(" << count;
    while (child) {
      out << ", ";
      child->visit(this);
      out << ".get()";
      child = child->getNext();
    }

    out << ")";
  }
  
  out << ")";

  if (xmlPI->getTargetType().hasAppend())
    out << ";" << endl;
  else out << ")";
}

void CppCodeGenerator::visitAST(XMLQName *xmlQName) {
  XmlPLAST *child1 = xmlQName->getChild();
  XmlPLAST *child2 = child1->getNext();

  if (child2) {
    out << "createQName(";
    child1->visit(this);
    out << ", ";
    child2->visit(this);
    out << ")";

  } else child1->visit(this);
}