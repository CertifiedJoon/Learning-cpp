#include <iostream>

template<unsigned u, typename T>
std::ostream& print(std::ostream& os, const T (&arr)[u])
{
    for (unsigned i = 0; i != u; ++i)
        os << arr[i] << " ";
    
    return os;
}

int main()
{
    int arr[] = {1,4,5,2,3,5,2,36};
    print(std::cout, arr);
}