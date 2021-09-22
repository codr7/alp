#include "alp/libs/abc.hpp"
#include "alp/type.hpp"
#include "alp/vm.hpp"

#include <ostream>

namespace alp::libs {
  ABC::ABC(VM &vm): int_type(*vm.type_alloc.make(vm.sym("Int"))) {
    int_type.dump_val = [](const Val &val, ostream &out) { out << val.as<int>(); };
  }  
}
