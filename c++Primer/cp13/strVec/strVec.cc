#include <string>
#include <memory>
#include <utility>
#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <iterator>
#include <cstddef>
#include "strVec.h"

int main()
{
    std::ostream_iterator<std::string> osit(std::cout, " ");
    StrVec sv1{"string 1", "string 2", "string3"};
    std::cout << "construction complete\n";
    copy(sv1.begin(), sv1.end(), osit);
    std::cout << std::endl;
    
    StrVec sv2;
    sv2.push_back("string 1").push_back("string 2").push_back("string 3");
    copy(sv2.begin(), sv2.end(), osit);
    std::cout << std::endl;

    StrVec sv3(sv1);
    copy(sv3.begin(), sv3.end(), osit);
    std::cout << std::endl;

    StrVec sv4;
    sv4 = sv1;
    copy (sv4.begin(), sv4.end(), osit);
    std::cout << std::endl;
}