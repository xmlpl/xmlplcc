#include "Options.h"

#include <xmlpl/cpp/runtime/Functions.h>
#include "DefaultLibraryPath.h"

#include <stdlib.h>

using namespace xmlpl;
using namespace std;

Options *Options::instance = 0;

Options::Options() : useLineInfo(true), language(0),
		     verbosity(0), buildLibrary(false), saveTemps(false),
		     debugMode(false), dumpCore(false) {
  addToLibraryPath(DEFAULT_LIBRARY_PATH);

  const char *path = getenv("XMLPL_LIBRARY_PATH");
  if (path) addToLibraryPath(path);
}


void Options::setLibraryPath(const string path) {
  libraryPath.clear();
  addToLibraryPath(path);
}

void Options::addToLibraryPath(const string path) {
  vector<string> tokens = tokenize(path, ":");
  
  vector<string>::iterator it;
  for (it = tokens.begin(); it != tokens.end(); it++)
    libraryPath.push_back(*it);
}
