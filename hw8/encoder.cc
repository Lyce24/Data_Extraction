// Name of program mainreturn.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include "huffman.hh"

using namespace std;

int main(int argc, char **argv)
{
    // std::stringstream bits;
    ifstream indata; // indata is like cin
    Huffman hfm;

    int num; // variable for input value
    for (int i = 1; i < argc; ++i)
    {
        indata.open(argv[i]); // opens the file        
             
        const char *new_file = argv[i];
        const char *more = ".comp";
        std::string fullname = new_file;      
        fullname += more;
        const char* actually_name = fullname.c_str();
        std::ofstream outfile(actually_name);
        
        vector<int> bytes; 
        char byte = 0;
        if (!indata)
        { // file couldn't be opened
            cerr << "Error: file could not be opened" << endl;
            exit(1);
        }
        while (indata.get(byte))
        {
            bytes.push_back(int(byte));
        }
        bytes.push_back(256);
        for (const auto &i : bytes)
        {
            for (const auto &e : hfm.encode(i)) 
            {
                outfile << e;
            }
            outfile << endl;
        }

        indata.close();
        outfile.close();
    }
    return 0;
}