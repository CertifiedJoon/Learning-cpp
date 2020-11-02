#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
    ifstream fread(argv[1]);
    string s;
    vector<string> v;
    
    while(getline(fread, s)){
        v.push_back(s);
    }

    for (auto &line : v)
        cout << line << endl;
}