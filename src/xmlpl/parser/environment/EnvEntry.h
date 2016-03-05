#ifndef ENVENTRY_H
#define ENVENTRY_H

#include <BasicUtils/BasicSmartPointer.h>

#include "Name.h"
#include "Arg.h"
#include "Type.h"
#include "BuiltinFunctor.h"
#include <xmlpl/Location.h>

#include <string>

struct EnvEntryTypes {
  enum {
    VAR_ENTRY,
    FUNC_ENTRY,
    TYPE_ENTRY
  };
};

class EnvEntry;

typedef BasicSmartPointer<EnvEntry> EnvEntryRef;

class EnvEntry : public EnvEntryTypes {
  Name name;
  Location location;
  EnvEntryRef next;
  unsigned int envRefCount;
  const unsigned int depth;

public:
  EnvEntry(const Name &name, const Location &location, const unsigned int depth)
    : name(name), location(location), envRefCount(0), depth(depth) {}
  virtual ~EnvEntry() {}

  Name &getName() {return name;}
  const Name &getName() const {return name;}

  const Location &getLocation() const {return location;}
  void setLocation(const Location &location) {this->location = location;}

  const EnvEntryRef &getNext() const {return next;}
  void setNext(const EnvEntryRef &next) {this->next = next;}

  const unsigned int getEnvRefCount() const {return envRefCount;}
  void incrementEnvRefCount() {envRefCount++;}

  const unsigned int getDepth() const {return depth;}

  // All entry methods
  virtual const unsigned int getType() const;

  // Variable entry methods
  virtual const bool isConstant() const;

  // Function entry methods
  virtual const args_t &getArgs() const;
  virtual const bool isForwardDecl() const;
  virtual void declareBody(const Location &location);
  virtual void setBuiltinFunctor(const BuiltinFunctorBase *functor);
  virtual const BuiltinFunctorBase *getBuiltinFunctor() const;

  virtual int getEntryType() const = 0;
  virtual std::string toString() const = 0;
};

struct ltEnvEntry {
  bool operator()(EnvEntryRef e1, EnvEntryRef e2) const {
    return e1->getName().getRealName() < e2->getName().getRealName();
  }
};
#endif // ENVENTRY_H
