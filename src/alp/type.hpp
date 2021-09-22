#ifndef ALP_TYPE_HPP
#define ALP_TYPE_HPP

#include <functional>

namespace alp {
  using namespace std;

  struct Sym;
  struct Val;
  
  struct Type {
    Type(const Sym &name);

    const Sym &name;
    function<void (Val &val)> dealloc_val;
    function<void (const Val &val, ostream &out)> dump_val;
  };
}

#endif
