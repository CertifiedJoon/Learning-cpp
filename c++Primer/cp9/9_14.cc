#include <vector>
#include <string>
#include <list>
#include <iostream>

using namespace std;

int main(){
    list<char*> l {("i fucking").c_str(), ("love it").c_str(), ("work like").c_str(), ("you are insanely").c_str(), ("proud of yourself").c_str()};
    vector<string> v;
    v.assign(l.begin(), l.end());
}