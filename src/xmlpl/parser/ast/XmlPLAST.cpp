#include "XmlPLAST.h"

#include <BasicUtils/BasicException.h>

#include <xmlpl/ErrorHandler.h>
#include <xmlpl/Options.h>

using namespace antlr;
using namespace std;

const unsigned int XmlPLAST::getDataType() const {
  THROW("Not an expression!");
}

bool XmlPLAST::isTargetTypeSet() const {
  THROW("Not an expression!");
}

void XmlPLAST::setTargetType(const TargetType &targetType, bool resetOk) {
  THROW("Not an expression!");
}

const TargetType XmlPLAST::getTargetType() const {
  THROW("Not an expression!");
}

void XmlPLAST::filterWith(RefXmlPLAST ast) {
  THROW("AST Node does not support filterWith()!");
}

void XmlPLAST::validateIncomingType(const unsigned int type) {
  THROW("AST Node does not support validateIncomingType()!");
}

void XmlPLAST::setEnvDepth(const unsigned int envDepth) {
  THROW("AST Node does not support setEnvDepth()!");
}

void XmlPLAST::setFunctionize(const bool) {
  THROW("AST Node does not support setFunctionize()!");
}

unsigned int XmlPLAST::getEnvDepth() const {
  THROW("AST Node does not support getEnvDepth()!");
}

void XmlPLAST::semanticError(const std::string &msg) const {
  ErrorHandler::error(msg, getLocation());
}

void XmlPLAST::semanticWarning(const std::string &msg) const {
  ErrorHandler::warning(msg, getLocation());
}

void XmlPLAST::addCommonAttributes(XMLSerializer::attributes_t &attrs) {
  if (xmlpl::Options::getInstance()->getUseLineInfo()) {
    Location location = getLocation();

    if (location.line) {
      attrs["line"] = String(location.line);
      if (location.column) attrs["column"] = String(location.column);
    }
  }

  /*if (isExpression()) {
    attrs["target_type"] = get(getTargetType()).getName();
    attrs["data_type"] = get(getDataType()).getName();
    }*/
}

void XmlPLAST::serializeChildren(XMLSerializer &serializer) {
  if (getNumberOfChildren()) {
    RefXmlPLAST child(getFirstChild());
    
    while (child) {
      child->serializeXML(serializer);
      child = RefXmlPLAST(child->getNextSibling());
    }
  }
}

void XmlPLAST::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  attrs["text"] = getText();
  attrs["type"] = getType();

  addCommonAttributes(attrs);
  serializer.startElement("ast", attrs);

  serializeChildren(serializer);
  serializer.endElement();
}

bool XmlPLAST::matches(const xmlpl::Version &version) const {
  THROW("AST Node does not support VersionExpression::matches()!");
}
