#include <string>
#include <iostream>

using namespace std;

string& replace_instances_of(string &s, const string& prefix, const string& suffix){
    s.insert(0, prefix);
    s.insert(s.size(), suffix);

    return s;
}

int main(){
    string t("Neymar");
    cout << replace_instances_of(t, "Mr. ", " Jr");
}