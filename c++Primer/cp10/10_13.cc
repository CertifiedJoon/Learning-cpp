#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;
using namespace placeholders;
bool longer(int i, string::size_type t){
    return s.size() > t;
}


int main()
{
    vector<string> v;
    string s;
    string::size_type t;
    cin >> t;
    
    while (cin >> s){
        v.push_back(s);
    }

    auto end_partition = partition(v.begin(), v.end(), bind(longer, _1, t));

    v.erase(end_partition, v.end());

    for_each(v.begin(), v.end(), [](const string &s)
                                    {cout << s << endl;});
}   