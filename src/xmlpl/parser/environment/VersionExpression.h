#ifndef VERSIONEXPRESSION_H
#define VERSIONEXPRESSION_H

#include <xmlpl/cpp/runtime/Version.h>

class VersionExpression {
public:
	virtual ~VersionExpression() {}
  virtual bool matches(const xmlpl::Version &version) const = 0;
};

#endif // VERSIONEXPRESSION_H
