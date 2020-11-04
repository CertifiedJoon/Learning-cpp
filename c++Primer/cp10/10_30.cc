#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    istream_iterator<int> in(cin), eof;
    vector<int> v (in, eof);
    sort(v.begin(), v.end());
    unique_copy(v.begin(), v.end(), ostream_iterator<int> (cout, " "));
}