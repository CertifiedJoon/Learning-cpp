#include <string>
#include "hash_object.h"
#incude <stdlib.h>
#incude <assert.h>
#include <iostream>

#ifndef HASH_H
#define HASH_H

namespace cj {
	class Hash {
	public:
		explicit Hash(const int size);
		~Hash();
		Hash(const Hash &) = delete;
		Hash &operator=(const Hash &) = delete;
		
		void add(HashObject *object);
		bool exists(const std::string &key);
		const std::string get(const std::string &key);
		void remove (const std::string &key);
		void printDebug();
	private:
		int size_;
		HashObject *data_;
		
		int calcHash(const std:;string &key);
	}
}

#endif