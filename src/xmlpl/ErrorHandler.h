#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <string>
#include <iostream>

#include "Location.h"

class ErrorHandler {
  std::ostream *out;

  unsigned int errors;
  unsigned int warnings;
  Location defaultLocation;

  unsigned int debugFlags;

  static ErrorHandler *instance;
  
  ErrorHandler();

public:
  static const unsigned int DEBUG_IMPORT = 256;
  static const unsigned int DEBUG_ALL    = ~0;

  void setDebugFlags(std::string flags);
  void setDebugFlags(unsigned int flags) {debugFlags |= flags;}
  void clearDebugFlags(unsigned int flags) {debugFlags &= ~flags;}

  void setFilename(std::string filename) {defaultLocation.filename = filename;}
  const std::string getFilename() const {return defaultLocation.filename;}
  
  unsigned int getErrors() const {return errors;}
  unsigned int getWarnings() const {return warnings;}
  void reset() {
    errors = warnings = 0;
    defaultLocation = Location();
  }

  static void setOutputStream(std::ostream &out) {getInstance()->out = &out;}
  static void error(const std::string msg, const Location &location = Location());
  static void warning(const std::string msg, const Location &location = Location());
  static void debug(const unsigned int flags, const std::string msg,
		    const Location &location = Location());

  static void setDefaults(unsigned int line, unsigned int column) {
    getInstance()->defaultLocation.line = line;
    getInstance()->defaultLocation.column = column;
  }
  static void clearDefaults() {setDefaults(0, 0);}

  static ErrorHandler *getInstance() {
    if (!instance) instance = new ErrorHandler();
    return instance;
  }

protected:
  void _error(const std::string msg, const Location &location);
  void _warning(const std::string msg, const Location &location);
  void _debug(const unsigned int flags, const std::string msg, const Location &location);
  void printLocation(const Location &location) const;
};
#endif // ERRORHANDLER_H
