#include "WhileStmt.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST WhileStmt::factory() {
  return RefAST(new WhileStmt);
}

void WhileStmt::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("while", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
