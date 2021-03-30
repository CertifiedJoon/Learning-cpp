#include <string>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include "hash_object.h"

#ifndef HASH_H
#define HASH_H

namespace cj{
class Hash {
public:
	explicit HashTable(const int size);
	~HashTable();
	HashTable(const HashTable &) = delete;
	HashTable &operator=(const HashTable &) = delete;
	
	void Add(HashObject *object);
	bool Exists(const std::string &key);
	const std::string & Get(const std::string &key);
	void Remove(const std::string &key);
	void PrintDebug();
private:
	int size_;
	HashObject *data_;
	
	int Hash(const std::string &key);
}
}
#endif