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
    Huffman hfm;
    int num = 0; // variable for input value
    for (int i = 1; i < argc; ++i)
    {
        input_file.open(argv[i]); // opens the file        
             
        const char *new_file = argv[i];
        const char *more = ".comp";
        std::string fullname = new_file;      
        fullname += more;
        const char* actually_name = fullname.c_str();

        std::ofstream outfile(actually_name);
        BitOutput bito(outfile);
        vector<int> bytes; 
        char byte = 0;
        if (!input_file)
        { // file couldn't be opened
            cerr << "Error: file could not be opened" << endl;
            exit(1);
        }

        cout << "reading:";
        while (!input_file.eof())
        {
            byte = input_file.get();
            if (int(byte) == -1)
            {
                cout << byte;
                bytes.push_back(256);
            }
            else
            {
                cout << byte;
                bytes.push_back(int(byte));
            }
        }
        cout << endl;

        for (const auto &i : bytes)
        {
            cout << "encoding: " << i << endl;
            for (const auto &e : hfm.encode(i)) 
            {
                cout << e;
                bito.output_bit(e);
                num++;
            }
            cout << endl;
        }
        cout << "count: " << num << endl;
        bito.~BitOutput();
        input_file.close();
        outfile.close();
    }
    return 0;
}