#ifndef BUILDER_H
#define BUILDER_H

#include <string>
#include <list>

namespace xmlpl {
  class Builder {
  public:
		virtual ~Builder() {}

    virtual void buildStandalone(std::string input, std::string output,
				 std::list<std::string> &buildArgs,
				 std::list<std::string> &linkArgs) = 0;
    
    virtual void buildLibrary(std::string input, std::string output,
			      std::list<std::string> &buildArgs,
			      std::list<std::string> &linkArgs) = 0;
  };
};
#endif // BUILDER_H
