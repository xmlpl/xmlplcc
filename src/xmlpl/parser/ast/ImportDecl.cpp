#include "ImportDecl.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST ImportDecl::factory() {
  return RefAST(new ImportDecl);
}

void ImportDecl::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  attrs["name"] = name.getFullRealName();
  if (name.hasPseudonym()) attrs["as"] = name.getFullName();

  addCommonAttributes(attrs);
  serializer.startElement("import", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
