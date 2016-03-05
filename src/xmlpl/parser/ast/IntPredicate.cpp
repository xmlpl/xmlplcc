#include "IntPredicate.h"

using namespace antlr;

void IntPredicate::validateIncomingType(const unsigned int type) {
  Filterable::validateIncomingType(type);
  setDataType(type & ~SEQUENCE_FLAG);
}

void IntPredicate::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("int-predicate", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}

RefAST IntPredicate::factory() {return RefAST(new IntPredicate);}
