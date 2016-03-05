#include "NativeBlock.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST NativeBlock::factory() {
  return RefAST(new NativeBlock);
}

void NativeBlock::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  attrs["data"] = getText();

  addCommonAttributes(attrs);
  serializer.startElement("native", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
