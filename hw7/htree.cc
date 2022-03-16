/*
 * HTree: a class to represent a tree node with two values: a key
 * and a value.
 */

#include "htree.hh"

// Return an optional list of directions from root to a node of a given key.
// If key not contained in this tree, returns nullptr

HTree::HTree(key_t key,
             value_t value,
             tree_ptr_t left = nullptr,
             tree_ptr_t right = nullptr)
{
  key_ = key;
  value_ = value;
  left_ = left;
  right_ = right;
}

HTree::possible_path_t
HTree::path_to(key_t key) const
{
  return nullptr;
}


// Return the child of this node indicated by dir.
// If the child is nullptr (current node is a leaf), returns nullptr.
HTree::tree_ptr_t 
HTree::get_child(Direction dir) const
{
  return nullptr;
}