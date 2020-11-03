#include <string>
#include <iostream>
using namespace std;

int main(){

    string s("ab2c3d7R4E6");
    string alphabets("qwertyuiopasdfghjklzxcvbnmQWERPASDFGHJKLZXCVBNM");
    string digits("1234567890");

    string::size_type pos = 0;
    string extracted_a;
    string extracted_d;

    while ((pos = s.find_first_not_of(digits, pos)) != string::npos){
        extracted_a.push_back(s[pos]);
        ++pos;
    }
    pos = 0;
    while ((pos = s.find_first_not_of(alphabets, pos)) != string::npos){
        extracted_d.push_back(s[pos]);
        ++pos;
    }
    cout << extracted_a << " " << extracted_d << endl;
}