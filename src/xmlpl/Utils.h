#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <list>
#include <vector>
#include <cctype>
#include <string.h>

namespace xmlpl {
  class Utils {
  public:
    static std::string removeSuffix(std::string filename);
    static std::string changeSuffix(std::string filename, std::string suffix);
    static void argsFromCommand(std::list<std::string> &args);
    static void runCommand(std::list<std::string> &args);
    static std::string getEnvVar(const std::string var, const std::string defaultValue);
  };

  struct IsSpacePred {
    inline static bool match(char c) {return std::isspace(c);}
  };

  template <char T = ' '>
  struct IsCharPred {
    inline static bool match(char c) {return c == T;}
  };

  template <char a, char b, char c = b, char d = c>
  struct OneOfPred {
    inline static bool match(char x) {return x == a || x == b || x == c || x == d;}
  };

  
  template <class T>
  inline void tokenize(std::vector<std::string> &result, const std::string &str) {
    unsigned int i;
    unsigned int len = str.length();

    for (i = 0; i < len; i++) {
      while (i < len && T::match(str[i])) i++;
      
      unsigned int end = i;
      while (end < len && !T::match(str[end])) end++;	
      
      if (i < end) result.push_back(str.substr(i, end - i + 1));
      i = end;
    }
  }
};
#endif // UTILS_H
