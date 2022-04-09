// Name of program mainreturn.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "huffman.hh"
#include "bitio.hh"
using namespace std;

int main(int argc, char **argv)
{
    // std::stringstream bits;
    ifstream input_file; // indata is like cin
    std::vector<char> bytes;
    std::vector<Huffman::bits_t> complete_bit;
    Huffman::bits_t bits;
    string byte;
    Huffman huff;
    int symbol;

    int num; // variable for input value

    for (int i = 1; i < argc; ++i)
    {
        input_file.open(argv[i]); // opens the file

        // const char *new_file = argv[i];
        // const char *more = ".plaintext";
        // std::string fullname = new_file;
        // fullname += more;
        // const char *actually_name = fullname.c_str();
        // std::ofstream out(actually_name);

        BitInput bitio(input_file);
        if (input_file.is_open())
        {
            input_file.open(argv[i]); // opens the file
            BitInput biti(input_file);
            while (!(input_file.eof()))
            {
                symbol = huff.decode(biti.input_bit());
                if (symbol == Huffman::HEOF)
                {
                    break;
                }
                else
                {
                    if (symbol != -1)
                    {
                        cout << char(symbol);
                    }
                    symbol = -1;
                }
            }
            cout << endl;
        }
        input_file.close();
        // out.close();
    }       
    return 0;
}