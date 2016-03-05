#ifndef CPPBUILDER_H
#define CPPBUILDER_H

#include <xmlpl/Builder.h>

namespace xmlpl {
  class CppBuilder : public Builder {
    std::string CXX;
    std::string LIBTOOL;
    std::string RM;

  public:
    CppBuilder();
    virtual ~CppBuilder() {}

    virtual void buildStandalone(std::string input, std::string output,
				 std::list<std::string> &buildArgs,
				 std::list<std::string> &linkArgs);
    
    virtual void buildLibrary(std::string input, std::string output,
			      std::list<std::string> &buildArgs,
			      std::list<std::string> &linkArgs);

    virtual std::string buildObject(std::string input, std::list<std::string> &buildArgs);

    virtual void clean(std::string input);

    void addImportedLibraries(std::list<std::string> &args);
  };
};
#endif // CPPBUILDER_H
