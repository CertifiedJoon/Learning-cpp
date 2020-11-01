#include <iostream>
#include <string>
#include <vector>
#include "screen.h"

int main() {
    Screen myScreen(5,5);
    myScreen.move(4,0).set('#').display(std::cout);
    std::cout << '\n';
    myScreen.display(std::cout);
    std::cout << '\n';
}