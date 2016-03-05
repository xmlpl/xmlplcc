#include "DefaultCase.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST DefaultCase::factory() {
  return RefAST(new DefaultCase);
}

void DefaultCase::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("default", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
