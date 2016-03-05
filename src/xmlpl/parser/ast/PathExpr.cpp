#include "PathExpr.h"

using namespace antlr;

void PathExpr::validate() {
  XmlPLAST *expr = getChild();
  setDataType(expr->getDataType());
}

void PathExpr::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("path", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}

RefAST PathExpr::factory() {
  return RefAST(new PathExpr);
}
