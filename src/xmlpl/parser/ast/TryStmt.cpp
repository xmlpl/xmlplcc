#include "TryStmt.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST TryStmt::factory() {
  return RefAST(new TryStmt);
}

void TryStmt::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("try", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
