#include "ForeachStmt.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST ForeachStmt::factory() {
  return RefAST(new ForeachStmt);
}

void ForeachStmt::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("foreach", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
