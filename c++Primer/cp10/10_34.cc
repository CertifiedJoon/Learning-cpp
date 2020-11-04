#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

int main()
{
    list<int> lst {1,2,3,4,5,6,0,7,53};
    string s;
    for (auto it = lst.crbegin(); it != lst.crend(); ++it){
        s.append(to_string(*it));
        s.push_back();
    }
    cout << find(s.begin(), s.end(), '0');
}