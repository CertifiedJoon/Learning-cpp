#include <iostream>
#include <string>

using namespace std;

int main(){
    string hexdigits("0123456789ABCDEF");

    string result;
    char n;

    while(cin >> n){
        if (n < hexdigits.size())
            result += hexdigits[n];
    }

    cout << result <<endl;

    cout << s1;

    return 0;
}
