#include "LibraryImporter.h"
#include "ErrorHandler.h"

using namespace std;
using namespace xmlpl;


bool LibraryImporter::addLibrary(const string &library, const string &ns) {
  libraries_t::iterator it = libraries.find(ns);

  if (it != libraries.end()) {
    if (it->second != library) {
      ErrorHandler::error("Cannot import library '" + library +
			  "' with same namespace as '" + it->second + "'");
      return false;
    }

    return true;
  }

  libraries[ns] = library;
  return true;
}
