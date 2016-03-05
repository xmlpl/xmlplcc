#include "XMLAttr.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST XMLAttr::factory() {
  return RefAST(new XMLAttr);
}

void XMLAttr::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("attr", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
