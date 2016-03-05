#include "Predicates.h"

using namespace antlr;

void Predicates::setFilterChild(RefXmlPLAST child) {
  hasFilter = true;
  child->setNextSibling(getChild());
  setFirstChild(&*child);
}

void Predicates::validateIncomingType(const unsigned int type) {
  Filterable::validateIncomingType(type);
  setDataType(type);
}

void Predicates::setTargetType(const TargetType &targetType, bool resetOk) {
  Filterable::setTargetType(targetType, resetOk);

  for (XmlPLAST *pred = getFirstPredicate(); pred; pred = pred->getNext())
    pred->setTargetType(BOOLEAN_TYPE);
}

void Predicates::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  addCommonAttributes(attrs);
  serializer.startElement("predicates", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}

RefAST Predicates::factory() {return RefAST(new Predicates);}
