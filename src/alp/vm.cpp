#include "alp/vm.hpp"

namespace alp {
  VM::Libs::Libs(VM &vm): abc(vm) {}

  VM::VM(): libs(*this) {}

  Sym &VM::sym(const string_view &name) {
    auto [i, ok] = syms.emplace(name, nullptr);
    if (!ok) { return *i->second; }
    return *(i->second = sym_alloc.get());
  }

  Val *VM::val(Type &type, any imp) { return val_pool.make(type, imp); }

  void VM::push(Val *val) { stack.push_back(val); }

  Val *VM::push(Type &type, any imp) {
    Val *v = val(type, imp);
    push(v);
    return v;
  }

  Val *VM::peek() { return stack.empty() ? nullptr : stack.back(); }

  Val *VM::pop() {
    if (stack.empty()) { return nullptr; }
    Val *v = stack.back();
    stack.pop_back();
    return v;
  }
}
