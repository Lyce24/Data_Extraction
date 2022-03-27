#include "date.hh"
#include <cassert>

//////////////////////////////////////////////////////////////////////////////
Date::Date(unsigned y, unsigned m, unsigned d)
  : y_(y), m_(m), d_(d)
{
  assert(is_valid());
}

//////////////////////////////////////////////////////////////////////////////
bool Date::is_valid() const
{
  if (d_ < 1 || d_ > 31) {
    return false;
  }
  if (m_ < 1 || m_ > 12) {
    return false;
  }
  if (y_ < -5000 || y_ > 5000) {
    return false;
  }
  // check for leap year problems...

  return true;
}
