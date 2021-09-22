#ifndef ALP_STACK_HPP
#define ALP_STACK_HPP

#include <vector>

namespace alp {
  using namespace std;

  struct Val;
  
  using Stack = vector<Val *>;

  void dump(const Stack &stack, ostream &out);
  ostream &operator <<(ostream &out, const Stack &stack);
}

#endif
