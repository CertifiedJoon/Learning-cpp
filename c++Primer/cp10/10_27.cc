#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <forward_list>
#include <deque>
#include <iterator>

using namespace std;

int main(){
    vector<int> v {1,2,3,4,5,6,7,8,9};
    string s;
    list<int> lst;
    forward_list<int> flist;
    deque<int> q;
    copy(v.begin(), v.end(), inserter(lst, lst.end()));

    for (auto it = lst.begin(); it != lst.end(); ++it){
        cout << *it << endl;
    }
}