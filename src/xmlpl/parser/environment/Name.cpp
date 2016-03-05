#include "Name.h"

#include <BasicUtils/BasicException.h>

using namespace std;

Name::Name(const string &name) : namespaceStr(0) {
  parseName(name, *this);
}

Name::Name(const char *name) : namespaceStr(0) {
  parseName(string(name), *this);
}

const string Name::getFullName() const {
  if (!hasPseudonym()) return getFullRealName();

  if (prefix == "") return name;
  return prefix + "." + name;
}

const string Name::getFullRealName() const {
  if (realPrefix == "") return realName;
  return realPrefix + "." + realName;
}

bool Name::parseName(const string &str, Name &n) {
  vector<string> path;
  bool valid = parsePath(str, path);

  if (!path.empty()) n.realName = path[path.size() - 1];
  for (unsigned int i = 0; i + 1 < path.size(); i++)
    if (i) n.realPrefix += "." + path[i];
    else n.realPrefix = path[i];

  return valid;
}

bool Name::parsePath(const string &name, vector<string> &path) {
  if (name == ".") {
    path.push_back(name);
    return true;
  }

  string::size_type size = name.size();
  string::size_type start = 0;
  string::size_type end = 0;

  // find first dot
  while (end < size && name[end] != '.') end++;
  
  while (true) {
    if (start >= end) return false;

    // add to path
    path.push_back(name.substr(start, end - start));

    if (end == size) return true;

    // skip dot
    end++;
    if (end == size || name[end] == '.') return false;
    start = end;
    
    // find next dot
    while (end < size && name[end] != '.') end++;
  }
}
