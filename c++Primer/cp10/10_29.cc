#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main(){
    ifstream fin("input.txt");
    istream_iterator<string> itin(fin);
    istream_iterator<string> eof;

    vector<string> v (itin, eof);

    ostream_iterator<string> itout(cout, " ");
    copy(v.begin(), v.end(), itout);
    cout << endl;
}