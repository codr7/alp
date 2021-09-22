#include <ostream>
#include "alp/stack.hpp"
#include "alp/val.hpp"

namespace alp {
  void dump(const Stack &stack, ostream &out) {
    out << '[';

    for (auto i = stack.begin(); i != stack.end(); i++) {
      if (i != stack.begin()) { out << ' '; }
      (*i)->dump(out);
    }
    
    out << ']';
  }
  
  ostream &operator <<(ostream &out, const Stack &stack) {
    dump(stack, out);
    return out;
  }
}
