#include "tree.hh"
#include <iostream>


using namespace std;

int main()
{
    tree_ptr_t leaf1 = create_tree(9,0,nullptr,nullptr);
    tree_ptr_t root1 = create_tree(6,0,leaf1, nullptr);
    tree_ptr_t leaf2 = create_tree(12,0, nullptr, nullptr);
    tree_ptr_t root2 = create_tree(-5,0, leaf2, root1);
    tree_ptr_t leaf3 = create_tree(3,0,nullptr,nullptr);
    tree_ptr_t root4 = create_tree(12,0,leaf3, nullptr);
    tree_ptr_t root_top = create_tree(126,0,root2,root4);

    // string test = path_to(root_top,12);

    tree_ptr_t should_be_6 = node_at(root_top, "LR");
    tree_ptr_t should_be_9 = node_at(root_top, "LRL");
    tree_ptr_t should_be_null = node_at(root_top, "LRLRS");
    tree_ptr_t should_be_nullptr = node_at(root_top,"LLR");

    // cout << test << endl;
    cout << should_be_6 ->key_ << endl;
    cout << should_be_9 ->key_ << endl;
    cout << (should_be_null == nullptr) <<endl;
    cout << (should_be_nullptr == nullptr) <<endl;

    destroy_tree(root_top);
    
    return 0;
}
