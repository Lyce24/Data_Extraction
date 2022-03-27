// Eriksen Liu

#include "tree.hh"

using namespace std;

//////////////////////////////////////////////////////////////////////////////
tree_ptr_t
create_tree(const key_type& key,
            const value_type& value,
            tree_ptr_t left,
            tree_ptr_t right)
{
    tree_ptr_t lst = new Tree({key, value, left,right});  //make a new tree as a pointer which connects to given right and left branches
    return lst;   //return the new tree
}


//////////////////////////////////////////////////////////////////////////////
void
destroy_tree(tree_ptr_t tree)        //delete the tree from left to right
{
    if (!tree)    //base case for recursion (if the tree right now is nullptr, just return nothing and stop the recursion 
    {
        return;
    }
    destroy_tree(tree->left_);       //go to left branch
    destroy_tree(tree->right_);      //go to right branch
    delete tree;                     //delete the current branch (if both its branches are nullptr)
}



// //////////////////////////////////////////////////////////////////////////////

std::string
path_to(tree_ptr_t tree, key_type key)
{   
    if (tree)
    {
        if (tree -> key_ == key)  //if the key of the current tree == key, then that's the base case for recursion
        {
            return "";            //add nothing to the path
        }
        else  //recursion: go to left, add "L" to the path, till the left_ is nullptr, and then go to right, do the same thing.
        {
            if (path_to(tree-> left_, key) != "-")
            {
                return "L" + path_to(tree-> left_, key);
            }
            if (path_to(tree-> right_, key) != "-")
            {
                return "R" + path_to(tree-> right_, key);
            }
            else     //if both branches from the current branch are nullptr, then return "-", if all the searches can't find the value.
            {
                return "-";
            }
        }
    }
    else
    {
        return "-";   //if !tree, then return "-" like in delete_tree
    }
}

/*

if (!tree)
{
    return "-";
}

if (!tree -> ket_ ==key)
{
    return "";
}

const auto left_res = path_to(tree -> left_,key);
if (left_res != "-")
{
    return "L" + left_res;
}
const auto right_res = path_to(tree -> right_, key)
if (right_res == "-")
{
    return "-";
}
else
{
    return "R"  + right_res;
}

*/




// //////////////////////////////////////////////////////////////////////////////
tree_ptr_t
node_at(tree_ptr_t tree, std::string path)
{
    int N = path.length();           //set N as the length of the string given
    for (int i = 0; i < N; i++)      //check every character of the string in a while loop
    {
        if (path[i] != 'L')          //if the character is not L - either R or other string)
        {
            if (path[i] != 'R')      //if other sting, then right the nullptr
            {
                return nullptr;    
            }
            else
            {                     
                if (tree -> right_)  //if R, then check the right branch of current branch, if it's nullptr, then return nullptr
                {
                    tree = tree -> right_;  //if the right branch exists, then go to that branch
                }
                else
                {
                    return nullptr;
                }
            }
        }
        else
        {
            if (path[i] != 'L')    //do the same thing in opposite direction (L direction)
            {
                return nullptr;
            }
            else
            {
                if (tree->left_)
                {
                    tree = tree -> left_;
                }
                else
                {
                    return nullptr;
                }
            }
        }
    }
    return tree;   //return the current branch
}

/*
for (auto c : path){
    if (!tree)  return nullptr;
    if (c == "L")   tree = tree -> left_;
    else if (c == "R")  tree = tree -> right_;
    else    return nullptr;
}

*/