#ifndef ALP_SYM_HPP
#define ALP_SYM_HPP

#include <string>

namespace alp {
  using namespace std;
  
  struct Sym {
    Sym(const string_view &name);
    const string name;
  };
}

#endif
