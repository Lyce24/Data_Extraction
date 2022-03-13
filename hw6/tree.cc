#include "tree.hh"
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////////////
tree_ptr_t
create_tree(const key_type& key,
            const value_type& value,
            tree_ptr_t left,
            tree_ptr_t right)
{
    tree_ptr_t lst = new Tree({key, value, left,right});
    return lst;
}


//////////////////////////////////////////////////////////////////////////////
void
destroy_tree(tree_ptr_t tree)
{
    if (!tree)
    {
        return;
    }
    destroy_tree(tree->left_);
    destroy_tree(tree->right_);
    delete tree;
}



// //////////////////////////////////////////////////////////////////////////////
bool result = false;

std::string
path_to(tree_ptr_t tree, key_type key)
{   
    std::string path = "";
    if (!tree)
    {
        return "";
    }
    if (tree -> key_ == key)
    {
        result = true;
        return "";
    }    

    if (result == false)
    {
        // cout << tree -> key_ << endl;
        // cout << path << endl;
        path = "L" + path_to(tree-> left_, key);    
    } 
    else
    {
        return path;
    }


    if (result == false)
    {
        // cout << tree -> key_ << endl;
        // cout << path << endl;
        path = "R" + path_to(tree->right_,key);
    }

    if (result == false)
    {
        return "-";
    }
    return path;
}



// //////////////////////////////////////////////////////////////////////////////
tree_ptr_t
node_at(tree_ptr_t tree, std::string path)
{
    int N = path.length();
    for (int i = 0; i < N; i++)
    {
        if (path[i] != 'L')
        {
            if (path[i] != 'R')
            {
                return nullptr;
            }
            else
            {
                if (tree -> right_)
                {
                    tree = tree -> right_;
                }
                else
                {
                    return nullptr;
                }
            }
        }
        else
        {
            if (path[i] != 'L')
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
    return tree;
}

