#include <iostream>

using namespace std;

int main()
{   
    int j  = 0xA;
    auto f = [j](int i) 
                {return i + j;};
    cout << f(3) << endl;
}