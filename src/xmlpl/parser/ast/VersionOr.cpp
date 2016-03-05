#include "VersionOr.h"

#include <iostream>

using namespace antlr;
using namespace std;
using namespace xmlpl;

RefAST VersionOr::factory() {
  return RefAST(new VersionOr);
}

void VersionOr::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("or", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}

bool VersionOr::matches(const Version &version) const {
  XmlPLAST *exp1 = getChild();
  if (exp1) {
    if (exp1->matches(version)) return true;

    XmlPLAST *exp2 = exp1->getNext();
    if (exp2->matches(version)) return true;
  }

  return false;
}
