#include "Cast.h"

#include <xmlpl/parser/environment/Type.h>
#include <xmlpl/parser/environment/TypeTables.h>

#include <BasicUtils/BasicException.h>

#include <iostream>

using namespace antlr;
using namespace std;
using namespace xmlpl;

RefAST Cast::factory() {
  return RefAST(new Cast);
}

void Cast::validate() {
  if (!TypeTables::lookupCastable(getFrom(), getTo()))
    semanticError("invalid cast from " + Type::get(getFrom()).getName() +
		  " to " + Type::get(getTo()).getName());

  getChild()->setTargetType(dataType, true);
}

void Cast::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  ASSERT_OR_THROW("Cast must have child!", getChild());

  attrs["from"] = String(Type::get(getFrom()).getName(), true);
  attrs["to"] = String(Type::get(getTo()).getName(), true);

  addCommonAttributes(attrs);
  serializer.startElement("cast", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
