#include <iostream>
#include <initializer_list>

using namespace std;

int sum(initializer_list<int> list);

int main(){
    int i = 1, j = 4, k = 2, m = 8;

    cout << sum({1,2,3,4,5,6,7}) << endl;
}

int sum(initializer_list<int> list){
    int sum = 0;

    for (auto it = list.begin(); it != list.end(); ++it)
        sum += *it;

    return sum;
}
