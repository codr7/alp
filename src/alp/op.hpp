#ifndef ALP_OP_HPP
#define ALP_OP_HPP

#include "alp/form.hpp"
#include "alp/types.hpp"

namespace alp {
  using namespace std;

  struct VM;
  
  struct Op {
    Op(Form &form);
    virtual PC eval(VM &vm) = 0;

    Form &form;
  };
}

#endif
