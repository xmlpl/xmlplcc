#include "NodeTest.h"

#include <BasicUtils/BasicException.h>

#include <iostream>

using namespace antlr;
using namespace std;

RefAST NodeTest::factory() {
  return RefAST(new NodeTest);
}

void NodeTest::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  attrs["name"] = getName();
  attrs["type"] = getTypeTest()->getName();

  addCommonAttributes(attrs);
  serializer.startElement("test", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
