#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
using vit = vector<string>::iterator;

void elimDups(vector<string> &strings);

void three_way_radix_sort(vector<string> &strings, string::size_type lo, 
                          string::size_type hi, string::size_type d);

void swap(vector<string> &strings, string::size_type i, string::size_type j);

int main()
{
    vector<string> books {"mobydick", "twenty-thousand leagues under sea", "sherlock holmes", "to kill a mockingbird", "the great gatsby",
                        "the catcher in the rye", "war and peace", "animal farm", "gulliver's travels", "little woman", "mobydick"};
    elimDups(books);
    
    for (auto s : books)
        cout << s << endl;
}

void elimDups(vector<string> &strings){
    three_way_radix_sort(strings, 0, strings.size()-1, 0);
    auto end_unique = unique(strings.begin(), strings.end());

    strings.erase(end_unique, strings.end());
}

void three_way_radix_sort (vector<string> &strings, string::size_type lo,
                           string::size_type hi, string::size_type d){
    if (lo >= hi)
        return;

    int lt = lo;
    int gt = hi;
    
    int v = strings[lo][d];
    int i = lo + 1;
    
    while (i <= gt)
    {
        int t = strings[i][d];
        if (t < v) swap(strings, lt++, i++);
        else if (t > v) swap(strings, gt--, i);
        else ++i;
    }

    three_way_radix_sort(strings, lo, lt - 1, d);
    if (gt > lt) three_way_radix_sort(strings, lt, gt, d + 1);
    three_way_radix_sort(strings, gt+1, hi, d);
}

void swap(vector<string> &strings, string::size_type i, string::size_type j){
    string temp = strings[i];
    strings[i] = strings[j];
    strings[j] = temp;
}