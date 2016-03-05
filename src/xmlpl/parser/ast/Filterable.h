#ifndef FILTERABLE_H
#define FILTERABLE_H

#include "Expression.h"

class Filterable : public Expression {
  unsigned int dataType;
  unsigned int incomingType;

 public:
  Filterable(const XmlPLAST &o) : Expression(o), dataType(UNKNOWN_TYPE),
				  incomingType(UNKNOWN_TYPE) {}
  Filterable() : dataType(UNKNOWN_TYPE), incomingType(UNKNOWN_TYPE) {}
  virtual ~Filterable() {}

  virtual RefXmlPLAST getFilterChild() const = 0;
  virtual void setFilterChild(RefXmlPLAST child) = 0;

  virtual void setDataType(const unsigned int dataType) {this->dataType = dataType;}
  virtual const unsigned int getLocalDataType() const {return dataType;}
  virtual const unsigned int getDataType() const;
  virtual void setTargetType(const TargetType &targetType, bool resetOk = false);

  virtual const bool isFilterable() const {return true;}
  virtual void filterWith(RefXmlPLAST ast);
  virtual void validateIncomingType(const unsigned int type);
  virtual unsigned int getIncomingType() const {return incomingType;}
};
#endif // FILTERABLE_H
