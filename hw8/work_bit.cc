// Name of program mainreturn.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include "huffman.hh"
#include "bitio.hh"

using namespace std;

int main(int argc, char **argv)
{
    // std::stringstream bits;
    ifstream input_file; // indata is like cin
    Huffman huff;
    int symbol;
    for (int i = 1; i < argc; ++i)
    {
        input_file.open(argv[i]); // opens the file
        const char *new_file = argv[i];
        const char *more = ".plaintext";
        std::string fullname = new_file;      
        fullname += more;
        const char* actually_name = fullname.c_str();
        std::ofstream outfile(actually_name);

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
                outfile.put(symbol);
                }
                symbol = -1;
            }
        }
        cout << endl;
    }
    return 0;
}
