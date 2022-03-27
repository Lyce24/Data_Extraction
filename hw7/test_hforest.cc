// Eriksen Liu

#include "hforest.hh"
#include <iostream>
#include <cassert>

// create different trees with different values and keys
HTree::tree_ptr_t create_test_tree()
{
  
  auto leaf12 = make_shared<HTree>(12, 1);
  auto leaf_5 = make_shared<HTree>(-5,1,leaf12,nullptr);
  return leaf_5;
}

HTree::tree_ptr_t create_test_tree1()
{
  
  auto leaf12 = make_shared<HTree>(12, 1);
  auto leaf_5 = make_shared<HTree>(-6,6,leaf12,nullptr);
  return leaf_5;
}

HTree::tree_ptr_t create_test_tree2()
{
  
  auto leaf12 = make_shared<HTree>(12, 1);
  auto leaf_5 = make_shared<HTree>(6,213,leaf12,nullptr);
  return leaf_5;
}

HTree::tree_ptr_t create_test_tree3()
{
  
  auto leaf12 = make_shared<HTree>(12, 1);
  auto leaf_5 = make_shared<HTree>(10,23,leaf12,nullptr);
  return leaf_5;
}


int main()
{
    auto root = create_test_tree2();
    auto root3 = create_test_tree1();   
    auto root1 = create_test_tree();
    auto root2 = create_test_tree3();   

    // create a class example to test the forest
    HForest test_forest; 
    
    // print out the orginal size of the forest, should be 0
    cout << "original size of the forest: " << test_forest.size() << endl; 

    // add some trees in the forest
    test_forest.add_tree(root);
    test_forest.add_tree(root3);
    test_forest.add_tree(root1);
    test_forest.add_tree(root2);    

    cout << "size of the forest after adding 4 trees: " << test_forest.size() << endl;

    // print out every value of every tree in the forest, should be (213 6 1 23)
    cout << "Output of every value of every tree in the forest: ";
    for (auto tree = test_forest.forest_vector.begin(); tree != test_forest.forest_vector.end(); ++tree)
        cout << (*tree) -> get_value() << " ";
    cout << "" << endl;

    // now pop every tree in the forest
    for (int i = 0; i < 4; i++)
    {
      cout << "pop the tree with lowest value: " << test_forest.pop_tree() -> get_value() << endl;
    }
    
    // after 4 times, there is no more trees in the forest, so the pop_tree() function should return nullptr
    cout << "equal to nullptr? " << (test_forest.pop_tree() == nullptr) << endl;
    cout << "size of the final forest: " << test_forest.size() << endl;
    
    return 0; 
}