#include "alp/sym.hpp"
#include "alp/type.hpp"

namespace alp {
  Type::Type(const Sym &name): name(name) {}

  Type::~Type() {}

  void Type::dealloc(VM &vm) { delete this; }
}
