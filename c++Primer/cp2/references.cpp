#include <iostream>
using namespace std;

int main(){
    int i, &r1 = i;

    i = 5;

    cout << i << " " << r1;
}
