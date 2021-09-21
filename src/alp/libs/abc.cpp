#include "alp/libs/abc.hpp"
#include "alp/type.hpp"
#include "alp/vm.hpp"

namespace alp::libs {
  ABC::ABC(VM &vm): int_type(vm.type_alloc.make(vm.sym("Int"))) {}
}
