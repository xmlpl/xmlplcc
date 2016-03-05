#include "ArrayExpr.h"

#include <xmlpl/parser/environment/Type.h>

using namespace antlr;
using namespace xmlpl;

RefAST ArrayExpr::factory() {
  return RefAST(new ArrayExpr);
}

void ArrayExpr::validate() {
  XmlPLAST *child = getChild();
  if (child) {
    if (!Type::isSequence(child->getDataType()))
      semanticError("array expression invalid for non-sequence type");

    dataType = child->getDataType() & ~SEQUENCE_FLAG;
  }
}

void ArrayExpr::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("array", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
