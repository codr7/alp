#include "alp/type.hpp"
#include "alp/val.hpp"
#include "alp/vm.hpp"

namespace alp {
  Val::Val(Type &type, any imp): type(&type), imp(imp) {}

  void Val::dealloc(VM &vm) {
    if (type->dealloc_val) { type->dealloc_val(*this); }
    vm.val_pool.put(this);
  }

  void Val::dump(ostream &out) const {
    assert(type->dump_val);
    type->dump_val(*this, out);
  }
}
