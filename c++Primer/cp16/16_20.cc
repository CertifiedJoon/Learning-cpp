#include <vector>
#include <map>
#include <set>
#include <iostream>

template <typename T> void print_container(std::ostream &os, const T &c)
{
    for (auto it = c.begin(); it != c.end(); ++it)
        os << *it << std::endl;
}

    

int main()
{
    std::vector<int> v {1,2,3,4,5,6,7,8,9};
    std::map<int, int> m {{1,-1}, {2,-2}, {3,-3}};
    std::multiset<int> s {3,4,5,3,6,2,4};

    print_container(std::cout, s);   
}