#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool capital_in (const string &s);
void string_tolower (string &s);

int main(){
    string s;
    cin >> s;
    cout << capital_in("i am your father") << endl;
    string_tolower(s);
    cout << s << endl;
}

bool capital_in (const string &s){
    for (auto &c: s){
        if (isupper(c))
            return 1;
    }
    return 0;
}

void string_tolower(string &s){
    for (auto &c : s)
        c = tolower(c);
}
