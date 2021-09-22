#ifndef ALP_TYPES_HPP
#define ALP_TYPES_HPP

#include <cstddef>

namespace alp {
  struct Val;

  using PC = size_t;
  using Stack = vector<Val *>;
}

#endif
