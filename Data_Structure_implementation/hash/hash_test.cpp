#include "hash_object.h"
#include "hash.h"
#include "hash.cpp"

int main() {
	cj::Hash table(100);
	std::string key, val;
	
	while (std::cin >> key >> val) {
		cj::HashObject *elem = new cj::HashObject();
		elem->SetKey(key);
		elem->SetValue(val);
		table.Add(elem);
	}
	
	table.PrintDebug();
	
	std::cout << table.Exists("Kant") << std::endl;
	std::cout << table.Get("Kant") << std::endl;
	table.Remove("Kant");
	std::cout << table.Exists("Kant") << std::endl;
	
	
	std::cin.clear();
}