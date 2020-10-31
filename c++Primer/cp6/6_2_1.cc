#include <iostream>

using namespace std;

void swap(const int &i, const int &j){
    i ^= j;
    j ^= i;
    i ^= j;
}

int main(){
    int m = -1, n = -11;

    swap(m,n);
    cout << m << " " << n << endl;
}
