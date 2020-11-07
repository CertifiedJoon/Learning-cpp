#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    map<string, int> wordc;
    string word;

    while (cin >> word)
    {
        auto ret = wordc.insert(make_pair(word, 1));
        if (!ret.second)
            ++ret.first->second;
    }
}