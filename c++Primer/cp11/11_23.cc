#include <map>
#include <string>
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_pair (const pair<string,vector<string>> &p);

int main()
{
    multimap<string, vector<string>> families;
    string family;

    while (cin >> family)
    {
        cout << "Enter yo kids names: " << endl;
        istream_iterator<string> in(cin), eof;
        families.insert(make_pair(family, vector<string>(in, eof)));
        cin.clear();
    }

    for_each(families.begin(), families.end(), print_pair);
}

void print_pair (const pair<string,vector<string>> &p)
{
    ostream_iterator<string> out(cout, " ");
    cout << p.first << " Family: \n";
    copy(p.second.begin(), p.second.end(), out);
    cout << endl;
}