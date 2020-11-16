#include <iostream>
#include <list>
#include <string>
#include <vector>

template<class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& t)
{
    while (first != last)
    {
        if (*first == t) return first;
        ++first;
    }
    return last;
}

int main()
{
    std::vector<int> v{111,324,5436,2341,5,26,136,47};
    std::list<int> lst{1,23,25352,3634,62,123516,6245,45135166};

    std::cout << *find(lst.begin(), lst.end(), 62) <<std::endl;
}