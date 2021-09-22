#ifndef ALP_VAL_HPP
#define ALP_VAL_HPP

#include  <any>
#include "alp/ref.hpp"

namespace alp {
  using namespace std;
  
  struct Type;
  
  struct Val: Ref {
    Val(Type &type, any imp = nullptr);
    
    template <typename T>
    T &as() { return any_cast<T &>(imp); }

    template <typename T>
    const T &as() const { return any_cast<const T &>(imp); }

    void dealloc(VM &vm) override;
    void dump(ostream &out) const;

    Type &type;
    any imp;
  };
}

#endif
