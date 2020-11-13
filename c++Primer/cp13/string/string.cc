#include <memory>
#include <cstddef>
#include <utility>
#include <algorithm>
#include <cstring>
#include <iostream>
#include "string.h"

int main()
{
    string s("i dont think this is gonna work");
    string s1(s);
    std::cout << s1;
}
