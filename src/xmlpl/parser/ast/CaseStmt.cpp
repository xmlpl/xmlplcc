#include "CaseStmt.h"
#include <xmlpl/parser/environment/Type.h>

#include <iostream>

using namespace antlr;
using namespace std;
using namespace xmlpl;

const unsigned int CaseStmt::getDataType() const {
  XmlPLAST *child = getChild();

  if (!child) return UNKNOWN_TYPE;

  if (child->getDataType() == INTEGER_TYPE)
    return INTEGER_TYPE;

  if (Type::canBe(child->getDataType(), STRING_TYPE))
    return STRING_TYPE;

  return UNKNOWN_TYPE;
}

RefAST CaseStmt::factory() {
  return RefAST(new CaseStmt);
}

void CaseStmt::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("case", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
