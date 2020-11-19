#include <vector>
#include <map>
#include <set>
#include <iostream>

template <typename T> void print_container(std::ostream &os, const T &c)
{
    for (typename T::size_type i = 0; i != c.size(); ++i)
        os << c[i] << std::endl;
}



int main()
{
    std::vector<int> v {1,2,3,4,5,6,7,8,9};
    std::map<int, int> m {{1,-1}, {2,-2}, {3,-3}};
    std::set<int> s {3,4,5,3,6,2,4};

    print_container(std::cout, m);   
}