#include "SwitchStmt.h"
#include <xmlpl/parser/environment/Type.h>

#include <xmlpl/ErrorHandler.h>

#include <iostream>
#include <stdlib.h>

using namespace antlr;
using namespace std;
using namespace xmlpl;

const unsigned int SwitchStmt::getDataType() const {
  XmlPLAST *child = getChild();

  if (!child) return UNKNOWN_TYPE;

  if (child->getDataType() == INTEGER_TYPE)
    return INTEGER_TYPE;

  if (Type::canBe(child->getDataType(), STRING_TYPE))
    return STRING_TYPE;

  return UNKNOWN_TYPE;
}

RefAST SwitchStmt::factory() {
  return RefAST(new SwitchStmt);
}

extern "C" int caseCompare(const XmlPLAST **c1, const XmlPLAST **c2) {
  return (*c1)->getText().compare((*c2)->getText());
}

void SwitchStmt::validate() {
  const unsigned int type = getDataType();

  if (type == UNKNOWN_TYPE) {
    semanticError(string("invalid switch data type, must be ") +
		  Type::get(INTEGER_TYPE).getName() + " or " +
		  Type::get(STRING_TYPE).getName() + "!");
    return;
  }

  XmlPLAST *child = getChild();
  child->setTargetType(type);


  child = child->getNext();

  if (!child) semanticWarning("switch statment has no cases!");

  int numCases = 0;
  while (child) {
    if (child->getType() == CASE) {
      numCases++;

      if (child->getDataType() != type)
	child->semanticError(string("case of type ") +
			     Type::get(child->getDataType()).getName() +
			     " does not match switch of type " +
			     Type::get(type).getName() + "!");
   
    } else if (!child->getChild())
      child->semanticError("default case cannot be empty!");
    
    child = child->getNext();
  }

  // Check for duplicate cases
  if (numCases > 1) {
    // Create array
    XmlPLAST **cases = new XmlPLAST *[numCases];
    child = getChild()->getNext();

    // Fill with case constants
    for (int i = 0; i < numCases; i++) {
      cases[i] = child->getChild();
      child = child->getNext();
    }

    // Sort array
    qsort(cases, numCases, sizeof(XmlPLAST *),
	  (int (*)(const void *, const void *))caseCompare);
    

    // Look for duplicates
    for (int i = 0; i < numCases - 1; i++)
      if (cases[i]->getText() == cases[i + 1]->getText())
	cases[i]->semanticError(string("case is duplicated at ") +
				cases[i + 1]->getLocation().toString());

    delete[] cases;
  }
}

void SwitchStmt::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("switch", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
