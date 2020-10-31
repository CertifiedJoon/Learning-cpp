#include <iostream>
#include "chapter6.h"
using namespace std;

unsigned factorial_of (unsigned i){
    if (i < 2)
    return 1;

    return i * factorial_of(i-1);
}

void factorial_calc(){
    int i = 0;

    while (cin >> i){
        try {
            if (i < 0)
            throw runtime_error("Factorial of negative number does not exist");

            cout << "factorial of " << i << ": " << factorial_of(i) << endl;
        } catch (runtime_error err){
            cout << err.what()
            << "\nTry again? y or n\n";

            char c = 'n';
            cin >> c;

            if(!c || c == 'n')
            break;
        }
    }
}
