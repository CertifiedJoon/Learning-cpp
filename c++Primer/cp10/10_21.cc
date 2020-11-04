#include <iostream>

using namespace std;

int main()
{
    int i = 10;

    auto f = [i] () mutable
                {return (--i != 0);};

    while(f());

    cout << f() << endl;
}