#include "Argument.h"
#include <xmlpl/parser/environment/Type.h>

using namespace antlr;
using namespace xmlpl;

void Argument::validate() {
  if (arg.type == Type::VOID_TYPE)
    semanticError("Argument type cannot be void!");
}

void Argument::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  attrs["name"] = arg.name.getName();
  attrs["type"] = Type::get(arg.type).getName();

  addCommonAttributes(attrs);
  serializer.startElement("arg", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}

RefAST Argument::factory() {
  return RefAST(new Argument);
}
