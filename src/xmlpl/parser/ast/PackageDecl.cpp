#include "PackageDecl.h"

#include <iostream>

using namespace antlr;
using namespace std;

RefAST PackageDecl::factory() {
  return RefAST(new PackageDecl);
}

void PackageDecl::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  attrs["namespace"] = getNamespace();
  attrs["version"] = getVersion().toString();

  addCommonAttributes(attrs);
  serializer.startElement("package", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}
