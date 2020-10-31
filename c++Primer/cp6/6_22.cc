#include <iostream>

using namespace std;

void swapp(const int **p, const int **q);

int main(){
    int i = 1, j = 4;
    const int *m = &i, *n = &j;

    swapp(&m, &n);
    cout << i << " " << j << endl;
    cout << *m << " " << *n << endl;
}

void swapp(const int **p, const int **q){
    const int *temp = *p;
    *p = *q;
    *q = temp;
}
