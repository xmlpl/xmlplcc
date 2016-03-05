#ifndef LOCATION_H
#define LOCATION_H

#include <string>

class Location {
public:
  unsigned int line;
  unsigned int column;
  std::string filename;

  Location() : line(0), column(0) {}
  Location(const unsigned int line, const unsigned int column,
	   const std::string filename = "") : line(line), column(column),
					      filename(filename) {}
  Location(const Location &location) : line(location.line), column(location.column),
				       filename(location.filename) {}

  operator const std::string() const {return toString();}
  const std::string toString() const;
};
#endif // LOCATION_H
