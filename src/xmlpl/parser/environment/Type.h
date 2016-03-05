#ifndef TYPE_H
#define TYPE_H

#include <xmlpl/cpp/runtime/TypeID.h>

#include <string>
#include <vector>

class Environment;

namespace xmlpl {

  class Type : public TypeID {
  public:
    static unsigned int types[];

		virtual ~Type() {}
    
    virtual const std::string getName() const = 0;
    virtual unsigned int getID() const = 0;
    virtual const std::string getIDString() const = 0;
    virtual bool isPathType() const {return false;}
    virtual void declare(Environment &env);

    bool operator==(const Type &type) const {
      return getID() == type.getID();
    }
    
    bool operator!=(const Type &type) const {
      return getID() != type.getID();
    }
    
    static Type &get(const unsigned int typeID);

    static bool isNode(const unsigned int typeID)
    {return (typeID & NODE_FLAG) && !(typeID & SEQUENCE_FLAG);}
    static bool isSequence(const unsigned int typeID)
    {return typeID & SEQUENCE_FLAG;}
    static bool isIterator(const unsigned int typeID)
    {return typeID & ITERATOR_FLAG;}
    static bool isOStream(const unsigned int typeID)
    {return typeID & OSTREAM_FLAG;}
    static bool isNodeSeq(const unsigned int typeID)
    {return (typeID & NODE_FLAG) && (typeID && SEQUENCE_FLAG);}
    static unsigned int canCast(const unsigned int from, const unsigned int to);
    static bool canBe(const unsigned int type1, const unsigned int type2) {
      return type1 == type2 || canCast(type1, type2);
    }
  };
};
#endif // TYPE_H
