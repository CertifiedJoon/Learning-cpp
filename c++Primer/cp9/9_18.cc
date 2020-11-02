#include <deque>
#include <string>
#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> ls;
    deque<int> even, odd;
    int s;

    while(cin >> s)
        ls.push_back(s);

    for (auto it = ls.begin(); it != ls.end(); ++it){
        if (*it & 1)
            odd.push_back(*it);
        else
            even.push_back(*it);
    }

    for (auto it = odd.begin(); it != odd.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    
    for (auto it = even.begin(); it != even.end(); ++it){
        cout << *it << " ";
    }

}