#include "Location.h"

#include <BasicUtils/BasicString.h>

using namespace std;

const string Location::toString() const {
  string s;

  if (line) {
    s = BasicString(line);
    if (column) s = s + ":" + BasicString(column);    
  }

  return s;
}
