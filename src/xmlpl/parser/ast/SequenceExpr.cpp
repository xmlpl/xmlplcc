#include "SequenceExpr.h"
#include <xmlpl/parser/environment/Type.h>

#include <iostream>

using namespace antlr;
using namespace std;
using namespace xmlpl;

RefAST SequenceExpr::factory() {
  return RefAST(new SequenceExpr);
}

void SequenceExpr::setTargetType(const TargetType &targetType, bool resetOk) {
  XmlPLAST *child = getChild();

  unsigned int childTargetType = targetType.getFlags() | targetType.getType();

  while (child) {
    if (Type::isSequence(child->getDataType()))
      child->setTargetType(childTargetType, resetOk);
    else child->setTargetType(childTargetType & ~SEQUENCE_FLAG, resetOk);

    child = child->getNext();
  }
  
  if (targetType.getType() == BOOLEAN_TYPE)
    ; // Keep default data type
  else if (Type::isSequence(targetType.getType()))
    dataType = targetType.getType();
  else semanticError(string("cannot cast sequence expression to ") +
		     Type::get(targetType.getType()).getName());

  Expression::setTargetType(targetType, resetOk);
}

void SequenceExpr::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("sequence", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
