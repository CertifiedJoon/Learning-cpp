#include <iostream>
#include <vector>
#include <cstdlib>
#define NDEBUG
using namespace std;

using vit = vector<int>::iterator;

void print_recursive(vit beg, vit end);

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8};
    print_recursive(v.begin(), v.end());

    return EXIT_SUCCESS;
}

void print_recursive(vit beg, vit end){
    if (beg == end)
        return;

    cout << *beg << " ";
    #ifndef NDEBUG
    cout << end - beg << endl;
    #endif
    print_recursive(beg + 1, end);
}
