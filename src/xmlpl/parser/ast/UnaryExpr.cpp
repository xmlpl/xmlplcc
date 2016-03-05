#include "UnaryExpr.h"
#include <xmlpl/parser/environment/Type.h>

#include <BasicUtils/BasicException.h>
#include <BasicUtils/BasicString.h>

using namespace antlr;
using namespace std;
using namespace xmlpl;

const bool UnaryExpr::hasEffect() const {
  switch (getType()) {
  case INC:
  case DEC:
    return true;

  default:
    return false;
  }
}

void UnaryExpr::validate() {
  XmlPLAST *operand = getChild();
  ASSERT_OR_THROW("Operand cannot be null!", operand);

  const unsigned int type = operand->getDataType();
  unsigned int targetType = UNKNOWN_TYPE;
  dataType = type;

  switch (getType()) {
  case NOT:
    targetType = BOOLEAN_TYPE;
    dataType = BOOLEAN_TYPE;
    break;

  case INC:
    if (Type::isIterator(type)) {
      targetType = type;
      break;
    }

  case DEC:
    if (type == INTEGER_TYPE) targetType = INTEGER_TYPE;
    break;

  case MINUS:
  case PLUS:
    if (type == INTEGER_TYPE || type == REAL_TYPE) targetType = type;
    break;

  case BCOMP:
    if (Type::canBe(type, INTEGER_TYPE)) targetType = INTEGER_TYPE;
    dataType = INTEGER_TYPE;
    break;
    
  default:
    THROW(string("Encountered unrecognized unary expression type: ") +
	  BasicString(getType()) + "!");
  }

  if (!targetType)
    semanticError(string("invalid operand of type `") + Type::get(type).getName() +
		  "' to unary operator " + getOp());

  operand->setTargetType(targetType);
}

void UnaryExpr::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  attrs["op"] = getText();
  if (getPost()) attrs["post"] = "true";

  addCommonAttributes(attrs);
  serializer.startElement("unaryexpr", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}


RefAST UnaryExpr::factory() {
  return RefAST(new UnaryExpr);
}
