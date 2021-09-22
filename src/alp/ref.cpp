#include <cassert>
#include "alp/ref.hpp"

namespace alp {
  Ref::Ref(size_t refs): refs(refs) {}

  bool Ref::deref(VM &vm) {
    assert(refs);
    if (--refs) { return false; }
    dealloc(vm);
    return true;
  }

}
