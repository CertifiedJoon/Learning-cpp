#include <iostream>
#include <string>

using namespace std;

int main(){
    string prev, word;
    unsigned maxCount = 0, count = 0;
    string res;

    while(cin >> word){
        if (prev == word){
            ++count;
        } else {
            count = 0;
        }

        if (count > maxCount){
            res = word;
            maxCount = count;
        }

        prev = word;
    }

    cout << res << endl;
}
