#include "IfStmt.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST IfStmt::factory() {
  return RefAST(new IfStmt);
}

void IfStmt::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("if", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
