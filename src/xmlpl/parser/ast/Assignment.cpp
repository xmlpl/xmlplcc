#include "Assignment.h"
#include "BinaryExpr.h"
#include "VariableRef.h"
#include <xmlpl/parser/environment/Type.h>
#include <xmlpl/parser/environment/TypeTables.h>

#include <iostream>

using namespace antlr;
using namespace std;
using namespace xmlpl;

const unsigned int Assignment::getDataType() const {
  RefXmlPLAST exp1 = RefXmlPLAST(getFirstChild());
  return exp1->getDataType();
}

RefAST Assignment::factory() {
  return RefAST(new Assignment);
}

int Assignment::convertAssignOp(int op) const {
  switch (op) {
  case ADD_ASSIGN: return PLUS;
  case SUB_ASSIGN: return MINUS;
  case MUL_ASSIGN: return STAR;
  case DIV_ASSIGN: return FS;
  case MOD_ASSIGN: return MOD;
  case COMMA_ASSIGN: return COMMA;
  default: THROW("Unrecognized assign op!");
  }
}

void Assignment::validate() {
  XmlPLAST *exp1 = getChild();
  XmlPLAST *exp2 = exp1->getNext();

  if (exp1->isConstant()) semanticError("cannot assign to constant");
  else validateTypes(exp1->getDataType(), exp2->getDataType());

  if (getType() != ASSIGN && getType() != COMMA_ASSIGN) {
    RefBinaryExpr be =  new BinaryExpr;
    be->setLocation(getLocation());
    be->setType(convertAssignOp(getType()));
    be->setText(getText().substr(0, getText().length() - 1));
    
    be->validate(exp1->getDataType(), exp2->getDataType());

    exp2->setTargetType(exp1->getDataType());

  } else if (getType() == COMMA_ASSIGN) {
    unsigned int from = exp2->getDataType();
    unsigned int to = exp1->getDataType();

    if (!Type::isSequence(to))
      semanticError("cannot append to non-sequence");

    if (from != to && !TypeTables::lookupCastable(from, to))
      semanticError(string("cannot append ") + Type::get(from).getName() + " to " +
		    Type::get(to).getName());

    if (Type::isSequence(from)) exp2->setTargetType(to);
    else exp2->setTargetType(to & ~SEQUENCE_FLAG);

  } else if (getType() == ASSIGN) exp2->setTargetType(exp1->getDataType());
}

void Assignment::validateTypes(const unsigned int type1, const unsigned int type2) const {
  if (!Type::canBe(type2, type1))
    semanticError(string("cannot not assign ") + Type::get(type1).getName() +
		  " variable to " + Type::get(type2).getName() + " value");
}

void Assignment::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  attrs["op"] = getOp();

  addCommonAttributes(attrs);
  serializer.startElement("assignment", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
