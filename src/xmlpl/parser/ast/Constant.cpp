#include "Constant.h"
#include <xmlpl/parser/environment/Type.h>

using namespace antlr;

RefAST Constant::factory() {
  return RefAST(new Constant);
}

void Constant::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  attrs["value"] = getText();
  attrs["type"] = xmlpl::Type::get(getDataType()).getName();

  addCommonAttributes(attrs);
  serializer.startElement("const", attrs);
  serializer.endElement();
}
