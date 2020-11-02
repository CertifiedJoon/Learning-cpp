#include <forward_list>
#include <iostream>

using namespace std;

int main(){
    forward_list<int> fl;
    for (int i = 0; i < 10; ++i){
        fl.push_front(i);
    }

    auto prev = fl.before_begin();
    auto current = fl.begin();

    while (current != fl.end()){
        if (*current & 1)
            current = fl.erase_after(prev);
        else{
            prev = current;
            ++current;
        }
    }

    for (auto i : fl){
        cout << i << endl;
    }
}