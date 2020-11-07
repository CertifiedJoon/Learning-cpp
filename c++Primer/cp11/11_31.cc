#include <map>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;
void print_pair(const pair<string, string> &p);
bool alphabetical(const pair<string, string> &p, const pair<string, string> &q);
void sort_print(multimap<string,string> m);
int main()
{
    multimap<string, string> authorNBook {{"Conan Doyle", "Sherlock Holmes and study of pink"},
                                          {"J.K Rolling", "Harry potter and half blood prince"},
                                          {"Jordan Peterson", "12 rules for life"},
                                          {"Charles Dickens", "A christmas carol"}};

    sort_print(authorNBook);
}

void print_pair (const pair<string, string> &p)
{
    cout << p.first << " : " << p.second << endl;
}

void sort_print (multimap<string,string> m)
{
    while (!m.empty()){
        auto ret = m.lower_bound("A");
        print_pair(*ret);
        m.erase(ret);
    }
}


bool alphabetical (const pair<string, string> &p, const pair<string, string> &q)
{
    return (p.first < q.first) ? true : false; 
}