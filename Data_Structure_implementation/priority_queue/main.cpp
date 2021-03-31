#include "priority_queue.h"
#include "priority_queue.cpp"
#include <iostream>
#include <string>

int main() {
	cj::PriorityQueue q(10);
	int priority = 0;
	std::string value;
	
	while (std::cin >> priority >> value) {
		q.Insert(priority, value);
	}
	
	q.PrintDebug();
	auto top = q.PopMax();
	std::cout << top->key_ << " : " <<  top->value_ << std::endl;

	std::cout << q.GetMax()->key_ << " : " << q.GetMax()->value_ << std::endl;
		
	std::cout << q.GetSize() << " ";
	q.Remove(3);
	std::cout << q.GetSize() << std::endl;
}