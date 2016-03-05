#include "XMLElement.h"

#include <iostream>

using namespace antlr;
using namespace std;

void XMLElement::validate() {
  // Set attributes to append
  for (XmlPLAST *attr = getChild(); attr; attr = attr->getNext())
    if (attr->getType() == XML_ATTR)
      attr->setTargetType(APPEND_FLAG | ATTRIBUTE_TYPE);
}

void XMLElement::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("elem", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}

RefAST XMLElement::factory() {
  return RefAST(new XMLElement);
}
