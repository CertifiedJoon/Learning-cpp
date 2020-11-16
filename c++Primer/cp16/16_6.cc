#include <iostream>

template<unsigned N, typename T>
T* begin(T (&arr)[N])
{
    return arr;
}

template<unsigned N, typename T>
T* end(T (&arr)[N])
{
    return arr + N - 1;
}

int main()
{
    int arr[] ={1,2,3,4,5,6,7,6,5};
    std::cout << *end(arr) << std::endl;
}