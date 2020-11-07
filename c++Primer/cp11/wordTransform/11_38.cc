#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;
int main()
{
    unordered_map<string, size_t> wordc;
    string word;
    while (cin >> word)
        ++wordc[word];

    cout << "Bucket count" << wordc.bucket_count() << endl;
    cout << "max_bucket_count" << wordc.max_bucket_count() << endl;

    for (const auto &w : wordc)
        cout << w.first  << " : " << w.second << endl;
}