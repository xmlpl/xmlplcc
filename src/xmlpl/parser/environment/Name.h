#ifndef NAME_H
#define NAME_H

#include <vector>
#include <string>
#include <ostream>

class Name {
  std::string name;
  std::string prefix;
  std::string realName;
  std::string realPrefix;
  const char *namespaceStr;

public:
  Name() : namespaceStr(0) {}
  Name(const Name &n) : name(n.name), prefix(n.prefix),
			realName(n.realName), realPrefix(n.realPrefix),
			namespaceStr(n.namespaceStr) {}
  Name(const std::string &name);
  Name(const char *name);

  void setName(const std::string &name) {this->name = name;}
  const std::string &getName() const {return hasPseudonym() ? name : realName;}

  void setPrefix(const std::string &prefix) {this->prefix = prefix;}
  const std::string &getPrefix() const {return hasPseudonym() ? prefix : realPrefix;}

  void setRealName(const std::string &realName) {this->realName = realName;}
  const std::string &getRealName() const {return realName;}

  void setRealPrefix(const std::string &realPrefix) {this->realPrefix = realPrefix;}
  const std::string &getRealPrefix() const {return realPrefix;}

  void setNamespace(const char *namespaceStr) {this->namespaceStr = namespaceStr;}
  const char *getNamespace() const {return namespaceStr;}

  bool hasPseudonym() const {return name != "" || prefix != "";}

  const std::string getFullName() const;
  const std::string getFullRealName() const;

  static bool parseName(const std::string &str, Name &n);
  static bool parsePath(const std::string &name, std::vector<std::string> &path);
};

inline std::ostream &operator<<(std::ostream &stream, const Name &name) {
  return stream << name.getFullName();
}

#endif // NAME_H
