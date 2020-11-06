#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;

void print(const pair<string, vector<pair<string,string>>> &nb);
void print_pair(const pair<string, string> &p);

int main()
{
    map<string, vector<pair<string, string>>> family;
    string fam, name, bday;
    
    while (cin >> fam && cin >> name && cin >> bday)
    {
        family[fam].emplace_back(name, bday);
        cin.clear();
    }

    for_each(family.begin(), family.end(), print);
}

void print (const pair<string,vector<pair<string, string>>> &names){
    cout << names.first << " family\n";
    for_each((names.second).begin(), (names.second).end(), print_pair);
    cout << endl;
}

void print_pair(const pair<string, string> &p){
    cout << p.first << " : " << p.second << endl;
}