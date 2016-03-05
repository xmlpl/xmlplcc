#include "TypeTest.h"
#include <xmlpl/parser/environment/Type.h>

#include <BasicUtils/BasicException.h>

#include <iostream>

using namespace antlr;
using namespace std;
using namespace xmlpl;

RefAST TypeTest::factory() {
  return RefAST(new TypeTest);
}

void TypeTest::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  attrs["type"] = Type::get(getTypeTest()).getName();

  addCommonAttributes(attrs);
  serializer.startElement("typetest", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
