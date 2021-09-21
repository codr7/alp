#ifndef ALP_LIBS_ABC
#define ALP_LIBS_ABC

namespace alp {
  struct Type;
  struct VM;
}

namespace alp::libs {
  using namespace alp;

  struct ABC {
    ABC(VM &vm);

    Type &int_type;
  };
}

#endif
