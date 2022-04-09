#include "huffman.hh"
#include <iostream>

HTree::tree_ptr_t initialize_tree(int val, int key, HTree::tree_ptr_t left, HTree::tree_ptr_t right);

Huffman::Huffman()
{
    for (int i = 0; i < 3; i++)
        Huffman::frequency_table.push_back(0);
    Huffman::frequency_table.push_back(1);
    return;
}


HTree::tree_ptr_t Huffman::create_forest()
{
    for (int i = 0; i < 4; i++)
    {
        HTree::tree_ptr_t leaf = initialize_tree(i,Huffman::frequency_table[i], nullptr,nullptr);
        Huffman::huffman_forest.add_tree(leaf);    
    }

    while (Huffman::huffman_forest.size() != 1)
    {
        cout << Huffman::huffman_forest.size() <<endl;
        HTree::tree_ptr_t leaf1 = Huffman::huffman_forest.pop_tree();
        int value1 = leaf1 -> get_value();
        cout << "value for leaf1:" << value1 << endl;
        cout << "key for leaf1:" << leaf1->get_key() << endl;
        HTree::tree_ptr_t leaf2 = Huffman::huffman_forest.pop_tree();
        int value2 = leaf2 -> get_value();
        cout << "value for leaf2:" << value2 << endl;
        cout << "key for leaf2:" << leaf2->get_key() << endl;
        int value = value1 + value2;
        HTree::tree_ptr_t leaf3 = initialize_tree(-1, value, leaf1, leaf2);
        cout << "value for leaf3:" << leaf3 -> get_value() << endl;
        cout << "key for leaf3:" << leaf3->get_key() << endl;
        Huffman::huffman_forest.add_tree(leaf3);    
    }
    auto result = Huffman::huffman_forest.pop_tree();
    return result;
}


Huffman::bits_t Huffman::encode(int symbol)
{
    HTree::tree_ptr_t tree = create_forest();
    auto path = tree -> path_to(symbol);
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
    Huffman::frequency_table[symbol] ++;
    return result;
}

int Huffman::decode(bool bits)
{
    return 0;
}


HTree::tree_ptr_t initialize_tree(int val, int key, HTree::tree_ptr_t left, HTree::tree_ptr_t right)
{
    auto leaf = make_shared<HTree>(val,key, left, right);
    return leaf;
}