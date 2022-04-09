// obtaining file size
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    streampos begin, end;
    ifstream myfile("test.txt", ios::binary);
    begin = myfile.tellg();
    myfile.seekg(0, ios::end);
    end = myfile.tellg();
    myfile.close();
    cout << "size of test.txt: " << (end - begin) << " bytes.\n";

    ifstream myfile1("test.txt.comp", ios::binary);
    begin = myfile1.tellg();
    myfile1.seekg(0, ios::end);
    end = myfile1.tellg();
    myfile1.close();
    cout << "size of test.txt.comp: " << (end - begin) << " bytes.\n";

    ifstream myfile2("test.txt.comp.plaintext", ios::binary);
    begin = myfile2.tellg();
    myfile2.seekg(0, ios::end);
    end = myfile2.tellg();
    myfile2.close();
    cout << "size of test.txt.comp.plaintext: " << (end - begin) << " bytes.\n";
    return 0;
}
