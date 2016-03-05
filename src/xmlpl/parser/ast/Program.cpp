#include "Program.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST Program::factory() {
  return RefAST(new Program);
}

void Program::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("program", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
