#include "Empty.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST Empty::factory() {
  return RefAST(new Empty);
}

void Empty::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("empty", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
