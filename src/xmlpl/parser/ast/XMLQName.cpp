#include "XMLQName.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST XMLQName::factory() {
  return RefAST(new XMLQName);
}

void XMLQName::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  if (getPrefix() != "") attrs["prefix"] = getPrefix();
  if (getName() != "") attrs["name"] = getName();

  addCommonAttributes(attrs);
  serializer.startElement("qname", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
