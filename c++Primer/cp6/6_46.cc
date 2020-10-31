#include <iostream>
#include <string>

using namespace std;

constexpr bool isShorter(const char *p,const char *q){
    for (; p && q; ++p, ++q);

    return (q);
}

int main(){
    string s = "1234";
    string l = "12345";

    cout << isShorter(s.c_str(), l.c_str());
}
