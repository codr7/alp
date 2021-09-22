#ifndef ALP_VM_HPP
#define ALP_VM_HPP

#include <unordered_map>

#include "alp/libs/abc.hpp"
#include "alp/pool.hpp"
#include "alp/sym.hpp"
#include "alp/type.hpp"
#include "alp/types.hpp"
#include "alp/val.hpp"

namespace alp {
  using namespace std;
    
  struct VM {
    struct Libs {
      Libs(VM &vm);
      libs::ABC abc;
    };
      
    static const size_t SLAB_SIZE = 1024;

    VM();
    
    Sym &sym(const string_view &name);

    template <typename T>
    Val *val(TType<T> &type, const T &imp) { return val_pool.make(type, imp); }
  
    Val *push(Val *val);

    template <typename T>
    Val *push(TType<T> &type, const T &imp) { return push(val(type, imp)); }

    Val *peek();
    Val *pop();
    
    Alloc<Sym, SLAB_SIZE> sym_alloc;
    Pool<Val, SLAB_SIZE> val_pool;

    unordered_map<string, Sym *> syms;
    Libs libs;
    Stack stack;
  };
}

#endif
