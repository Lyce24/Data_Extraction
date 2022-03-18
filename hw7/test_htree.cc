/*
 * test_tree: A simple unit test for the Tree data structure.
 */

#include "htree.hh"
#include <iostream>
#include <cassert>

using namespace std;

// Create an elaborate example test tree:
HTree::tree_ptr_t create_test_tree()
{
  
  auto leaf12 = make_shared<HTree>(12, 1);
  auto leaf_5 = make_shared<HTree>(-5,1,leaf12,nullptr);
  return leaf_5;
}

void test_htree(const HTree::tree_ptr_t root)
{
  assert(*(root->path_to(126)) == HTree::path_t({ }));
}

int main()
{
  auto root = create_test_tree();
  // test_htree(root);

  cout << root -> get_child(HTree::Direction::LEFT) -> get_key() << endl;
  auto path = root -> path_to(12);
  HTree::path_t lst({ HTree::Direction::LEFT });
  cout << (*path == lst) << endl;

  return 0;
}

