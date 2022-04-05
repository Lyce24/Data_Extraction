// Name of program mainreturn.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

int main(int argc, char **argv)
{
    // std::stringstream bits;
    ifstream input_file; // indata is like cin
    vector<char> bytes;
    char byte = 0;

    int num; // variable for input value
    for (int i = 1; i < argc; ++i)
    {
        input_file.open(argv[i]); // opens the file
        while (input_file.get(byte))
        {
            bytes.push_back(byte);
        }
        for (const auto &i : bytes)
        {
            cout << i;
        }

        input_file.close();

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