#include "xmlplcc.h"

#include "Language.h"

#include "parser/XmlPLLexer.hpp"
#include "parser/XmlPLParser.hpp"
#include "ErrorHandler.h"
#include "parser/TargetType.h"
#include "parser/environment/Type.h"
#include "parser/environment/TypeTables.h"
#include "parser/environment/Environment.h"

#include <BasicUtils/BasicException.h>
#include <BasicUtils/BasicSmartPointer.h>
#include <BasicUtils/BasicSignalCatch.h>
#include <xmlpl/cpp/runtime/LibXML2XMLStream.h>
#include <xmlpl/cpp/runtime/XMLStream2SerializerAdapter.h>

using namespace std;
using namespace antlr;
using namespace xmlpl;

RefXmlPLAST parseXmlPL(istream &input, string filename) {
  XmlPLLexer lexer(input);

  try {
    try {
      BasicSignalCatch<SIGSEGV> sigSegCatch;
      
      if (Options::getInstance()->getDumpCore() || !SIGNALED(sigSegCatch)) {
        ASTFactory astFactory("XmlPLAST", XmlPLAST::factory);
  
        lexer.setFilename(filename);
        XmlPLParser parser(lexer);
        parser.setFilename(filename);
  
        parser.initializeASTFactory(astFactory);
        parser.setASTFactory(&astFactory);
  
        Environment *env = new Environment;
  
        // Declare built-in functions
        Options::getInstance()->getLanguage()->declareBuiltins(env);
  
        parser.program(env);

        return RefXmlPLAST(parser.getAST());

      } else throw BasicException("Fatal error during parse",
                                  BasicFileLocation(lexer.getFilename(),
                                                    lexer.getLine(),
                                                    lexer.getColumn()));

    } catch (const exception &e) {
      throw BasicException(e.what());

    } catch (const ANTLRException &e) {
      throw BasicException(e.toString());
    }

  } catch (const BasicException &e) {
    throw BasicException(e.getMessage(),
                         BasicFileLocation(lexer.getFilename(),
                                           lexer.getLine(), lexer.getColumn()),
                         e);
  }
}

RefXmlPLAST makeCast(RefXmlPLAST node, const unsigned int from,
										 const unsigned int to) {
  Cast *cast = new Cast;

  cast->setTargetType(to | node->getTargetType().getFlags());
  cast->setDataType(to);
  cast->setNextSibling(node->getNext());
  node->setNextSibling(0);
  cast->setFirstChild(&*node);

  return cast; 
}

RefXmlPLAST postprocessXmlPL(RefXmlPLAST tree, bool castOk) {
  if (tree == 0) return 0;

  // Recur
  RefXmlPLAST child = tree->getChild();

  if (child) {
    // Do not double cast expressions that have already been cast
    bool castOk = tree->getType() != XmlPLAST::CAST;

    child = postprocessXmlPL(child, castOk);
    tree->setFirstChild(&*child);
    RefXmlPLAST next = child->getNext();
    
    while (next) {
      next = postprocessXmlPL(next, castOk);
      child->setNextSibling(&*next);
      
      child = next;
      next = next->getNext();
    }
  }

  if (castOk && tree->isExpression()) {
    unsigned int from = tree->getDataType();
    unsigned int to = tree->getTargetType().getType();

    if (from != to) {
      // Don't cast self casting expressions
      if (tree->isSelfCasting()) return tree;

      if (tree->getTargetType().hasAppend()) {
        // Stop at string for node sequence appends
        if (Type::isNode(to) && from == Type::STRING_TYPE) return tree;
      }

      // Don't cast to void
      if (to == Type::VOID_TYPE) return tree;
      
      if (!TypeTables::lookupCastable(from, to)) {
        ErrorHandler::error("invalid cast from " + Type::get(from).getName() +
                            " to " + Type::get(to).getName(),
														tree->getLocation());
        return tree;
      }
      
      return makeCast(tree, from, to);
    }
  }

  return tree;
}

void outputXmlPLXML(RefXmlPLAST tree, ostream &output) {
	LibXML2XMLStream stream(output);
  XMLStream2SerializerAdapter serializer(&stream);

  serializer.startDocument();
  if (tree) tree->serializeXML(serializer);
  serializer.endDocument();
  output << endl;
}
