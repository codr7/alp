#ifndef ALP_LIBS_ABC
#define ALP_LIBS_ABC

#include "alp/type.hpp"

namespace alp {
  struct VM;
}

namespace alp::libs {
  using namespace alp;

  struct ABC {
    using IntType = TType<int>;
    
    ABC(VM &vm);

    IntType &int_type;
  };
}

#endif
