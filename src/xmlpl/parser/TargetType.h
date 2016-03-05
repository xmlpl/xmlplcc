#ifndef TARGETTYPE_H
#define TARGETTYPE_H

#include "TargetTypeFlags.h"

class TargetType : public TargetTypeFlags {
  unsigned int type;

public:
  TargetType() : type(UNKNOWN_TYPE) {}
  TargetType(const unsigned int type) : type(type) {}
  TargetType(const TargetType &o) : type(o.type) {}

  unsigned int getType() const {return type & ~FLAGS_MASK;}
  unsigned int getFlags() const {return type & FLAGS_MASK;}
  TargetType setFlags(const unsigned int flags) const {return type | flags;}
  TargetType clearFlags(const unsigned int flags) const {return type & ~flags;}

  const bool hasAppend() const {return type & APPEND_FLAG;}
  const bool hasCount() const {return type & COUNT_FLAG;}
  const bool hasBreak() const {return type & BREAK_FLAG;}
  const bool hasContinue() const {return type & CONTINUE_FLAG;}
  const bool hasReturn() const {return type & RETURN_FLAG;}

  bool operator==(const TargetType &o) const {return getType() == o.getType();}
  bool operator!=(const TargetType &o) const {return getType() != o.getType();}
};
#endif // TARGETTYPE_H
