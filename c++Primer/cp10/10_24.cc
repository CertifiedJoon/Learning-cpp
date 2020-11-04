#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using namespace placeholders;

bool greater_than(int i, const string &j){
    return i > j.size();
}

int main()
{
    vector<int> v;
    int i;
    string s;
    cin >> s;
    while (cin >> i)
        v.push_back(i);

    auto end = find_if(v.begin(), v.end(), bind(greater_than, _1, s));

    cout << *end << endl;
}