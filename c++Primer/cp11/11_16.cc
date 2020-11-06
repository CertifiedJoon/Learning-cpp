#include <map>
#include <iostream>

using namespace std;

int main()
{
    int i;
    char c;
    map<char, int> ci;
    auto mit = ci.begin();
    
    cin >> c >> i;
    mit[c] = i;
    cout << mit->first << mit->second << endl;
}