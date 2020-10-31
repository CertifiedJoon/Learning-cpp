#include <iostream>
using namespace std;

void print (const int *beg, const int *end);
void print (const int *arr, size_t size);

int main(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int i = 2;
    print(&i, &i+1);
    print(&i, 1);
}

void print(const int *beg, const int *end){
    while (beg != end){
        cout << *beg << endl;
        ++beg;
    }
}

void print(const int *arr, size_t size){
    while(size){
        cout << *arr << endl;
        ++arr;
        --size;
    }
}
