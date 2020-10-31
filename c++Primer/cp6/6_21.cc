#include <iostream>

using namespace std;

int larger(const int i, const int *j);

int main(){
    int j = 3;

    cout << larger(2, &j);

}

int larger(int i, const int *j){
    return i > *j ? i : *j;
}
