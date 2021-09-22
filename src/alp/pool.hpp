#ifndef ALP_POOL_HPP
#define ALP_POOL_HPP

#include "alp/alloc.hpp"

namespace alp {
  using namespace std;
  
  template <typename T, size_t N>
  struct Pool: Alloc<T, N> {
    T *get() override {
      if (free.empty()) { return Alloc<T, N>::get(); }
      T *t = free.back();
      free.pop_back();
      return t;
    }

    void put(T *t) { free.push_back(t); }

    void destroy(T *t) {
      t->~T();
      put(t);
    }
    
    vector<T *> free;
  };
}

#endif
