#include "FilterExpr.h"

using namespace antlr;

void FilterExpr::validate() {
  XmlPLAST *expr = getChild();
  setDataType(expr->getDataType());
}

void FilterExpr::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("filter", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}

RefAST FilterExpr::factory() {
  return RefAST(new FilterExpr);
}
