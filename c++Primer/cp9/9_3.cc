#include <iostream>
#include <vector>

using namespace std;

using vit = vector<int>::iterator;

vit has(vit beg, vit end, const int i){
    while(beg != end){
        if (*beg == i)
            return beg;
        ++beg;
    }
    return end;
}

int main(){
    vector<int> v{1,2,3,4,4,5,6,7,8,9,10};
    if (has(v.begin(), v.end(), 11) == v.end())
        cout << "not found\n";
    else
        cout << "found\n";
}