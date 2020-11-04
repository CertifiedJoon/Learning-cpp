#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

void longer_than(vector<string> &s, vector<string>::size_type t);

int main()
{
    vector<string> vs;
    string s;
    int length;
    cin >> length;
    while(cin >> s)
        vs.push_back(s);

    longer_than(vs, length);
}

void longer_than(vector<string> &vs, vector<string>::size_type t){
    auto end_partition = partition(vs.begin(), vs.end(), [t](const string &s)
                                            {return (s.size() > t);});
    vs.erase(end_partition, vs.end());

    stable_sort(vs.begin(), vs.end());
    unique(vs.begin(), vs.end());

    for_each(vs.begin(), vs.end(), [](const string &s){
                                        cout << s << endl;});
}