#include "Environment.h"

#include "VarEntry.h"
#include "FuncEntry.h"
#include "TypeEntry.h"

#include <xmlpl/Language.h>
#include <xmlpl/LibraryImporter.h>
#include <xmlpl/ErrorHandler.h>
#include <xmlpl/Options.h>

#include <BasicUtils/BasicException.h>
#include <BasicUtils/BasicString.h>

using namespace std;
using namespace xmlpl;

Environment::Environment(root_env_t root) : depth(0) {
  // Declare default types
  for (unsigned int i = 0; Type::types[i]; i++)
    Type::get(Type::types[i]).declare(*this);
}

Environment::Environment() : depth(1) {
  root = new Environment(ROOT_ENV);
  parent = root;
}

EnvEntryRef Environment::lookup(const Name &name) {
  env_map_t::iterator it = env.find(name.getName());
  if (it == env.end()) return 0;

  ns_map_t::iterator it2 = it->second.find(name.getPrefix());
  if (it2 == it->second.end()) return 0;

  return it2->second;
}

EnvEntryRef Environment::lookupRecursive(const Name &name) {
  EnvEntryRef entry = lookup(name);
  if (entry == 0 && parent != 0) return parent->lookupRecursive(name);
  return entry;
}

EnvEntryRef Environment::lookupAll(const Name &name, const Location &location) {
  env_map_t::iterator it = env.find(name.getName());

  if (it != env.end()) {
    ns_map_t::iterator it2;

    if (name.getPrefix() == "") {
      EnvEntryRef entry;
      bool tooMany = false;
      for (it2 = it->second.begin(); it2 != it->second.end(); it2++)
	if (entry == 0) entry = it2->second;
	else {tooMany = true; break;}

      if (tooMany) {
	string candidates;
	for (it2 = it->second.begin(); it2 != it->second.end(); it2++)
	  candidates += "\n  " + it2->second->toString();
	
	ErrorHandler::error("identifier '" + name.getFullName() +
			    "' is ambiguous within this context\n" +
			    "possible candidates are:" + candidates, location);
      }

      return entry;

    } else {
      it2 = it->second.find(name.getPrefix());
      if (it2 != it->second.end()) return it2->second;
    }
  }

  if (parent != 0) return parent->lookupAll(name, location);
  return 0;
}

EnvEntryRef Environment::declare(EnvEntryRef entry) {

  if (entry->getName().getNamespace() == 0)
    entry->getName().setNamespace(defaultNS.c_str());

  return env[entry->getName().getName()][entry->getName().getPrefix()] = entry;
}

const vector<EnvEntryRef> Environment::import(const Name &name,
					      const VersionExpression *ve,
					      const Location &location) {
  LibraryImporter *importer = Options::getInstance()->getLanguage()->getLibraryImporter();
  return importer->import(name, ve, *this, location);
}

EnvEntryRef Environment::declareType(const Name &name, const unsigned int type,
				     const Location &location) {
  EnvEntryRef entry = lookup(name);

  if (entry != 0)
    ErrorHandler::error(string("identifier '") + name.getFullName() +
			"' previously declared at " +
			entry->getLocation().toString(), location);

  return declare(new TypeEntry(name, type, location, depth));
}

EnvEntryRef Environment::declareVariable(const Name &name, const unsigned int type,
					 const bool constant, const Location &location) {
  EnvEntryRef entry = lookup(name);

  if (entry != 0)
    ErrorHandler::error(string("identifier '") + name.getFullName() +
			"' previously declared at " +
			entry->getLocation().toString(), location);

  return declare(new VarEntry(name, type, constant, location, depth));
}

EnvEntryRef Environment::declareFunction(const Name &name, const unsigned int type,
					 const args_t &args, const Location &location) {
  EnvEntryRef entry = lookup(name);

  if (entry != 0) {
    if (name.getName() == "main") {
      ErrorHandler::error("function main cannot be overloaded");
      return 0;
    }

    if (entry->getEntryType() != EnvEntry::FUNC_ENTRY)
      ErrorHandler::error(string("identifier '") + name.getName() +
			  "' previously declared at " +
			  entry->getLocation().toString(), location);
    
    EnvEntryRef func = entry;
    while (func != 0) {
      if (compareArgs(func->getArgs(), args)) {

	if (func->getType() != type) {
	  ErrorHandler::error(string("function declarations differ only in return type, ") +
			      "first declared at:" +
			      "\n  " + func->toString(), location);
	  return 0;
	}

	return func;
      }

      func = func->getNext();
    }
  }

  FuncEntry *newFunc = new FuncEntry(type, name, args, location, depth);
  if (entry != 0) newFunc->setNext(entry);

  return declare(newFunc);
}

EnvEntryRef Environment::declareBuiltin(const char *name, const unsigned int type,
					const args_t &args, BuiltinFunctorBase *functor) {
  // TODO should all builtins be in the same namespace?
  EnvEntryRef entry = declareFunction(string("xmlpl.builtin.") + name,
				      type, args, Location());
  entry->setBuiltinFunctor(functor);

  return entry;
}

const unsigned int Environment::lookupType(const Name &name, const Location &location) {
  EnvEntryRef entry = lookupAll(name, location);

  if (entry == 0) {
    ErrorHandler::error(string("undeclared type ") + name.getFullName(), location);
    return Type::UNKNOWN_TYPE;
  }

  if (entry->getEntryType() != EnvEntry::TYPE_ENTRY) {
    ErrorHandler::error(string("identifier '") + name.getFullName() + "' is not a type",
			location);
    return Type::UNKNOWN_TYPE;
  }

  entry->incrementEnvRefCount();
  return entry->getType();
}

EnvEntryRef Environment::lookupVariable(const Name &name, const Location &location) {
  EnvEntryRef entry = lookupAll(name, location);
  
  if (entry == 0) {
    ErrorHandler::error(string("undeclared variable ") + name.getFullName(), location);
    return 0;
  }

  if (entry->getEntryType() != EnvEntry::VAR_ENTRY) {
    ErrorHandler::error(string("identifier '") + name.getFullName() +
			"' is not a variable", location);
    return 0;
  }

  entry->incrementEnvRefCount();
  return entry;
}

EnvEntryRef Environment::lookupFunction(const Name &name, const args_t &args,
					const Location &location) {

  // Lookup name
  EnvEntryRef entry = lookupAll(name, location);

  // Error if not found
  if (entry == 0) {
    ErrorHandler::error(string("undeclared function ") +
			formatFunctionName(0, name.getFullName(), args), location);
    return 0;
  }

  // Check if found identifier is a function
  if (entry->getEntryType() != EnvEntry::FUNC_ENTRY) {
    ErrorHandler::error(string("identifier '") + name.getFullName() +
			"' is not a function", location);
    return 0;
  }
  
  // Search for an exact match
  for (EnvEntryRef func = entry; func.get(); func = func->getNext())
    if (compareArgs(func->getArgs(), args)) {
      func->incrementEnvRefCount();
      return func;
    }

  // Search for possible matches
  list<EnvEntryRef> funcs;
  for (EnvEntryRef func = entry; func.get(); func = func->getNext())
    if (compareArgs(func->getArgs(), args, true))
      funcs.push_front(func);

  
  // One match
  if (funcs.size() == 1) {
    (*funcs.begin())->incrementEnvRefCount();
    return *funcs.begin();
  }

  string err;
  string candidates;

  if (funcs.size() == 0) { // No matches
    err = "no matching function for call";

    for (EnvEntryRef func = entry; func.get(); func = func->getNext()) {
      if (func != entry) candidates = "\n" + candidates;
      candidates = string("  ") + func->toString() + candidates;
    }

  } else { // Ambiguous match
    err = "ambigious function call";
    
    for (list<EnvEntryRef>::iterator it = funcs.begin(); it != funcs.end(); it++)
      candidates += "  " + (*it)->toString() + "\n";
  }

  err += ": " + formatFunctionName(0, name.getFullName(), args) + "\n";
  err += "possible candidates are:\n" + candidates;
  
  ErrorHandler::error(err, location);
  return 0;
}

bool Environment::compareArgs(const args_t &args1, const args_t &args2,
			      const bool allowCasting) {
  if (args1.size() != args2.size()) return false;

  for (unsigned int i = 0; i < args1.size(); i++)
    if (args1[i].type != args2[i].type &&
	(!allowCasting || !Type::canCast(args2[i].type, args1[i].type)))
      return false;

  return true;
}

string Environment::formatFunctionName(const unsigned int returnType, string name,
				       const args_t &args) {

  if (returnType) name = Type::get(returnType).getName() + " " + name;

  name += "(";
  
  args_t::const_iterator it = args.begin();
  for (; it != args.end(); it++) {
    if (it != args.begin()) name += ", ";
    name += Type::get(it->type).getName();
    if (it->byReference) name += " &";
  }

  name += ")";

  return name;
}
