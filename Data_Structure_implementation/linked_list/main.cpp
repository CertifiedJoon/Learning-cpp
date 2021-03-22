#include <iostream>
#include <string>
#include "src/linked_list.h"
#include "src/linked_list.cpp"


int main () {
	cj::LinkedList<int> cjlist{};
	cjlist.push_back(1);
	cjlist.push_back(2);
	
	std::cout<< "size of int list is: " << cjlist.size() << std::endl;
	
	cj::LinkedList<std::string> strlist{};
	strlist.push_front("string 1");
	strlist.push_front("string 2");
	strlist.push_front("string 3");
	
	strlist.print_debug();
	strlist.reverse();
	strlist.print_debug();
	strlist.remove_value("string 3");
	strlist.print_debug();
}