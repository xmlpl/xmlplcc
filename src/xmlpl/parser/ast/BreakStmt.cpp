#include "BreakStmt.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST BreakStmt::factory() {
  return RefAST(new BreakStmt);
}

void BreakStmt::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("break", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
