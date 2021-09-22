#ifndef ALP_TYPE_HPP
#define ALP_TYPE_HPP

#include <functional>
#include "alp/ref.hpp"

namespace alp {
  using namespace std;

  struct Sym;
  struct Val;
  
  struct Type: Ref {
    Type(const Sym &name);
    virtual ~Type();
    void dealloc(VM &vm) override;

    const Sym &name;
    function<void (Val &val)> dealloc_val;
    function<void (const Val &val, ostream &out)> dump_val;
  };

  template <typename T>
  struct TType: Type {
    TType(const Sym &name): Type(name) {}
  };
}

#endif
