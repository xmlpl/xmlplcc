#include "ReturnStmt.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST ReturnStmt::factory() {
  return RefAST(new ReturnStmt);
}

void ReturnStmt::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("return", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
