#ifndef ALP_POS_HPP
#define ALP_POS_HPP

#include  <string>

namespace alp {
  using namespace std;
  
  struct Pos {
    Pos(const string_view source = "n/a", int row = -1, int col = -1);

    string source;
    int row, col;
  };
}

#endif
