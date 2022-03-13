#include "tree.hh"

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



std::string
path_to(tree_ptr_t tree, key_type key)
{
    if (!tree)
    {
        return "no";
    }
    if (tree -> key_ == key)
    {
        return "yes";
    }

    if ((path_to(tree -> left_, key) == "no") && (path_to(tree -> right_, key) == "no"))
    {
        return "no";
    }

    return "no";

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

