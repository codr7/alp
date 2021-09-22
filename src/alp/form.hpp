#ifndef ALP_FORM_HPP
#define ALP_FORM_HPP

#include "alp/pos.hpp"
#include "alp/ref.hpp"

namespace alp {
  using namespace std;
  
  struct Form: Ref {
    Form(Pos pos);
    virtual ~Form();
    virtual void dealloc(VM &vm) override;
    virtual void dump(ostream &out) const = 0;
    const Pos pos;
  };
}

#endif
