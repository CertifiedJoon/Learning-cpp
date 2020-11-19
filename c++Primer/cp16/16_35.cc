#include <iostream>


template<typename T> void calc(T v1, T v2){
    std::cout << v1 + v2 << std::endl;
}

int main()
{
    char c = 'l';
    double d = 3.123;
    float f = 1.2;
    calc(d, f);
}