#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<char> v;
    v.reserve(100);

    for (int i = 0; i<100; ++i)
        v.push_back(i+48);

    string s(v.begin(), v.end());

    cout << s << endl;
}