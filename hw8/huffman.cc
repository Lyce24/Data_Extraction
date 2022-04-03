#include "huffman.hh"
#include <iostream>

HTree::tree_ptr_t combine_leaf(int val, int key, HTree::tree_ptr_t left, HTree::tree_ptr_t right)
{
    auto leaf = make_shared<HTree>(val, key, left, right);
    return leaf;
}

Huffman::Huffman()
{
    for (int i = 0; i < Huffman::ALPHABET_SIZE - 1; i++)
        Huffman::frequency_table.push_back(0);
    Huffman::frequency_table.push_back(1);
    return;
}

HTree::tree_ptr_t Huffman::create_tree()
{
    for (int i = 0; i < Huffman::ALPHABET_SIZE; i++)
    {
        HTree::tree_ptr_t leaf = combine_leaf(i, Huffman::frequency_table[i], nullptr, nullptr);
        Huffman::huffman_forest.add_tree(leaf);
    }

    while (Huffman::huffman_forest.size() != 1)
    {
        HTree::tree_ptr_t leaf1 = Huffman::huffman_forest.pop_tree();
        int value1 = leaf1->get_value();
        HTree::tree_ptr_t leaf2 = Huffman::huffman_forest.pop_tree();
        int value2 = leaf2->get_value();
        int value = value1 + value2;
        HTree::tree_ptr_t leaf3 = combine_leaf(-1, value, leaf1, leaf2);
        Huffman::huffman_forest.add_tree(leaf3);
    }
    auto result = Huffman::huffman_forest.pop_tree();
    return result;
}

Huffman::bits_t Huffman::encode(int symbol)
{
    HTree::tree_ptr_t tree = create_tree();
    auto path = tree->path_to(symbol);
    Huffman::bits_t result;
    auto path_front = (*(path)).begin();
    for (path_front; path_front != (*(path)).end(); path_front++)
    {
        if (*path_front == HTree::Direction::LEFT)
        {
            result.push_back(0);
        }
        else
        {
            result.push_back(1);
        }
    }
    Huffman::frequency_table[symbol]++;
    return result;
}

int Huffman::decode(bool bits)
{  
    if (Huffman::huffman_forest.size() == 0)
    {  
        HTree::tree_ptr_t tree = create_tree();
        if (bits == 0)
        {
            auto left = Huffman::huffman_forest.forest_vector.front() -> get_child(HTree::Direction::LEFT);
            if (left->get_key() < 0)
            {
                Huffman::huffman_forest.pop_tree();
                Huffman::huffman_forest.add_tree(left);
                return -1;
            }
            else
            {
                auto result = left->get_key();
                huffman_forest.pop_tree();
                Huffman::frequency_table[result]++;
                return result;
            }
        }
        else
        {
            auto right = Huffman::huffman_forest.forest_vector.front() -> get_child(HTree::Direction::RIGHT);
            if (right->get_key() < 0)
            {
                Huffman::huffman_forest.pop_tree();
                Huffman::huffman_forest.add_tree(right);
                return -1;
            }
            else
            {
                auto result = right->get_key();
                huffman_forest.pop_tree();
                Huffman::frequency_table[result]++;
                return result;
            }
        }
    }
    else
    {
        if (bits == 0)
        {
            auto left = Huffman::huffman_forest.forest_vector.front() -> get_child(HTree::Direction::LEFT);
            if (left->get_key() < 0)
            {
                Huffman::huffman_forest.pop_tree();
                Huffman::huffman_forest.add_tree(left);
                return -1;
            }
            else
            {
                auto result = left->get_key();
                huffman_forest.pop_tree();
                Huffman::frequency_table[result]++;
                return result;
            }
        }
        else
        {
            auto right = Huffman::huffman_forest.forest_vector.front() -> get_child(HTree::Direction::RIGHT);
            if (right->get_key() < 0)
            {
                Huffman::huffman_forest.pop_tree();
                Huffman::huffman_forest.add_tree(right);
                return -1;
            }
            else
            {
                auto result = right->get_key();
                huffman_forest.pop_tree();
                Huffman::frequency_table[result]++;
                return result;
            }
        }
    }
    return 3;
}


