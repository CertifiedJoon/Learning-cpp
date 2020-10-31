#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
    string s = "";
    ++argv;

    while(argc > 1){
        s += *argv;
        ++argv;
        --argc;
    }

    cout << s;
}
