#ifndef ALP_VAL_HPP
#define ALP_VAL_HPP

#include  <any>

namespace alp {
  using namespace std;
  
  struct Type;
  
  struct Val {
    Val(Type &type);
    
    template <typename T>
    T &get() { return any_cast<T>(imp); }

    Type &type;
    any imp;
  };
}

#endif
