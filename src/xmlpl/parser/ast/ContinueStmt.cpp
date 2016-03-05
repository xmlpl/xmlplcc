#include "ContinueStmt.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST ContinueStmt::factory() {
  return RefAST(new ContinueStmt);
}

void ContinueStmt::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("continue", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
