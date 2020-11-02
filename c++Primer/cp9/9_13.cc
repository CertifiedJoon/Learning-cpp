#include <vector>
#include <list>
#include <iostream>
using namespace std;

int main(){
    vector<int> i {1,23,4,5,6,3,4324,1};
    list<int> l {1,23,5467,68,79,4,1};

    vector<double> d (l.begin(),l.end());

    for (const auto val : d)
        cout << val << endl;
}