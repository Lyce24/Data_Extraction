#include "huffman.hh"
#include <iostream>

int decode_symbol(Huffman &huff, const Huffman::bits_t &bits)
{
    int symbol = -1;

    for (auto b : bits)
    {
        symbol = huff.decode(b);
    }
    return symbol;
}

//////////////////////////////////////////////////////////////////////////////
// Ensure decoding returns the same symbol that was encoded, in different
// scenarios.
int main()
{
    Huffman huff;
    int symbol;
    int i = 0;

    Huffman::bits_t test = {0, 1, 0, 0, 0, 1, 0, 0, 0, 1};
    while (true)
    {
        symbol = huff.decode(test[i]);
        if (symbol == Huffman::HEOF)
        {
            break;
        }
        else
        {
            cout << symbol << endl;
            symbol = -1;
            i++;
        }
    }
    return 0;
}