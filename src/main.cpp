#include <iostream>
#include "alp/vm.hpp"

using namespace std;
using namespace alp;

int main() {
  cout << "Welcome to Alp v1" << endl;

  VM vm;
  
  Val *v = vm.push(vm.libs.abc.int_type, 42);
  cout << "Val: ";
  v->dump(cout);
  cout << endl;
  
  return 0;
}
