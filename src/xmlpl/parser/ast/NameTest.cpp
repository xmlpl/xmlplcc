#include "NameTest.h"

#include <BasicUtils/BasicException.h>

#include <iostream>

using namespace antlr;
using namespace std;

RefAST NameTest::factory() {
  return RefAST(new NameTest);
}

void NameTest::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  if (getPrefix() != "") attrs["name"] = getPrefix() + ":" + getName();
  else attrs["name"] = getName();

  addCommonAttributes(attrs);
  serializer.startElement("nametest", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
