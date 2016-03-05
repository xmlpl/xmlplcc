#include "Step.h"

#include "TypeTest.h"

#include <BasicUtils/BasicException.h>

using namespace antlr;

void Step::validateIncomingType(const unsigned int type) {
  Filterable::validateIncomingType(type);

  switch (axis) {
  case CHILD_AXIS:
  case DESCENDANT_AXIS:
  case DESCENDANT_OR_SELF_AXIS:
    switch (type & ~SEQUENCE_FLAG) {
    case ELEMENT_TYPE:
    case DOCUMENT_TYPE:
    case NODE_TYPE:
      break;

    default:
      semanticError("invalid axis for node type");
    }
    break;

  case ATTRIBUTE_AXIS:
  case PARENT_AXIS:
    switch (type & ~SEQUENCE_FLAG) {
    case ELEMENT_TYPE:
    case NODE_TYPE:
      break;
    
    default:
      semanticError("invalid axis for node type");
    }
    break;

  default: break;
  }
}

void Step::validate() {
  switch (axis) {
  case CHILD_AXIS:
  case DESCENDANT_AXIS:
  case DESCENDANT_OR_SELF_AXIS:
    setDataType(getTestType(getChild()) | SEQUENCE_FLAG);
    break;

  case ATTRIBUTE_AXIS:
    setDataType(ATTRIBUTE_SEQ_TYPE);
    break;

  case PARENT_AXIS:
    setDataType(ELEMENT_SEQ_TYPE);
    break;

  default: THROW("Invalid axis!");
  }
}

void Step::serializeXML(XMLSerializer &serializer) {
  XMLSerializer::attributes_t attrs;

  attrs["axis"] = getAxisName(axis);

  addCommonAttributes(attrs);
  serializer.startElement("step", attrs);
  serializeChildren(serializer);
  serializer.endElement();
}

RefAST Step::factory() {
  return RefAST(new Step);
}

unsigned int Step::getTestType(XmlPLAST *test) {
  if (!test) THROW("Failed to find test type!");

  switch (test->getType()) {
  case AND: return getTestType(test->getChild());
  case TYPE_TEST: return ((TypeTest *)test)->getTypeTest();
  default: THROW("Unexpected node test type!");
  }
}

const char *Step::getAxisName(axis_t axis) {
  switch (axis) {
  case UNKNOWN_AXIS: return "unknown";
    //case ANCESTOR_AXIS: return "ancestor";
    //case ANCESTOR_OR_SELF_AXIS: return "ancestor_or_self";
  case PARENT_AXIS: return "parent";
    //case PRECEDING_AXIS: return "preceding";
    //case PRECEDING_SIBLING_AXIS: return "preceding_sibling";
  case ATTRIBUTE_AXIS: return "attribute";
  case CHILD_AXIS: return "child";
  case DESCENDANT_AXIS: return "descendant";
  case DESCENDANT_OR_SELF_AXIS: return "descendant_or_self";
    //case FOLLOWING_AXIS: return "following";
    //case FOLLOWING_SIBLING_AXIS: return "following_sibling";
    //case SELF_AXIS: return "self";
  default: THROW("Invalid axis type!");
  }
}
