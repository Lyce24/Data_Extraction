// Name of program mainreturn.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "huffman.hh"
#include "bitio.hh"
using namespace std;

int decode_symbol(Huffman& huff, const Huffman::bits_t& bits)
{
  int symbol = -1;

  for (auto b : bits) {
    symbol = huff.decode(b);
  }
  return symbol;
}

int main(int argc, char **argv)
{
    // std::stringstream bits;
    ifstream input_file; // indata is like cin
    std::vector<char> bytes;
    std::vector<Huffman::bits_t> complete_bit;
    Huffman::bits_t bits;
    string byte;
    Huffman huff;

    int num; // variable for input value

    for (int i = 1; i < argc; ++i)
    {
        input_file.open(argv[i]); // opens the file

        const char *new_file = argv[i];
        const char *more = ".plaintext";
        std::string fullname = new_file;      
        fullname += more;
        const char* actually_name = fullname.c_str();
        std::ofstream outfile(actually_name);

        if (input_file.is_open())
        {
            while (getline(input_file, byte))
            {
                for (std::string::size_type i = 0; i < byte.size(); i++)
                {
                    if (byte[i] == '1')
                    {
                        bits.push_back(1);
                    }
                    else
                    {
                        bits.push_back(0);
                    }
                    
                }
                complete_bit.push_back(bits);
                bits.clear();
            }
            for (int i = 0; i < complete_bit.size(); i++)
            {
                char c = decode_symbol(huff, complete_bit[i]);
                outfile << c;
            }
            // for (const auto &i : bytes)
            // {
            //     cout << i;
            // }
            // cout << endl;
            input_file.close();
            outfile.close();
        }
        // const char *new_file = argv[i];
        // const char *more = ".comp";
        // std::string fullname = new_file;
        // fullname += more;
        // const char* actually_name = fullname.c_str();
        // std::ofstream outfile(actually_name);

        // vector<char> bytes;
        // char byte = 0;
        // if (!indata)
        // { // file couldn't be opened
        //     cerr << "Error: file could not be opened" << endl;
        //     exit(1);
        // }
        // while (indata.get(byte))
        // {
        //     bytes.push_back(byte);
        // }

        // for (const auto &i : bytes)
        // {
        //     for (const auto &e : hfm.encode(i)) outfile << e << "\n";
        // }

        // // for (const auto &i : bytes) {
        // //     bits.put(i) ;
        // // }

        // // BitInput biti(bits);
        // // while (bits.eof() != 1)
        // // {

        // // }

        // indata.close();
        // outfile.close();
    }
    return 0;
}