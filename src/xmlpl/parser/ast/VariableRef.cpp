#include "VariableRef.h"
#include <xmlpl/parser/environment/Type.h>

using namespace antlr;

RefAST VariableRef::factory() {
  return RefAST(new VariableRef);
}

void VariableRef::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  attrs["name"] = getName().getFullName();
  attrs["type"] = String(xmlpl::Type::get(getDataType()).getName(), true);
  attrs["release"] = release ? "true" : "false";

  addCommonAttributes(attrs);
  serializer.startElement("varref", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
