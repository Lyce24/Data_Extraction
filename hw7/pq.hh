
#pragma once

#include <vector>

class PQueue {
 public:
  using elem_t = int;

  PQueue() = default;
  ~PQueue() = default;

  void push_element(elem_t elem);

  elem_t pop_element();

 private:
  std::vector<elem_t> elems_;
};

