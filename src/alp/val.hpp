#ifndef ALP_VAL_HPP
#define ALP_VAL_HPP

#include  <any>
#include "alp/ref.hpp"

namespace alp {
  using namespace std;

  struct Type;
  
  template <typename T>
  struct TType;
  
  struct Val: Ref {
    template <typename T>
    Val(TType<T> &type, const T& imp): type(&type), imp(imp) {}
    
    template <typename T>
    T &as() { return any_cast<T &>(imp); }

    template <typename T>
    const T &as() const { return any_cast<const T &>(imp); }

    void dealloc(VM &vm) override;
    void dump(ostream &out) const;

    Type *type;
    any imp;
  };

  ostream &operator <<(ostream &out, const Val &val);
}

#endif
