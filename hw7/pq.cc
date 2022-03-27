#include "pq.hh"

#include <algorithm>
#include <cassert>
#include <climits>

void
PQueue::push_element(elem_t elem)
{
  elems_.push_back(elem);
}

PQueue::elem_t
PQueue::pop_element()
{
  assert(!elems_.empty() && "Can't call pop_element with an empty queue!");

  int max_elem = INT_MIN;
  for (auto e : elems_) {
    if (e > max_elem) {
      max_elem = e;
    }
  }

  // Remove and erase max_elem from elems_:
  elems_.erase(std::remove(elems_.begin(), elems_.end(), max_elem));

  return max_elem;
}

