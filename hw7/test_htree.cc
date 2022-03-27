// Eriksen Liu

/*
 * test_tree: A simple unit test for the Tree data structure.
 */

#include "htree.hh"
#include <iostream>

using namespace std;

/* Create an elaborate example test tree:
            126
           /   \
          /     \
        -5       12
        / \     /  \
      12   6   3    5
          /        /  \
         9        8    7
*/
HTree::tree_ptr_t create_test_tree()
{
  
  auto leaf9 = make_shared<HTree>(9, 1);
  auto leaf6 = make_shared<HTree>(6,2,leaf9, nullptr);
  auto leaf12 = make_shared<HTree>(12,3);
  auto leaf_5 = make_shared<HTree>(-5, 4, leaf12, leaf6);
  auto leaf8 = make_shared<HTree>(8,1,nullptr,nullptr);
  auto leaf7 = make_shared<HTree>(7,1,nullptr,nullptr);
  auto leaf5 = make_shared<HTree>(5,4, leaf8, leaf7);
  auto leaf3 = make_shared<HTree>(3, 4);
  auto leaf12_1 = make_shared<HTree>(12,3, leaf3, leaf5);
  auto leaf126 = make_shared<HTree>(126,2,leaf_5, leaf12_1);
  return leaf126;
}

int main()
{
  // create a test tree
  auto root = create_test_tree();

  // Check get_value() and get_key()
  cout << "Get the key of the root: " << root -> get_key() << endl;
  cout << "Get the value of the root: " << root -> get_value() << endl; 

  cout << "Get the key of the children to the left and then to the right: " << root -> get_child(HTree::Direction::LEFT) -> get_child(HTree::Direction::RIGHT) -> get_key() << endl;
  cout << "Get the key of the children to the right and then to the right and then to the left: " << root ->get_child(HTree::Direction::RIGHT) -> get_child(HTree::Direction::RIGHT) ->get_child(HTree::Direction::LEFT) -> get_key() << endl;
  
  // Check the path to node 12, 8, 9, and 1231
  auto path_12 = root -> path_to(12);
  HTree::path_t lst_to_12 ({HTree::Direction::LEFT, HTree::Direction::LEFT});
  cout << "Result for path to node 12 (equals to LL?): " << (*path_12 == lst_to_12) << endl;

  auto path_8 = root -> path_to(8);
  HTree::path_t lst_to_8 ({HTree::Direction::RIGHT, HTree::Direction::RIGHT, HTree::Direction::LEFT});
  cout << "Result for path to node 8 (equals to RRL?): " << (*path_8 == lst_to_8) << endl;

  auto path_9 = root -> path_to(9);
  HTree::path_t lst_to_9 ({HTree::Direction::LEFT,HTree::Direction::RIGHT, HTree::Direction::LEFT});
  cout << "Result for path to node 9 (equals to LRL?): " << (*path_9 == lst_to_9) << endl;

  auto path_1231 = root ->path_to(1231);
  cout << "Result for path to node 1231 (equals to nullptr?): " << (path_1231 == nullptr) << endl;

  return 0;
}

