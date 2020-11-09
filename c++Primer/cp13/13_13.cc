#include <iostream>
#include <string>

struct X{
    X() {std::cout << "X()" << std::end;}
    X(const X&) {std::cout << "X(const X&)" << std::endl;}
    X& operator=(const X&) {std::cout<< "destructor" << std::endl;};
    ~X() {std::cout << "destructor" << std::endl;}

    string *ps;
}

int main(){
    X x ("123")
}