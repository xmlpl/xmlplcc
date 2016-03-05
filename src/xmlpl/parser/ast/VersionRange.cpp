#include "VersionRange.h"

#include <iostream>

using namespace antlr;
using namespace std;
using namespace xmlpl;

RefAST VersionRange::factory() {
  return RefAST(new VersionRange);
}

void VersionRange::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  switch (getOp()) {
  case GT:
    attrs["op"] = ">";
    attrs["version"] = version.toString();
    break;

  case GTE:
    attrs["op"] = ">=";
    attrs["version"] = version.toString();
    break;

  case LESS:
    attrs["op"] = "<";
    attrs["version"] = version.toString();
    break;

  case LTE:
    attrs["op"] = "<=";
    attrs["version"] = version.toString();
    break;

  case MINUS:
    attrs["min"] = version.toString();
    attrs["max"] = max.toString();
    break;

  default:
    attrs["version"] = version.toString();
    break;
  }

  addCommonAttributes(attrs);
  serializer.startElement("range", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}

bool VersionRange::matches(const Version &version) const {
  switch (getOp()) {
  case GT: return version > this->version;
  case GTE: return version >= this->version;
  case LESS: return version < this->version;
  case LTE: return version <= this->version;
  case MINUS: return this->version <= version && version <= max;
  default: return version == this->version;
  }
}
