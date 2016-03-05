#include "BlockStmt.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST BlockStmt::factory() {
  return RefAST(new BlockStmt);
}

void BlockStmt::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("block", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
