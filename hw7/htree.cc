/*
 * HTree: a class to represent a tree node with two values: a key
 * and a value.
 */

#include "htree.hh"

// Return an optional list of directions from root to a node of a given key.
// If key not contained in this tree, returns nullptr

HTree::HTree(key_t key,
             value_t value,
             tree_ptr_t left,
             tree_ptr_t right)
:key_(key), value_(value), left_(left), right_(right)
{}

HTree::key_t
HTree::get_key() const
{
  return key_;
}

HTree::value_t
HTree::get_value() const
{
  return value_;
}

HTree::tree_ptr_t
HTree::get_child(Direction dir) const
{
  if (dir == Direction::LEFT)
  {
    if (!left_)
    {
      return nullptr;
    }
    else
    {
      return left_;
    }
  }
  else
  {
    if (!right_)
    {
      return nullptr;
    }
    else
    {
      return right_;
    }
  }
}


HTree::possible_path_t
HTree::path_to(key_t key) const
{
  possible_path_t path(new path_t()); //{} - empty list
  if (key_ == key)
  {
    return path;
  }
  else
  {
    auto left_case = left_->path_to(key);
    if (left_case != nullptr)
    {
      left_case -> push_front(Direction::LEFT);
      return left_case;
    }
    auto right_case = right_->path_to(key);
    if (right_case != nullptr)
    {
      right_case -> push_front(Direction::RIGHT);
      return right_case;
    }
    else
    {
      return nullptr;
    }
  }
  return nullptr;
}
