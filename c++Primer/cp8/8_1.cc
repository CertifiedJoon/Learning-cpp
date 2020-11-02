#include <iostream>
#include <string>
#include <sstream>
using namespace std;

istringstream& &read(istringstream& iss){
    string s;
    while (iss >> s)
        cout << s << endl;
    return iss;
}

int main(){
    read(cin);
}
