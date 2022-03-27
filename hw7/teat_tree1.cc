#include "htree.hh"
#include <iostream>

using namespace std;

int main()
{
    HTree tree1(1,2,nullptr,nullptr);
    HTree tree2(3,4,nullptr,tree1); 
}
