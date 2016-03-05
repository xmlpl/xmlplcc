#include "VariableDecl.h"
#include <xmlpl/parser/environment/Type.h>

#include <iostream>

using namespace antlr;
using namespace std;
using namespace xmlpl;

RefAST VariableDecl::factory() {
  return RefAST(new VariableDecl);
}

void VariableDecl::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  attrs["name"] = entry->getName().getName();
  attrs["type"] = Type::get(entry->getType()).getName();

  addCommonAttributes(attrs);
  serializer.startElement("vardecl", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
