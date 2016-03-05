#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <BasicUtils/BasicSmartPointer.h>

#include <string.h>
#include <string>
#include <map>
#include <list>
#include <vector>

#include "Name.h"
#include "EnvEntry.h"
#include "FuncEntry.h"
#include "VersionExpression.h"

#include <xmlpl/Location.h>

struct ltString {
  bool operator()(const char *s1, const char *s2) const {
    if (!s1 && !s2) return false;
    if (!s1) return true;
    if (!s2) return false;
    return strcmp(s1, s2) < 0;
  }
};

class Environment;

typedef BasicSmartPointer<Environment> EnvRef;

class Environment {
public:
  typedef std::map<const std::string, EnvEntryRef> ns_map_t;
  typedef std::map<const std::string, ns_map_t> env_map_t;
  
private:
  EnvRef parent;
  EnvRef root;
  const unsigned int depth;
  
  env_map_t env;
  std::string defaultNS;

  typedef enum {ROOT_ENV} root_env_t;
  Environment(root_env_t root);

  Environment(EnvRef parent) : parent(parent), root(parent->getRoot()),
			       depth(parent->depth + 1) {
    if (root == 0) root = parent;
  }

public:
  Environment();
  ~Environment() {}

  EnvRef getRoot() {return root;}
  EnvRef getParent() {return parent;}
  unsigned int getDepth() const {return depth;}

  env_map_t::const_iterator begin() const {return env.begin();}
  env_map_t::const_iterator end() const {return env.end();}

  EnvEntryRef lookup(const Name &name);
  EnvEntryRef lookupAll(const Name &name, const Location &location);
  EnvEntryRef lookupRecursive(const Name &name);
  EnvEntryRef declare(EnvEntryRef entry);

  const std::vector<EnvEntryRef> import(const Name &name, const VersionExpression *ve,
					const Location &location);

  void setDefaultNamespace(const std::string &defaultNS) {this->defaultNS = defaultNS;}
  const std::string &getDefaultNamespace() const {return defaultNS;}
  EnvEntryRef declareType(const Name &name, const unsigned int type,
			  const Location &location);
  EnvEntryRef declareVariable(const Name &name, const unsigned int type, const bool constant,
			      const Location &location);
  EnvEntryRef declareFunction(const Name &name, const unsigned int type,
			      const args_t &args, const Location &location);
  EnvEntryRef declareBuiltin(const char *name, const unsigned int type,
			     const args_t &args, BuiltinFunctorBase *functor);

  const unsigned int lookupType(const Name &name, const Location &location);
  EnvEntryRef lookupVariable(const Name &name, const Location &location);
  EnvEntryRef lookupFunction(const Name &name, const args_t &args, const Location &location);

  static EnvRef extend(EnvRef parent) {return EnvRef(new Environment(parent));}

  static bool compareArgs(const args_t &args1, const args_t &args2,
			  const bool allowCasting = false);
  static std::string formatFunctionName(const unsigned int returnType, std::string name,
					const args_t &args);
};
#endif // ENVIRONMENT_H
