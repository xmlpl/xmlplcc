#include "Language.h"

#include <BasicUtils/BasicException.h>

using namespace xmlpl;
using namespace std;

Language::language_map_t Language::languageMap;

Language *Language::get(const std::string name) {
  language_map_t::iterator it = languageMap.find(name);

  if (it == languageMap.end()) {
    string str = "Invalid language " + name + ". Valid languages include: ";
    bool first = true;
    for (it = languageMap.begin(); it != languageMap.end(); it++) {
      if (first) first = false;
      else str += ", ";

      str += it->first;
    }

    str += ".";
    
    throw BasicException(str);
  }

  return it->second;
}

void Language::add(Language *language) {
  ASSERT_OR_THROW("Language cannot be null!", language);

  language_map_t::iterator it = languageMap.find(language->getName());

  ASSERT_OR_THROW(string("Language ") + language->getName() + " already registered!",
		  it == languageMap.end());

  languageMap[language->getName()] = language;
}
