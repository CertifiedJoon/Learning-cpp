#include <iostream>
#include <vector>

using namespace std;

int add(int i, int j){
    return i + j;
}

int subtract(int i, int j){
    return i - j;
}

int multiply(int i, int j){
    return i * j;
}

int divide(int i, int j){
    return i / j;
}

typedef decltype(divide) *arithmetics;

int main(){
    vector<arithmetics> ar = {add, subtract, multiply, divide};

    for (auto calc : ar)
        cout << calc(1,2) << endl;

    return 0;
}
