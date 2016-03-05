#include "XMLComment.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST XMLComment::factory() {
  return RefAST(new XMLComment);
}

void XMLComment::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("comment", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
