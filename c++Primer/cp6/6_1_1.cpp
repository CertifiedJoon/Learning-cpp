#include <iostream>

using std::cout;
using std::endl;

unsigned count_calls(){
    static unsigned ctrl = 0;
    return ctrl++;
}

int main(){
    for (size_t i = 0; i < 10; ++i){
        cout << count_calls() << endl;
    }
}
