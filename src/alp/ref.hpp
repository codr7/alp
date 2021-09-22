#ifndef ALP_REF_HPP
#define ALP_REF_HPP

#include <cstddef>

namespace alp {
  struct VM;
  
  struct Ref {
    Ref(size_t refs = 1);
    bool deref(VM &vm);
    virtual void dealloc(VM &vm) = 0;

    size_t refs;
  };

  template <typename T>
  T &ref(T &r) {
    r.refs++;
    return r;
  }
}

#endif
