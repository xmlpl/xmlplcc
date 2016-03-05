#include "EnvEntry.h"

#include <BasicUtils/BasicException.h>

using namespace std;

const unsigned int EnvEntry::getType() const {
  THROW("Environment entry does not have a type!");
}

const bool EnvEntry::isConstant() const {
  THROW("Environment entry is not a variable!");
}

const args_t &EnvEntry::getArgs() const {
  THROW("Environment entry is not a function!");
}

const bool EnvEntry::isForwardDecl() const {
  THROW("Environment entry is not a function!");
}

void EnvEntry::declareBody(const Location &location) {
  THROW("Environment entry is not a function!");
}

void EnvEntry::setBuiltinFunctor(const BuiltinFunctorBase *functor) {
  THROW("Environment entry is not a function!");
}

const BuiltinFunctorBase *EnvEntry::getBuiltinFunctor() const {
  THROW("Environment entry is not a function!");
}
