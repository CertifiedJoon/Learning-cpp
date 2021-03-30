#include "cjvector.h"
#include <string>
#include <iostream>

int main() {
	vector<std::string> v;
	std::string anything;
	
	while (std::cin >> anything)
		v.push_back(anything);
	
	for (auto *it = v.begin(); it != v.end(); ++it)
		std::cout << *it << ", ";
	std::cout << std::endl;
}