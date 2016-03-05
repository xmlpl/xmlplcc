#ifndef TARGETTYPEFLAGS_H
#define TARGETTYPEFLAGS_H

#include <xmlpl/cpp/runtime/TypeID.h>

class TargetTypeFlags : public xmlpl::TypeID {
public:
  enum {
    APPEND_FLAG     = 256,
    COUNT_FLAG      = 512,
    BREAK_FLAG      = 1024,
    CONTINUE_FLAG   = 2048,
    RETURN_FLAG     = 4096,

    LOOP_FLAGS      = CONTINUE_FLAG | BREAK_FLAG,
    STATEMENT_FLAGS = LOOP_FLAGS | RETURN_FLAG,
    FLAGS_MASK      = APPEND_FLAG | COUNT_FLAG |
    BREAK_FLAG | CONTINUE_FLAG | RETURN_FLAG
  };
};
#endif // TARGETTYPEFLAGS_H
