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

    StrVec sv1 = {"string 1", "string 2", "string 3"};
    copy(sv1.begin(), sv1.end(), osit);
    std::cout << std::endl;
    
    StrVec sv2;
    sv2.push_back("string 2").push_back("string 2").push_back("string 3");
    copy(sv2.begin(), sv2.end(), osit);
    std::cout << std::endl;
    std::cout << (sv1 < sv2) << std::endl;

    StrVec sv4 = sv2;
    copy (sv4.begin(), sv4.end(), osit);
    std::cout << std::endl;
    std::cout << (sv4 <= sv2) << std::endl;

    StrVec sv3(sv2);
    copy(sv3.begin(), sv3.end(), osit);
    std::cout << std::endl;

}