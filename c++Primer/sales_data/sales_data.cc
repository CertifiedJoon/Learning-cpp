#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "sales_data.h"

int main(){
    std::vector<Sales_data> v;
    std::string s;
    
    while (std::cin >> s)
        v.emplace_back(s);

    sort(v.begin(), v.end(), compareIsbn);

    for (const auto &data : v)
        std::cout << data.isbn() << std::endl;
}