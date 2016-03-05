#ifndef ARG_H
#define ARG_H

#include "Name.h"
#include "Type.h"

struct Arg : public xmlpl::TypeID {
  unsigned int type;
  bool byReference;
  Name name;

  Arg() : type(UNKNOWN_TYPE), byReference(false) {}
  Arg(const Arg &a) : type(a.type), byReference(a.byReference), name(a.name) {}
  Arg(const unsigned int type, const bool byReference = false) :
    type(type), byReference(byReference) {}
  Arg(const unsigned int type, const bool byReference, const Name name) :
    type(type), byReference(byReference), name(name) {}
};

#include <vector>
typedef std::vector<Arg> args_t;

#endif // ARG_H
