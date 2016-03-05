#ifndef XMLPLCC_H
#define XMLPLCC_H

#include "parser/ast/XmlPLAST.h"
#include <iostream>

RefXmlPLAST parseXmlPL(std::istream &input, std::string filename);
RefXmlPLAST postprocessXmlPL(RefXmlPLAST tree, bool castOk = true);
void outputXmlPLXML(RefXmlPLAST tree, std::ostream &output);

#endif // XMLPLCC_H
