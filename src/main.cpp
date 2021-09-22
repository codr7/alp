#include <iostream>
#include "alp/val.hpp"
#include "alp/vm.hpp"

using namespace std;
using namespace alp;

int main() {
  cout << "Welcome to Alp v1" << endl;

  VM vm;
  
  vm.push(vm.libs.abc.int_type, 42);
  cout << vm.stack << endl;
  
  return 0;
}
