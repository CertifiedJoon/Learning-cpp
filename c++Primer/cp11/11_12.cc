#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<pair<string, int>> si;
    
    string s;
    int i;

    while(cin >> s && cin >> i)
        si.push_back({s, i});

    for_each(si.begin(), si.end(), 
    [](const pair<string, int> &p) {cout << p.first << ":" << p.second << endl;});
}