#include <iostream>
#include "alp/pool.hpp"

using namespace std;

int main() {
  cout << "Welcome to Alp v1" << endl;

  alp::Pool<int, 1024> a;
  
  return 0;
}
