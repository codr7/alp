#ifndef ALP_LIBS_ABC
#define ALP_LIBS_ABC

#include "alp/stack.hpp"
#include "alp/type.hpp"

namespace alp {
  struct VM;
}

namespace alp::libs {
  using namespace alp;

  struct ABC {
    using IntType = TType<int>;
    using StackType = TType<Stack>;
    ABC(VM &vm);

    IntType &int_type;
    StackType &stack_type;
  };
}

#endif
