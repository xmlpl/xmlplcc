#include "ThrowStmt.h"
#include <xmlpl/parser/environment/Type.h>

#include <xmlpl/ErrorHandler.h>

#include <iostream>

using namespace antlr;
using namespace std;
using namespace xmlpl;

RefAST ThrowStmt::factory() {
  return RefAST(new ThrowStmt);
}

void ThrowStmt::validate() {
  const unsigned int type = getChild()->getDataType();
  
  if (!Type::canBe(type, STRING_TYPE))
    ErrorHandler::error("throw expression must result in a string!");

  getChild()->setTargetType(type);
}

void ThrowStmt::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("throw", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
