#include "alp/form.hpp"

namespace alp {
  Form::Form(Pos pos): pos(pos) {}

  Form::~Form() {}

  void Form::dealloc(VM &vm) { delete this; }
}
