#ifndef TYPEENTRY_H
#define TYPEENTRY_H

#include "EnvEntry.h"

class TypeEntry : public EnvEntry {
  const unsigned int type;

public:
  TypeEntry(const Name &name, const unsigned int type, const Location &location,
	    const unsigned int depth) :
    EnvEntry(name, location, depth), type(type) {}
  virtual ~TypeEntry() {}

  virtual const unsigned int getType() const {return type;}

  virtual int getEntryType() const {return TYPE_ENTRY;}
  virtual std::string toString() const;
};
#endif // TYPEENTRY_H
