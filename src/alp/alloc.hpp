#ifndef ALP_ALLOC_HPP
#define ALP_ALLOC_HPP

#include <memory>
#include <utility>
#include <vector>

namespace alp {
  using namespace std;
  
  template <typename T, size_t N>
  struct Alloc {
    struct Slab { typename aligned_storage<sizeof(T), alignof(T)>::type slots[N]; };
    
    Slab &push_slab() {
      n = 0;
      return *slabs.emplace_back(make_unique<Slab>());
    }

    virtual T *get() {
      Slab &s = (slabs.empty() || n == N) ? push_slab() : *slabs.back();
      return reinterpret_cast<T *>(&s.slots[n++]);
    }

    template <typename...Args>
    T *make(Args&&...args) { return new (get()) T(forward<Args>(args)...); }
    
    vector<unique_ptr<Slab>> slabs;
    size_t n = 0;
  };
}

#endif
