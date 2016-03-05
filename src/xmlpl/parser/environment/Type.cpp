#include "Type.h"
#include "TypeTables.h"

#include "Environment.h"

#include <BasicUtils/BasicException.h>
#include <BasicUtils/BasicString.h>

using namespace std;
using namespace xmlpl;

class UnknownType : public Type {
public:
  UnknownType() {}

  virtual const string getName() const {return "unknown_type";}
  virtual unsigned int getID() const {return UNKNOWN_TYPE;}
  virtual const string getIDString() const {return "TypeID::UNKNOWN_TYPE";}

  virtual void declare(Environment &env) {}
};

class VoidType : public Type {
public:
  VoidType() {}

  virtual const string getName() const {return "void";}  
  virtual unsigned int getID() const {return VOID_TYPE;}
  virtual const string getIDString() const {return "TypeID::VOID_TYPE";}
};

class NullType : public Type {
public:
  NullType() {}

  virtual const string getName() const {return "null";}
  virtual unsigned int getID() const {return NULL_TYPE;}
  virtual const string getIDString() const {return "TypeID::NULL_TYPE";}

  virtual void declare(Environment &env) {}
};

class PrefixType : public Type {
public:
  PrefixType() {}

  virtual const string getName() const {return "prefix";}
  virtual unsigned int getID() const {return PREFIX_TYPE;}
  virtual const string getIDString() const {return "TypeID::PREFIX_TYPE";}
};

class QNameType : public Type {
public:
  QNameType() {}

  virtual const string getName() const {return "qname";}
  virtual unsigned int getID() const {return QNAME_TYPE;}
  virtual const string getIDString() const {return "TypeID::QNAME_TYPE";}
};

class StringType : public Type {
public:
  StringType() {}

  virtual const string getName() const {return "string";}
  virtual unsigned int getID() const {return STRING_TYPE;}
  virtual const string getIDString() const {return "TypeID::STRING_TYPE";}
};

class IntegerType : public Type {
public:
  IntegerType() {}

  virtual const string getName() const {return "integer";}
  virtual unsigned int getID() const {return INTEGER_TYPE;}
  virtual const string getIDString() const {return "TypeID::INTEGER_TYPE";}
};

class RealType : public Type {
public:
  RealType() {}

  virtual const string getName() const {return "real";}
  virtual unsigned int getID() const {return REAL_TYPE;}
  virtual const string getIDString() const {return "TypeID::REAL_TYPE";}
};

class BooleanType : public Type {
public:
  BooleanType() {}

  virtual const string getName() const {return "boolean";}
  virtual unsigned int getID() const {return BOOLEAN_TYPE;}
  virtual const string getIDString() const {return "TypeID::BOOLEAN_TYPE";}
};


class NodeType : public Type {
public:
  NodeType() {}

  virtual const string getName() const {return "node";}  
  virtual unsigned int getID() const {return NODE_TYPE;}
  virtual const string getIDString() const {return "TypeID::NODE_TYPE";}

  virtual bool isPathType() const {return true;}
};

class DocumentType : public Type {
public:
  DocumentType() {}

  virtual const string getName() const {return "document";}
  virtual unsigned int getID() const {return DOCUMENT_TYPE;}
  virtual const string getIDString() const {return "TypeID::DOCUMENT_TYPE";}

  virtual bool isPathType() const {return true;}
};

class ElementType : public Type {
public:
  ElementType() {}

  virtual const string getName() const {return "element";}  
  virtual unsigned int getID() const {return ELEMENT_TYPE;}
  virtual const string getIDString() const {return "TypeID::ELEMENT_TYPE";}

  virtual bool isPathType() const {return true;}
};

class AttributeType : public Type {
public:
  AttributeType() {}

  virtual const string getName() const {return "attribute";}
  virtual unsigned int getID() const {return ATTRIBUTE_TYPE;}
  virtual const string getIDString() const {return "TypeID::ATTRIBUTE_TYPE";}
};

class TextType : public Type {
public:
  TextType() {}

  virtual const string getName() const {return "text";}
  virtual unsigned int getID() const {return TEXT_TYPE;}
  virtual const string getIDString() const {return "TypeID::TEXT_TYPE";}
};

class CommentType : public Type {
public:
  CommentType() {}

  virtual const string getName() const {return "comment";}
  virtual unsigned int getID() const {return COMMENT_TYPE;}
  virtual const string getIDString() const {return "TypeID::COMMENT_TYPE";}
};

class PIType : public Type {
public:
  PIType() {}

  virtual const string getName() const {return "pi";}
  virtual unsigned int getID() const {return PI_TYPE;}
  virtual const string getIDString() const {return "TypeID::PI_TYPE";}
};

class ProxyType : public Type {
public:
  ProxyType() {}

  virtual const string getName() const {return "proxy";}
  virtual unsigned int getID() const {return PROXY_TYPE;}
  virtual const string getIDString() const {return "TypeID::PROXY_TYPE";}

  virtual void declare(Environment &env) {}
};

class SequenceType : public Type {
  const Type &childType;

public:
  SequenceType(const Type &childType) : childType(childType) {}

  virtual const string getName() const {return childType.getName() + "[]";}
  virtual unsigned int getID() const {return SEQUENCE_FLAG | childType.getID();}
  virtual const string getIDString() const {
    return string("(") + childType.getIDString() + " | TypeID::SEQUENCE_FLAG)";
  }

  virtual bool isPathType() const {return childType.isPathType();}
};

class IteratorType : public Type {
  const Type &childType;

public:
  IteratorType(const Type &childType) : childType(childType) {}

  virtual const string getName() const {return childType.getName() + "++";}
  virtual unsigned int getID() const {return ITERATOR_FLAG | childType.getID();}
  virtual const string getIDString() const {
    return string("(") + childType.getIDString() + " | TypeID::ITERATOR_FLAG)";
  }
};

class OStreamType : public Type {
  const Type &childType;

public:
  OStreamType(const Type &childType) : childType(childType) {}

  virtual const string getName() const {return childType.getName() + "<<";}
  virtual unsigned int getID() const {return OSTREAM_FLAG | childType.getID();}
  virtual const string getIDString() const {
    return string("(") + childType.getIDString() + " | TypeID::OSTREAM_FLAG)";
  }
};

static UnknownType UNKNOWN_INSTANCE;    
static NodeType NODE_INSTANCE;
static DocumentType DOCUMENT_INSTANCE;
static ElementType ELEMENT_INSTANCE;
static AttributeType ATTRIBUTE_INSTANCE;
static TextType TEXT_INSTANCE;
static CommentType COMMENT_INSTANCE;
static PIType PROCESSING_INSTRUCTION_INSTANCE;
static ProxyType PROXY_INSTANCE;
static PrefixType PREFIX_INSTANCE;
static QNameType QNAME_INSTANCE;
static StringType STRING_INSTANCE;
static IntegerType INTEGER_INSTANCE;
static RealType REAL_INSTANCE;
static BooleanType BOOLEAN_INSTANCE;
static NullType NULL_INSTANCE;
static VoidType VOID_INSTANCE;


static SequenceType NODE_SEQ_INSTANCE(NODE_INSTANCE);

static SequenceType DOCUMENT_SEQ_INSTANCE(DOCUMENT_INSTANCE);
static SequenceType ELEMENT_SEQ_INSTANCE(ELEMENT_INSTANCE);
static SequenceType ATTRIBUTE_SEQ_INSTANCE(ATTRIBUTE_INSTANCE);
static SequenceType TEXT_SEQ_INSTANCE(TEXT_INSTANCE);
static SequenceType COMMENT_SEQ_INSTANCE(COMMENT_INSTANCE);
static SequenceType PI_SEQ_INSTANCE(PROCESSING_INSTRUCTION_INSTANCE);

static SequenceType BOOLEAN_SEQ_INSTANCE(BOOLEAN_INSTANCE);
static SequenceType PREFIX_SEQ_INSTANCE(PREFIX_INSTANCE);
static SequenceType QNAME_SEQ_INSTANCE(QNAME_INSTANCE);
static SequenceType STRING_SEQ_INSTANCE(STRING_INSTANCE);
static SequenceType INTEGER_SEQ_INSTANCE(INTEGER_INSTANCE);
static SequenceType REAL_SEQ_INSTANCE(REAL_INSTANCE);


static IteratorType NODE_ITER_INSTANCE(NODE_INSTANCE);

static IteratorType DOCUMENT_ITER_INSTANCE(DOCUMENT_INSTANCE);
static IteratorType ELEMENT_ITER_INSTANCE(ELEMENT_INSTANCE);
static IteratorType ATTRIBUTE_ITER_INSTANCE(ATTRIBUTE_INSTANCE);
static IteratorType TEXT_ITER_INSTANCE(TEXT_INSTANCE);
static IteratorType COMMENT_ITER_INSTANCE(COMMENT_INSTANCE);
static IteratorType PI_ITER_INSTANCE(PROCESSING_INSTRUCTION_INSTANCE);

static IteratorType BOOLEAN_ITER_INSTANCE(BOOLEAN_INSTANCE);
static IteratorType PREFIX_ITER_INSTANCE(PREFIX_INSTANCE);
static IteratorType QNAME_ITER_INSTANCE(QNAME_INSTANCE);
static IteratorType STRING_ITER_INSTANCE(STRING_INSTANCE);
static IteratorType INTEGER_ITER_INSTANCE(INTEGER_INSTANCE);
static IteratorType REAL_ITER_INSTANCE(REAL_INSTANCE);


static OStreamType NODE_OSTR_INSTANCE(NODE_INSTANCE);

static OStreamType DOCUMENT_OSTR_INSTANCE(DOCUMENT_INSTANCE);
static OStreamType ELEMENT_OSTR_INSTANCE(ELEMENT_INSTANCE);
static OStreamType ATTRIBUTE_OSTR_INSTANCE(ATTRIBUTE_INSTANCE);
static OStreamType TEXT_OSTR_INSTANCE(TEXT_INSTANCE);
static OStreamType COMMENT_OSTR_INSTANCE(COMMENT_INSTANCE);
static OStreamType PI_OSTR_INSTANCE(PROCESSING_INSTRUCTION_INSTANCE);

static OStreamType BOOLEAN_OSTR_INSTANCE(BOOLEAN_INSTANCE);
static OStreamType PREFIX_OSTR_INSTANCE(PREFIX_INSTANCE);
static OStreamType QNAME_OSTR_INSTANCE(QNAME_INSTANCE);
static OStreamType STRING_OSTR_INSTANCE(STRING_INSTANCE);
static OStreamType INTEGER_OSTR_INSTANCE(INTEGER_INSTANCE);
static OStreamType REAL_OSTR_INSTANCE(REAL_INSTANCE);


unsigned int Type::types[] = {
  NULL_TYPE,
  VOID_TYPE,

  BOOLEAN_TYPE,
  INTEGER_TYPE,
  REAL_TYPE,
  STRING_TYPE,
  PREFIX_TYPE,
  QNAME_TYPE,
  
  PROXY_TYPE,

  NODE_TYPE,
  
  DOCUMENT_TYPE,
  ELEMENT_TYPE,
  ATTRIBUTE_TYPE,
  TEXT_TYPE,
  COMMENT_TYPE,
  PI_TYPE,

  BOOLEAN_SEQ_TYPE,
  INTEGER_SEQ_TYPE,
  REAL_SEQ_TYPE,
  STRING_SEQ_TYPE,
  PREFIX_SEQ_TYPE,
  QNAME_SEQ_TYPE,

  NODE_SEQ_TYPE,

  DOCUMENT_SEQ_TYPE,
  ELEMENT_SEQ_TYPE,
  ATTRIBUTE_SEQ_TYPE,
  TEXT_SEQ_TYPE,
  COMMENT_SEQ_TYPE,
  PI_SEQ_TYPE,
  
  BOOLEAN_ITER_TYPE,
  INTEGER_ITER_TYPE,
  REAL_ITER_TYPE,
  STRING_ITER_TYPE,
  PREFIX_ITER_TYPE,
  QNAME_ITER_TYPE,

  NODE_ITER_TYPE,

  DOCUMENT_ITER_TYPE,
  ELEMENT_ITER_TYPE,
  ATTRIBUTE_ITER_TYPE,
  TEXT_ITER_TYPE,
  COMMENT_ITER_TYPE,
  PI_ITER_TYPE,
  
  BOOLEAN_OSTR_TYPE,
  INTEGER_OSTR_TYPE,
  REAL_OSTR_TYPE,
  STRING_OSTR_TYPE,
  PREFIX_OSTR_TYPE,
  QNAME_OSTR_TYPE,

  NODE_OSTR_TYPE,

  DOCUMENT_OSTR_TYPE,
  ELEMENT_OSTR_TYPE,
  ATTRIBUTE_OSTR_TYPE,
  TEXT_OSTR_TYPE,
  COMMENT_OSTR_TYPE,
  PI_OSTR_TYPE,
  
  UNKNOWN_TYPE    
};

void Type::declare(Environment &env) {
  env.declareType(getName(), getID(), Location());
}

Type &Type::get(const unsigned int typeID) {
  switch (typeID) {
  case UNKNOWN_TYPE: return UNKNOWN_INSTANCE;
    
  case NODE_TYPE: return NODE_INSTANCE;

  case DOCUMENT_TYPE: return DOCUMENT_INSTANCE;
  case ELEMENT_TYPE: return ELEMENT_INSTANCE;
  case ATTRIBUTE_TYPE: return ATTRIBUTE_INSTANCE;
  case TEXT_TYPE: return TEXT_INSTANCE;
  case COMMENT_TYPE: return COMMENT_INSTANCE;
  case PI_TYPE: return PROCESSING_INSTRUCTION_INSTANCE;
  case PROXY_TYPE: return PROXY_INSTANCE;

  case PREFIX_TYPE: return PREFIX_INSTANCE;
  case QNAME_TYPE: return QNAME_INSTANCE;
  case STRING_TYPE: return STRING_INSTANCE;
  case INTEGER_TYPE: return INTEGER_INSTANCE;
  case REAL_TYPE: return REAL_INSTANCE;
  case BOOLEAN_TYPE: return BOOLEAN_INSTANCE;

  case NULL_TYPE: return NULL_INSTANCE;
  case VOID_TYPE: return VOID_INSTANCE;

  case NODE_SEQ_TYPE: return NODE_SEQ_INSTANCE;

  case DOCUMENT_SEQ_TYPE: return DOCUMENT_SEQ_INSTANCE;
  case ELEMENT_SEQ_TYPE: return ELEMENT_SEQ_INSTANCE;
  case ATTRIBUTE_SEQ_TYPE: return ATTRIBUTE_SEQ_INSTANCE;
  case TEXT_SEQ_TYPE: return TEXT_SEQ_INSTANCE;
  case COMMENT_SEQ_TYPE: return COMMENT_SEQ_INSTANCE;
  case PI_SEQ_TYPE: return PI_SEQ_INSTANCE;

  case BOOLEAN_SEQ_TYPE: return BOOLEAN_SEQ_INSTANCE;
  case PREFIX_SEQ_TYPE: return PREFIX_SEQ_INSTANCE;
  case QNAME_SEQ_TYPE: return QNAME_SEQ_INSTANCE;
  case STRING_SEQ_TYPE: return STRING_SEQ_INSTANCE;
  case INTEGER_SEQ_TYPE: return INTEGER_SEQ_INSTANCE;
  case REAL_SEQ_TYPE: return REAL_SEQ_INSTANCE;

  case NODE_ITER_TYPE: return NODE_ITER_INSTANCE;

  case DOCUMENT_ITER_TYPE: return DOCUMENT_ITER_INSTANCE;
  case ELEMENT_ITER_TYPE: return ELEMENT_ITER_INSTANCE;
  case ATTRIBUTE_ITER_TYPE: return ATTRIBUTE_ITER_INSTANCE;
  case TEXT_ITER_TYPE: return TEXT_ITER_INSTANCE;
  case COMMENT_ITER_TYPE: return COMMENT_ITER_INSTANCE;
  case PI_ITER_TYPE: return PI_ITER_INSTANCE;

  case BOOLEAN_ITER_TYPE: return BOOLEAN_ITER_INSTANCE;
  case PREFIX_ITER_TYPE: return PREFIX_ITER_INSTANCE;
  case QNAME_ITER_TYPE: return QNAME_ITER_INSTANCE;
  case STRING_ITER_TYPE: return STRING_ITER_INSTANCE;
  case INTEGER_ITER_TYPE: return INTEGER_ITER_INSTANCE;
  case REAL_ITER_TYPE: return REAL_ITER_INSTANCE;

  case NODE_OSTR_TYPE: return NODE_OSTR_INSTANCE;

  case DOCUMENT_OSTR_TYPE: return DOCUMENT_OSTR_INSTANCE;
  case ELEMENT_OSTR_TYPE: return ELEMENT_OSTR_INSTANCE;
  case ATTRIBUTE_OSTR_TYPE: return ATTRIBUTE_OSTR_INSTANCE;
  case TEXT_OSTR_TYPE: return TEXT_OSTR_INSTANCE;
  case COMMENT_OSTR_TYPE: return COMMENT_OSTR_INSTANCE;
  case PI_OSTR_TYPE: return PI_OSTR_INSTANCE;

  case BOOLEAN_OSTR_TYPE: return BOOLEAN_OSTR_INSTANCE;
  case PREFIX_OSTR_TYPE: return PREFIX_OSTR_INSTANCE;
  case QNAME_OSTR_TYPE: return QNAME_OSTR_INSTANCE;
  case STRING_OSTR_TYPE: return STRING_OSTR_INSTANCE;
  case INTEGER_OSTR_TYPE: return INTEGER_OSTR_INSTANCE;
  case REAL_OSTR_TYPE: return REAL_OSTR_INSTANCE;

  default:
    THROW(string("Unrecognized type id: ") + BasicString(typeID));
  }
}

unsigned int Type::canCast(const unsigned int from, const unsigned int to) {
  if (to & ITERATOR_FLAG) return false;
  if ((to & OSTREAM_FLAG) && (from & SEQUENCE_FLAG))
    return canCast(from & ~SEQUENCE_FLAG, to & ~OSTREAM_FLAG);
  if ((to & OSTREAM_FLAG) || (from & OSTREAM_FLAG)) return false;

  if (from & ITERATOR_FLAG) return to == BOOLEAN_TYPE;

  return TypeTables::lookupCastable(from, to);
}
