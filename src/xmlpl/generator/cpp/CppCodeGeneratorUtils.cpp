#include "CppCodeGenerator.h"

#include <xmlpl/parser/environment/Type.h>

#include <BasicUtils/BasicException.h>
#include <BasicUtils/BasicString.h>
#include <BasicUtils/BasicArray.h>

#include <sstream>

extern "C" {
#include "md5.h"
}

using namespace std;
using namespace xmlpl;

void CppCodeGenerator::printBoxComment(ostream &s, const string c,
				       unsigned width) {
  width -= 2;

  s << "/";
  for (unsigned int i = 0; i < width; i++) s << "*";

  s << "\\" << endl;

  string w;
  unsigned int len = 0;
  stringstream ss(c);
  
  s << " *";
  len = 1;
  while (ss >> w) {
    if (len + w.length() + 1 < width) {
      s << " " << w;
      
      len += w.length() + 1;

    } else {

      if (len > 1) {
	for (unsigned int i = len; i < width - 1; i++)
	  s << " ";

	s << "*" << endl << " *";
	len = 1;
      }

      s << " " << w;
      len += w.length() + 1;

      if (len >= width) {
	s << endl << " *";
	len = 1;
      }
    }
  }

  for (unsigned int i = len; i < width - 1; i++)
    s << " ";
  
  s << "*"  << endl << "\\";
  for (unsigned int i = 0; i < width; i++) s << "*";
  s << "/" << endl;
}

string CppCodeGenerator::getTypeCPPName(unsigned int type) {
  if (Type::isSequence(type))
    return getTypeCPPName(type & ~SEQUENCE_FLAG) + "Sequence";
  if (Type::isIterator(type))
    return getTypeCPPName(type & ~ITERATOR_FLAG) + "Iterator";
  if (Type::isOStream(type))
    return getTypeCPPName(type & ~OSTREAM_FLAG) + "OStream";

  switch (type) {
  case NODE_TYPE: return "Node";

  case DOCUMENT_TYPE: return "Document";
  case ELEMENT_TYPE: return "Element";
  case ATTRIBUTE_TYPE: return "Attribute";
  case TEXT_TYPE: return "Text";
  case COMMENT_TYPE: return "Comment";
  case PI_TYPE: return "PI";

  case PREFIX_TYPE: return "Prefix";
  case QNAME_TYPE: return "QName";
  case STRING_TYPE: return "String";
  case INTEGER_TYPE: return "Integer";
  case REAL_TYPE: return "Real";
  case BOOLEAN_TYPE: return "Boolean";

  case VOID_TYPE: return "Void";

  default: THROW(string("Unsupported type: ") + Type::get(type).getName());
  }
}

string CppCodeGenerator::getTargetName(unsigned int type) {
  return getTypeCPPName(type & ~SEQUENCE_FLAG) + "Target";
}

string CppCodeGenerator::getTypeName(unsigned int type) {
  ASSERT_OR_THROW("Null cannot be used as a type!", type != NULL_TYPE);

  string name = getTypeCPPName(type);

  if (Type::isSequence(type) || Type::isIterator(type) ||
      Type::isOStream(type)) return name;
  return name + "_t";
}

string CppCodeGenerator::getCPPName(const Name &name, const string prefix) {
  string nameStr = prefix + getCPPNameStr(name.getRealName());

  if (name.getNamespace().empty()) return nameStr;

  if (namespaceStr == name.getNamespace()) return nameStr;

  return hashNamespace(name.getNamespace()) + "::" + nameStr;
}

string CppCodeGenerator::getCPPNameStr(const string name) {
  BasicArray<char> nameAry;

  nameAry.put('X');
  nameAry.put('P');
  nameAry.put('L');
  nameAry.put('_');
  
  for (unsigned int i = 0; i < name.size(); i++) {
    switch (name[i]) {
    case '_': nameAry.put('_'); nameAry.put('_'); break;
    case '-': nameAry.put('_'); nameAry.put('m'); break;
    case '.': nameAry.put('_'); nameAry.put('d'); break;
    default: nameAry.put(name[i]); break;
    }
  }
  nameAry.put(0);

  return nameAry.getBuffer();
}

string CppCodeGenerator::getCPPString(const std::string str) {
  string s;

  s = "\"";
  for (unsigned int i = 0; i < str.length(); i++)
    switch (str[i]) {
    case '\n': s += "\\n"; break;
    case '\t': s += "\\t"; break;
    case '\\': s += "\\\\"; break;
    case '"': s += "\\\""; break;
    default:
      if (0x7f < (unsigned int)str[i]) {
	char buf[5];
	sprintf(buf, "\\x%x", (int)(unsigned char)str[i]);
	s += buf;
      } else s += str[i];
      break;
    }
  s += "\"";

  return s;
}

void CppCodeGenerator::namespaceOn() {
  if (!isNamespaceOn) {    
    if (namespaceHash != "") {      
      out << TAB << "namespace " << namespaceHash << " {" << endl;
      tabUp();
    }
    
    isNamespaceOn = true;
  }
}

void CppCodeGenerator::namespaceOff() {
  if (isNamespaceOn) {
    if (namespaceHash != "") {
      tabDown();
      out << TAB << "};" << endl;
    }

    isNamespaceOn = false;
  }
}

string CppCodeGenerator::hashNamespace(const string ns) {
  if (ns == "") return "";

  unsigned char buf[16];
  md5_buffer(ns.c_str(), ns.length(), buf);

  char hexBuf[3];
  string nsHash;
  for (int i = 0; i < 16; i++) {
    sprintf(hexBuf, "%X", buf[i]);
    nsHash += hexBuf;
  }

  return string("XPL_") + nsHash;
}

string CppCodeGenerator::getContext() {
  ASSERT_OR_THROW("Context not set!", !contextStack.empty());
  return contextStack.back();
}

string CppCodeGenerator::getRawContext() {
  ASSERT_OR_THROW("Context not set!", !rawContextStack.empty());
  if (rawContextStack.back() == "") return getContext();
  return rawContextStack.back();
}

void CppCodeGenerator::throwException(const string &msg, const XmlPLAST *ast) {
  throw BasicException(msg, BasicFileLocation(sourceFile, ast->getLocation().line,
					      ast->getLocation().column));
}

void CppCodeGenerator::emitContext(const TargetType &targetType, unsigned int contextType) {
  unsigned int from = contextType & ~SEQUENCE_FLAG;
  unsigned int to = targetType.getType() & ~SEQUENCE_FLAG;

  if (targetType.hasAppend() || Type::isSequence(targetType.getType())) {
    out << TAB << "target.append(";
    if (from != to) out << "To" << getTypeCPPName(to) << "::cast(";
    out << getContext();
    if (from != to) out << ")";
    out << ");" << endl;

  } else if (targetType.hasCount()) {
    out << TAB << "count++;" << endl;

  } else if (targetType.getType() == BOOLEAN_TYPE && Type::isSequence(contextType)) {
    out << TAB << "return true;" << endl;

  } else {
    out << TAB << "return ";
    if (from != to) out << "To" << getTypeCPPName(to) << "::cast(";
    out << getContext();
    if (from != to) out << ")";
    out << ";" << endl;
  }
}

bool CppCodeGenerator::functionize(XmlPLAST *ast) {
  bool append = ast->getTargetType().hasAppend();
  unsigned int targetType = ast->getTargetType().getType();

  switch (functionizeMode) {
  case FUNCTIONIZE_IN_DECL:
    functionizeMode = FUNCTIONIZE_CALL;
    return true;

  case FUNCTIONIZE_CALL: {
    if (!ast->functionize()) return true;

    FunctionizeInfo *info = functionizeMap[ast];
    ASSERT_OR_THROW("AST not in functionize map!", info);

    bool firstArg = true;

    if (append || targetType == VOID_TYPE) out << TAB;
    out << "func" << info->id << "(";
    if (append) {
      out << "target";
      firstArg = false;
    }

    set<EnvEntry *>::iterator it;
    for (it = info->varRefs.begin(); it != info->varRefs.end(); it++) {
      if (firstArg) firstArg = false;
      else out << ", ";
      
      if ((*it)->getName().getName() == ".") out << getContext();
      else out << getCPPName((*it)->getName());
    }

    out << ")";
    if (append || targetType == VOID_TYPE) out << ";" << endl;

    return false;
  }

  case FUNCTIONIZE_DECL: {
    FunctionizeInfo *info = new FunctionizeInfo;
    functionizeMap[ast] = info;

    // Set id
    info->id = nextFunctionizeId++;

    // Find variable refs
    unsigned int envDepth = ast->getEnvDepth();
    ASSERT_OR_THROW("AST environment depth not set!", envDepth);
    info->findVarRefs(ast->getChild(), envDepth);

    // Return type
    out << "inline ";
    if (append) out << "void ";
    else {
      if (Type::isSequence(targetType)) out << "Temp";
      out << getTypeName(targetType) << " ";
    }

    // Function name
    out << "func" << info->id << "(";

    bool contextRef = false;
    bool firstArg = true;

    // Arguments
    if (append) {
      out << getTypeCPPName(targetType & ~SEQUENCE_FLAG) << "Target &target";
      firstArg = false;
    }

    set<EnvEntry *>::iterator it;
    for (it = info->varRefs.begin(); it != info->varRefs.end(); it++) {
      if (firstArg) firstArg = false;
      else out << ", ";

      out << getTypeName((*it)->getType()) << " ";

      if ((*it)->getName().getName() == ".") {
	contextRef = true;
	out << "context";

      } else out << "&" << getCPPName((*it)->getName());
    }

    out << ") {" << endl;
    tabUp();

    // Temporary Sequence
    bool tempSequence = !append && (Type::isSequence(targetType) || Type::isNode(targetType));
    if (tempSequence) {
      out << TAB << "Temp" << getTypeCPPName(targetType | SEQUENCE_FLAG)
	  << " target;" << endl;
      out << endl;
    }

    // Output AST code
    if (contextRef) pushContext("context");
    functionizeMode = FUNCTIONIZE_IN_DECL;
    ast->visit(this);
    functionizeMode = FUNCTIONIZE_DECL;
    if (contextRef) popContext();

    // Return value
    if (!append && targetType != VOID_TYPE) {
      out << TAB << "return ";

      if (Type::isSequence(targetType)) out << "target";
      else if (tempSequence)
	out << "target.empty() ? " << getTypeCPPName(targetType) << "Null() : target[0]";
      else out << getTypeCPPName(targetType) << "Null()";

      out << ";" << endl;
    }

    tabDown();
    out << TAB << "}" << endl;

    return false;
  }

  default: THROW("Invalid functionize mode!");
  }
}
