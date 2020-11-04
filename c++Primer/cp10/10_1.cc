#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
    vector<double> iv{1,2,3,4,5,6,7,8,9,1,2,2,1,1,1,2,3,4};
    string s ("harry potter and the prisoner or azekaban");

    double sum = accumulate(iv.cbegin(), iv.cend(), 0);
    cout << sum << endl;
}