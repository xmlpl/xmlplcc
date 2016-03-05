#include "ForStmt.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST ForStmt::factory() {
  return RefAST(new ForStmt);
}

void ForStmt::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("for", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
