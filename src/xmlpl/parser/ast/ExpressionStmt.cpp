#include "ExpressionStmt.h"

#include <xmlpl/parser/environment/Type.h>

#include <iostream>

using namespace antlr;
using namespace std;
using namespace xmlpl;

RefAST ExpressionStmt::factory() {
  return RefAST(new ExpressionStmt);
}

const unsigned int ExpressionStmt::getDataType() const {
  XmlPLAST *child = getChild();
  return child->getDataType();
}

void ExpressionStmt::setTargetType(const TargetType &targetType, bool resetOk) {
  XmlPLAST *child = getChild();

  if (child) {
    if (child->getDataType() == VOID_TYPE) emitValue = false;
    if (!targetType.hasAppend()) emitValue = false;

    if (child->hasEffect()) {
      if (child->getType() != FCALL) emitValue = false;
    }

    if (emitValue) {
      TargetType childTargetType = targetType.clearFlags(STATEMENT_FLAGS);
      
      if (!Type::isSequence(child->getDataType()))
	  childTargetType = childTargetType.clearFlags(SEQUENCE_FLAG);

      child->setTargetType(childTargetType);

    } else child->setTargetType(VOID_TYPE);

  } else emitValue = false;

  this->targetType = targetType;
}

void ExpressionStmt::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  if (!getEmitValue())
    attrs["emit"] = "false";

  addCommonAttributes(attrs);
  serializer.startElement("exprstmt", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
