#include "TypeEntry.h"

using namespace std;
using namespace xmlpl;

string TypeEntry::toString() const {
  return getName().getFullName();
}
