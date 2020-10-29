#include <vector>
#include <string>
#include <iostream>
#include <cctype>

using namespace std;
int main(){
    int i;
    vector<int> v;

    while(cin >> i)
        v.push_back(i);

    for(auto b = v.cbegin(), e = v.cend() - 1; b != v.end() && e != v.begin(); b++,e--)
        cout << *b + *e << endl;
}
