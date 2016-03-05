#include "FunctionDecl.h"
#include <xmlpl/parser/environment/Type.h>

#include <iostream>

using namespace antlr;
using namespace std;
using namespace xmlpl;

RefXmlPLAST FunctionDecl::getBlock() const {
  for (XmlPLAST *child = getChild(); child; child = child->getNext())
    if (child->getType() == BLOCK) return child;

  return 0;
}

void FunctionDecl::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  attrs["name"] = entry->getName().getName();
  attrs["type"] = Type::get(entry->getType()).getName();

  addCommonAttributes(attrs);
  serializer.startElement("funcdecl", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}

RefAST FunctionDecl::factory() {return RefAST(new FunctionDecl);}
