#include "FuncEntry.h"

#include "Type.h"

#include <xmlpl/ErrorHandler.h>

#include <BasicUtils/BasicException.h>

using namespace xmlpl;
using namespace std;

void FuncEntry::declareBody(const Location &location) {
  if (forwardDecl) {
    forwardDecl = false;
    setLocation(location);

  } else
    ErrorHandler::error(string("Duplicate declaration of function body, first declared at:") +
			"\n  " + toString(), location);
}

string FuncEntry::toString() const {
  string str;

  if (getLocation().line) str = getLocation().toString();
  else str = "(builtin)";

  str += ": " + Type::get(type).getName() + " " +
    getName().getFullName() + "(";

  for (unsigned int i = 0; i < args.size(); i++) {
    if (i) str += ", ";
    str += Type::get(args[i].type).getName();
  }

  str += ")";

  return str;
}
