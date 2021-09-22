#ifndef ALP_VAL_HPP
#define ALP_VAL_HPP

#include  <any>
#include "alp/ref.hpp"

namespace alp {
  using namespace std;
  
  struct Type;
  
  struct Val: Ref {
    Val(Type &type);
    
    template <typename T>
    T &get() { return any_cast<T>(imp); }

    void dealloc(VM &vm) override;
    void dump(ostream &out);

    Type &type;
    any imp;
  };
}

#endif
