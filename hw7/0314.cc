#include <iostream>

using namespace std;

class  Example
{
public:
     int num_;
     int swapper(int newval)
     {
         int old = num_;
         num_ = newval;
         return old;
     }
};

int main(){
    Example e;
    e.num_ = 5;
    std::cout << e.num_;
}
