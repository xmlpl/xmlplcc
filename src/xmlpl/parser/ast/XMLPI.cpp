#include "XMLPI.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST XMLPI::factory() {
  return RefAST(new XMLPI);
}

void XMLPI::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("pi", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
