#ifndef ALP_TYPE_HPP
#define ALP_TYPE_HPP

#include <functional>
#include "alp/ref.hpp"
#include "alp/val.hpp"

namespace alp {
  using namespace std;

  struct Sym;
  struct Val;
  struct VM;
  
  struct Type: Ref {
    Type(const Sym &name);
    virtual ~Type();
    void dealloc(VM &vm) override;

    const Sym &name;
    function<void (Val &val, VM &vm)> deref_val;
    function<void (const Val &val, ostream &out)> dump_val;
    function<void (Val &val, VM &vm)> ref_val;
  };

  template <typename T>
  struct TType: Type {
    TType(const Sym &name): Type(name) {
      dump_val = [](const Val &val, ostream &out) { out << val.as<T>(); };
    }
  };
}

#endif
