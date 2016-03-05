#include "VarEntry.h"

#include "Type.h"

using namespace std;
using namespace xmlpl;

string VarEntry::toString() const {
  return getLocation().toString() + ": " + Type::get(type).getName() + " " +
    getName().getFullName();
}
