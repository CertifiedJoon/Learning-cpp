#include <map>
#include <string>
#include <iostream>
#include <set>
#include <cctype>
#include <algorithm>

using namespace std;

void reformat(string& word);

int main()
{
    map<string, size_t> wordc;
    set<string> exclude {"the", "a", "but", "and", "or", "an", "the"};
    string word;

    while(cin >> word)
    {
        reformat(word);
        if (exclude.find(word) == exclude.end())
            ++wordc[word];
    }

    for (const auto & w : wordc)
    {
        cout << w.first << " occurs " << w.second  << " time"<< ((w.second & 1) ? "s \n" : "s\n");
    }
}

void reformat (string &word)
{
    while(!isalpha(word.back()))
        word.pop_back();

    for_each(word.begin(), word.end(),
                [](char &c){c = tolower(c);}); 
}


