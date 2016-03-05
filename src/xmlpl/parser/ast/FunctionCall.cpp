#include "FunctionCall.h"

#include <xmlpl/parser/environment/Type.h>

#include <BasicUtils/BasicException.h>

using namespace antlr;

void FunctionCall::validate() {
  if (entry != 0) {    
    // Set argument target types
    const args_t fargs = entry->getArgs();
    args_t::const_iterator it;

    XmlPLAST *expr = getChild();
    for (it = fargs.begin(); it != fargs.end(); it++) {
      ASSERT_OR_THROW("Call argument count does not match definition!", expr);

      if (expr->isConstant() && it->byReference)
	expr->semanticError("cannot pass constant by reference");

      expr->setTargetType(it->type);
      expr = expr->getNext();
    }    
  }
}

void FunctionCall::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  attrs["name"] = getName().getFullName();
  attrs["type"] = xmlpl::Type::get(getDataType()).getName();

  addCommonAttributes(attrs);
  serializer.startElement("fcall", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
