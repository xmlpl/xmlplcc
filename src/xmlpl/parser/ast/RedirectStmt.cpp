#include "RedirectStmt.h"

#include <xmlpl/parser/environment/Type.h>

using namespace antlr;
using namespace xmlpl;

RefAST RedirectStmt::factory() {
  return RefAST(new RedirectStmt);
}

void RedirectStmt::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  attrs["type"] = Type::get(getDataType()).getName();

  addCommonAttributes(attrs);
  serializer.startElement("redirect", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
