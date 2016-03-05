#include "BinaryExpr.h"

#include <xmlpl/parser/environment/Type.h>
#include <xmlpl/parser/environment/TypeTables.h>

#include <BasicUtils/BasicException.h>
#include <BasicUtils/BasicString.h>

#include <iostream>

using namespace antlr;
using namespace std;
using namespace xmlpl;

RefAST BinaryExpr::factory() {
  return RefAST(new BinaryExpr);
}

void BinaryExpr::validate() {
  XmlPLAST *left = getChild();
  ASSERT_OR_THROW("Left operand cannot be null!", left);
  XmlPLAST *right = left->getNext();
  ASSERT_OR_THROW("Right operand cannot be null!", right);

  const unsigned int targetType =
    validate(left->getDataType(), right->getDataType());

  left->setTargetType(targetType);
  right->setTargetType(targetType);
}

unsigned int BinaryExpr::validate(const unsigned int leftType,
				  const unsigned int rightType) {
  unsigned int targetType = UNKNOWN_TYPE;

  // Validate types
  switch (getType()) {
  case OR:
  case AND:
    if (leftType != VOID_TYPE && rightType != VOID_TYPE)
      targetType = BOOLEAN_TYPE;
    dataType = BOOLEAN_TYPE;
    break;

  case NE:
  case EQ:
    targetType = TypeTables::lookupEquality(leftType, rightType);
    dataType = BOOLEAN_TYPE;
    break;

  case LESS:
  case GT:
  case LTE:
  case GTE:
    targetType = TypeTables::lookupComparison(leftType, rightType);
    dataType = BOOLEAN_TYPE;
    break;

  case BOR:
  case BXOR:
  case BAND:
  case BSL:
  case BSR:
    targetType = TypeTables::lookupBit(leftType, rightType);
    dataType = INTEGER_TYPE;
    break;
    
  case PLUS:
    dataType = targetType = TypeTables::lookupPlus(leftType, rightType);
    break;

  case MINUS:
  case STAR:
  case FS:
  case MOD:
    dataType = targetType = TypeTables::lookupArithmetic(leftType, rightType);
    break;

  default:
    THROW(string("Encountered unrecognized binary expression type: ") +
	  BasicString(getType()) + "!");
  }  

  if (!targetType || !dataType)
    semanticError(string("invalid operands of types `") +
		  Type::get(leftType).getName() +
		  "' and `" + Type::get(rightType).getName() +
		  "' to binary operator " + getOp());

  return targetType;
}

std::string BinaryExpr::getOp() const {
  switch (getType()) {
  case OR: return "||";
  case AND: return "&&";
  case NE: return "!=";
  case EQ: return "==";
  case LESS: return "<";
  case GT: return ">";
  case LTE: return "<=";
  case GTE: return ">=";
  case BOR: return "|";
  case BXOR: return "^";
  case BAND: return "&";
  case BSL: return "<<";
  case BSR: return ">>";
  case PLUS: return "+";
  case MINUS: return "-";
  case STAR: return "*";
  case FS: return "/";
  case MOD: return "%";

  default:
    THROW(string("Encountered unrecognized binary expression type: ") +
	  BasicString(getType()) + "!");
  }  
}

void BinaryExpr::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  attrs["op"] = getOp();
  addCommonAttributes(attrs);
  serializer.startElement("binexpr", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
