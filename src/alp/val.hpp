#ifndef ALP_VAL_HPP
#define ALP_VAL_HPP

#include  <any>

namespace alp {
  using namespace std;

  struct Type;
  
  template <typename T>
  struct TType;

  struct VM;
  
  struct Val {
    template <typename T>
    Val(TType<T> &type, const T& imp): type(&type), imp(imp) {}

    Val(const Val &);
    
    template <typename T>
    T &as() { return any_cast<T &>(imp); }

    template <typename T>
    const T &as() const { return any_cast<const T &>(imp); }

    void ref(VM &vm);
    void deref(VM &vm);
    void dealloc(VM &vm);
    
    void dump(ostream &out) const;

    Type *type;
    any imp;
  };

  ostream &operator <<(ostream &out, const Val &val);
}

#endif
