// Eriksen Liu

#include "tree.hh"
#include "assert.h"
#include <iostream>
#include <stdlib.h>


using namespace std;

int main()
{

    //create tree structure as,
/*
            126
           /   \
          /     \
        -5       12
        / \     /  \
      12   6   3    5
          /        /  \
         9        8    7
*/
    tree_ptr_t branch9 = create_tree(9,0,nullptr,nullptr);
    tree_ptr_t branch8 = create_tree(8,0,nullptr,nullptr);
    tree_ptr_t branch7 = create_tree(7,0,nullptr,nullptr);
    tree_ptr_t branch5 = create_tree(5,0,branch8,branch7);
    tree_ptr_t branch6 = create_tree(6,0,branch9, nullptr);
    tree_ptr_t branch12 = create_tree(12,0, nullptr, nullptr);
    tree_ptr_t branch_5 = create_tree(-5,0, branch12, branch6);
    tree_ptr_t branch3 = create_tree(3,0,nullptr,nullptr);
    tree_ptr_t branch12_1 = create_tree(12,0,branch3, branch5);
    tree_ptr_t root = create_tree(126,0,branch_5,branch12_1);

    //test for path_to function
    string path_to_8 = path_to(root,8);
    string path_to_12 = path_to(root,12);
    string path_to_nonsense = path_to(root,1123);

    //test for node_at
    tree_ptr_t should_be_6 = node_at(root, "LR");
    tree_ptr_t should_be_9 = node_at(root, "LRL");
    tree_ptr_t should_be_null = node_at(root, "LRLRS");
    tree_ptr_t should_be_nullptr = node_at(root,"LLR");

    //printing results
    cout << path_to_8 << endl;
    cout << path_to_12 << endl;
    cout << path_to_nonsense << endl;

    cout << should_be_6 ->key_ << endl;
    cout << should_be_9 ->key_ << endl;
    cout << (should_be_null == nullptr) <<endl;
    cout << (should_be_nullptr == nullptr) <<endl;


    //destory the regular tree and tree with loop;
    destroy_tree(root);

    return 0;
}
