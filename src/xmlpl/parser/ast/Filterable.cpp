#include "Filterable.h"

using namespace antlr;

void Filterable::filterWith(RefXmlPLAST ast) {
  XmlPLAST *child = getFilterChild();

  if (child) child->filterWith(ast);
  else {
    setFilterChild(ast);

    ASSERT_OR_THROW("filterWith called, but data type not set!",
		    dataType != UNKNOWN_TYPE);
    if (ast->isFilterable()) ast->validateIncomingType(dataType);
  }
}

void Filterable::validateIncomingType(const unsigned int type) {
  incomingType = type;
}

const unsigned int Filterable::getDataType() const {
  XmlPLAST *child = getFilterChild();

  if (child && child->isFilterable()) return child->getDataType();
  return dataType;
}

void Filterable::setTargetType(const TargetType &targetType, bool resetOk) {
  XmlPLAST *child = getFilterChild();

  if (child && child->isFilterable()) child->setTargetType(targetType, resetOk);
  Expression::setTargetType(targetType, resetOk);
}
