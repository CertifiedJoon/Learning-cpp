#include <iostream>

int main(){
    int i = 2, j = 3;

    double d = static_cast<double> (j / i);

    std::cout << d << std::endl;

    return 0;
}
