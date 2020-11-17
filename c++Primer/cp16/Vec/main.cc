#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "vec.h"

int main()
{
    std::ostream_iterator<std::string> osit(std::cout, " ");

    vector<std::string> sv1 = {"string 1", "string 2", "string 3"};
    copy(sv1.begin(), sv1.end(), osit);
    std::cout << std::endl;
    
    vector<std::string> sv2;
    std::string s = "string 2";
    sv2.push_back(std::move(s)).push_back("string 2").push_back("string 3");
    copy(sv2.begin(), sv2.end(), osit);
    std::cout << std::endl;
    std::cout << (sv2 > sv1) << std::endl;

    std::cout << "entering test 3" << std::endl;
    vector<std::string> sv3 = sv2;
    copy (sv3.begin(), sv3.end(), osit);
    std::cout << std::endl;
    std::cout << (sv3 != sv2) << std::endl;

}