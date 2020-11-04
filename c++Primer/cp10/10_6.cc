#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;

int main()
{
    vector<int> v; list<int> lst; int i;

    while(cin >> i)
    {
        lst.push_back(i);
    }

    copy(lst.begin(), lst.end(), back_inserter(v));

    for (auto i : v)
        cout << i;
}