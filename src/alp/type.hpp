#ifndef ALP_TYPE_HPP
#define ALP_TYPE_HPP

namespace alp {
  struct Sym;
  
  struct Type {
    Type(const Sym &name);
    const Sym &name;
  };
}

#endif
