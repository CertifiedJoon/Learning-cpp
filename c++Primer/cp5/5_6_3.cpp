#include <iostream>
#include <stdexcept>

using namespace std;

int main(){
    int i , j;
    while (cin >> i >> j){
        try{
            if (j == 0)
                throw runtime_error("Division by zero");
            cout << static_cast<double>(i) / j;

        } catch(runtime_error err){
            cout << err.what()
                 << "\nTry again? y or n\n";
            char c = 'n';
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }
}
