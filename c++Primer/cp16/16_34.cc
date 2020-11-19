#include <iostream>
#include <string>

template<typename T, typename U>
int compare(const T &v1, const U &v2){
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int main()
{
    std::cout << compare ("hi", "world") << std::endl;
}