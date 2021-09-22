#ifndef ALP_VM_HPP
#define ALP_VM_HPP

#include <unordered_map>

#include "alp/libs/abc.hpp"
#include "alp/pool.hpp"
#include "alp/sym.hpp"
#include "alp/type.hpp"
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
    Val *val(Type &type, any imp);
  
    void push(Val *val);
    Val *push(Type &type, any imp);
    Val *peek();
    Val *pop();
    
    Alloc<Sym, SLAB_SIZE> sym_alloc;
    Alloc<Type, SLAB_SIZE> type_alloc;
    Pool<Val, SLAB_SIZE> val_pool;

    unordered_map<string, Sym *> syms;
    Libs libs;
    vector<Val *> stack;
  };
}

#endif
