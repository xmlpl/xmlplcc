#ifndef TYPETABLES_H
#define TYPETABLES_H
/*
 * This file was generated from XmlPLTypeTables.sxc
 *   via the Standard.OutputCode.Main macro.
 */


#include <xmlpl/cpp/runtime/TypeID.h>

class TypeTables : public xmlpl::TypeID {
/*
 * This table is formated as follows:
 *   If TO and FROM are the respective cast types
 *   Then getCastable(FROM, TO) is one of the following values:
 *     - 0 indicating the cast is invalid
 *     - 1 indicating the cast is valid
 *     - A type (e.g. NODE_TYPE) indicating the cast is valid, but must the FROM type must
 *       first be cast to the returned type.  Note you must continue to lookup the returned
 *       type until a 1 is returned to find the complete chain of required casts.
 */
private:
  static unsigned char castableTable[55][55];
public:
  static unsigned int lookupCastable(const unsigned int row, const unsigned int column);

/*
 * Lookups in the following tables return:
 *   - 0 indicating the operator is invalid for the argument types
 *   - A type indicating the operator is valid for the argument types when both are
 *     cast to the returned type.
 */
private:
  static unsigned char equalityTable[55][55];
public:
  static unsigned int lookupEquality(const unsigned int row, const unsigned int column);

private:
  static unsigned char comparisonTable[23][23];
public:
  static unsigned int lookupComparison(const unsigned int row, const unsigned int column);

private:
  static unsigned char bitTable[23][23];
public:
  static unsigned int lookupBit(const unsigned int row, const unsigned int column);

private:
  static unsigned char arithmeticTable[23][23];
public:
  static unsigned int lookupArithmetic(const unsigned int row, const unsigned int column);

private:
  static unsigned char plusTable[23][23];
public:
  static unsigned int lookupPlus(const unsigned int row, const unsigned int column);

};
#endif // TYPETABLES_H
