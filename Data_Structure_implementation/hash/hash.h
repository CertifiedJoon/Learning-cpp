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
	explicit Hash(const int size);
	~Hash();
	Hash(const Hash &) = delete;
	Hash &operator=(const Hash &) = delete;
	
	void Add(HashObject *object);
	bool Exists(const std::string &key);
	const std::string Get(const std::string &key);
	void Remove(const std::string &key);
	void PrintDebug();
private:
	int size_;
	HashObject *data_;
	
	int CalcHash(const std::string &key);
};
}
#endif