#ifndef FUNCTIONISZEINFO_H
#define FUNCTIONISZEINFO_H

#include <xmlpl/parser/environment/EnvEntry.h>
#include <xmlpl/parser/ast/VariableRef.h>

#include <set>

namespace xmlpl {
  struct FunctionizeInfo {
    unsigned int id;
    std::set<EnvEntry *> varRefs;

    void findVarRefs(XmlPLAST *ast, const unsigned int maxDepth) {
      while (ast) {
	findVarRefs(ast->getChild(), maxDepth);
	
	if (ast->getType() == XmlPLAST::VAR_REF) {
	  VariableRef *vRef = (VariableRef *)ast;
	  EnvEntry *entry = vRef->getEnvEntry().get();

	  if (entry->getDepth() <= maxDepth && entry->getDepth() > 1)
	    varRefs.insert(entry);
	}
	
	ast = ast->getNext();
      }
    }
  };
};
#endif // FUNCTIONISZEINFO_H
