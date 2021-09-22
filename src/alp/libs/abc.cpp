#include "alp/libs/abc.hpp"
#include "alp/type.hpp"
#include "alp/vm.hpp"

#include <ostream>

namespace alp::libs {
  ABC::ABC(VM &vm):
    int_type(*new IntType(vm.sym("Int"))),
    stack_type(*new StackType(vm.sym("Stack"))) {      
      stack_type.deref_val = [](Val &val, VM &vm) {
	for (Val *v: val.as<Stack>()) { v->deref(vm); }
      };

      stack_type.ref_val = [](Val &val, VM &vm) {
	for (Val *v: val.as<Stack>()) { v->ref(vm); }
      };
  }  
}
