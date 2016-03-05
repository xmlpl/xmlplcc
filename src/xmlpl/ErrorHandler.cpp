#include "ErrorHandler.h"

using namespace std;

ErrorHandler *ErrorHandler::instance = 0;

ErrorHandler::ErrorHandler() : out(&cerr), errors(0), warnings(0), debugFlags(0) {
}

void ErrorHandler::setDebugFlags(string flags) {
  if (flags == "import") setDebugFlags(DEBUG_IMPORT);
  else if (flags == "all") setDebugFlags(DEBUG_ALL);
}

void ErrorHandler::error(const string msg, const Location &location) {
  getInstance()->_error(msg, location);
}

void ErrorHandler::warning(const string msg, const Location &location) {
  getInstance()->_warning(msg, location);
}

void ErrorHandler::debug(const unsigned int flags, const string msg,
			 const Location &location) {
  getInstance()->_debug(flags, msg, location);
}

void ErrorHandler::_error(const string msg, const Location &location) {
  errors++;
  printLocation(location);
  *out << "error: " << msg << endl;
}

void ErrorHandler::_warning(const string msg, const Location &location) {
  warnings++;
  printLocation(location);
  *out << "warning: " << msg << endl;
}

void ErrorHandler::_debug(const unsigned int flags, const string msg,
			  const Location &location) {
  if ((debugFlags & flags) == flags) {
    printLocation(location);
    *out << "debug: " << msg << endl;
  }
}

void ErrorHandler::printLocation(const Location &location) const {
  if (location.filename != "") *out << location.filename << ":";
  else if (defaultLocation.filename != "") *out << defaultLocation.filename << ":";
  
  if (location.line) {
    *out << location.line << ":";
    if (location.column) *out << location.column << ":";
    *out << " ";

  } else if (defaultLocation.line) {
    *out << defaultLocation.line << ":";
    if (defaultLocation.column) *out << defaultLocation.column << ":";
    *out << " ";
  }
}
