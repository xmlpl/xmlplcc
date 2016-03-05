#ifndef VARENTRY_H
#define VARENTRY_H

#include "EnvEntry.h"

class VarEntry : public EnvEntry {
  const unsigned int type;
  const bool constant;

public:
  VarEntry(const Name &name, const unsigned int type, const bool constant,
	   const Location &location, const unsigned int depth) :
    EnvEntry(name, location, depth), type(type), constant(constant) {}
  virtual ~VarEntry() {}

  virtual const unsigned int getType() const {return type;}
  virtual const bool isConstant() const {return constant;}

  virtual int getEntryType() const {return VAR_ENTRY;}
  virtual std::string toString() const;
};
#endif // VARENTRY_H
