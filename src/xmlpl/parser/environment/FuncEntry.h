#ifndef FUNCENTRY_H
#define FUNCENTRY_H

#include "EnvEntry.h"

class FuncEntry : public EnvEntry {
  const unsigned int type;
  const args_t args;
  bool forwardDecl;
  const BuiltinFunctorBase *functor;

public:
  FuncEntry(const unsigned int type, const Name &name, const args_t &args,
	    const Location &location, const unsigned int depth) :
    EnvEntry(name, location, depth), type(type), args(args), forwardDecl(true), functor(0) {}
  virtual ~FuncEntry() {}

  virtual const unsigned int getType() const {return type;}

  virtual const args_t &getArgs() const {return args;}
  virtual const bool isForwardDecl() const {return forwardDecl;}
  virtual void declareBody(const Location &location);

  virtual void setBuiltinFunctor(const BuiltinFunctorBase *functor) {this->functor = functor;}
  virtual const BuiltinFunctorBase *getBuiltinFunctor() const {return functor;}

  virtual int getEntryType() const {return FUNC_ENTRY;}
  virtual std::string toString() const;
};
#endif // FUNCENTRY_H
