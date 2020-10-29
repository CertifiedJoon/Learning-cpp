#include <vector>
#include <iostream>

using namespace std;

int main(){
    unsigned int grade;
    vector<int> v(11,0);
    auto it = v.begin();

    while(cin >> grade){
        ++*(it + grade /10);
    }

    for (it = v.begin(); it != v.end(); it++){
        cout << *it <<endl;
    }
}
