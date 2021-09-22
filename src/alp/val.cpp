#include "alp/type.hpp"
#include "alp/val.hpp"
#include "alp/vm.hpp"

namespace alp {
  void Val::ref(VM &vm) {
    if (type->ref_val) { type->ref_val(*this, vm); }
  }

  void Val::deref(VM &vm) {
    if (type->deref_val) { type->deref_val(*this, vm); }
  }

  void Val::dealloc(VM &vm) {
    if (type->deref_val) { type->deref_val(*this, vm); }
    vm.val_pool.put(this);
  }

  void Val::dump(ostream &out) const {
    assert(type->dump_val);
    type->dump_val(*this, out);
  }

  ostream &operator <<(ostream &out, const Val &val) {
    val.dump(out);
    return out;
  }
}
