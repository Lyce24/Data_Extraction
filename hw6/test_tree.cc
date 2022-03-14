#include "tree.hh"
#include "assert.h"
#include <iostream>


using namespace std;

int main()
{
    tree_ptr_t leaf1 = create_tree(9,0,nullptr,nullptr);
    tree_ptr_t leaf8 = create_tree(8,0,nullptr,nullptr);
    tree_ptr_t leaf7 = create_tree(7,0,nullptr,nullptr);
    tree_ptr_t root5 = create_tree(5,0,leaf8,leaf7);
    tree_ptr_t root1 = create_tree(6,0,leaf1, nullptr);
    tree_ptr_t leaf2 = create_tree(12,0, nullptr, nullptr);
    tree_ptr_t root2 = create_tree(-5,0, leaf2, root1);
    tree_ptr_t leaf3 = create_tree(3,0,nullptr,nullptr);
    tree_ptr_t root4 = create_tree(12,0,leaf3, root5);
    tree_ptr_t root_top = create_tree(126,0,root2,root4);

    // string path_to_8 = path_to(root_top,5);
    string path_to_12 = path_to(root_top,6);
    // string path_to_nonsense = path_to(root_top,1123);


    tree_ptr_t should_be_6 = node_at(root_top, "LR");
    tree_ptr_t should_be_9 = node_at(root_top, "LRL");
    tree_ptr_t should_be_null = node_at(root_top, "LRLRS");
    tree_ptr_t should_be_nullptr = node_at(root_top,"LLR");

    // cout << path_to_8 << endl;
    cout << path_to_12 << endl;
    // cout << path_to_nonsense << endl;

    // cout << should_be_6 ->key_ << endl;
    // cout << should_be_9 ->key_ << endl;
    // cout << (should_be_null == nullptr) <<endl;
    // cout << (should_be_nullptr == nullptr) <<endl;

    destroy_tree(root_top);
    
    return 0;
}
