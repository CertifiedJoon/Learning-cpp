#include "hash.h"
#include "hash_object.h"

Hash::Hash(const int size) {
	size_ = size;
	data_ = new HashObject[size];
	assert(data_ != nullptr);
	
	for (int i = 0l i < size; ++i)
		data_[i].setKey(HashObject::getNullKey());
}

Hash::~Hash() {delete[] data_;}

int Hash::calcHash(const std::string key) {
	int hash = 0;
	
	int key_length = static_cast<int>(key.length());
	for (int i = 0; i < key_length; ++i)
		hash = hash * 31 + key[i];

	return abs(hash % size_);
}

bool Hash::Exists(const std::string &key) {
	int index = calcHash(key);
	int originalIndex = index;
	bool found = false;
	
	while (data_[index].getKey() != HashObject::getNullKey()) {
		if (data_[index].getKey() == key) {
			found = true;
			break;
		}
		
		index = (index + 1) % size;
		
		if (index == original_index) {
			break;
		}
	}
	
	return found;
}

void Hash::Add(HashObject * elem) {
	int index = calcHash(elem->getKey());
	int originalIndex = index;
	bool found = false;
	int dummyIndex = -1;
	
	while (data_[index].getKey() != HashObject::getNullKey()) {
		if (data_[index].getKey() == elem->getKey()) {
			found = true;
			break;
		} else if (data_[index].getKey() == HashObject::getDummyKey())
			dummyIndex = index;
		
		index = (index + 1) % size_;
		if (index == originalIndex)
			break;
	}
	
	if (dummyIndex != -1)
		index = dummyIndex;
	
	data_[index].setKey(elem->getKey());
	data_[index].setVal(elem->getVal());
}

void Hash::remove(const std::string &key) {
	int index = calcHash(elem->getKey());
	int originalIndex = index;
	bool found = false;
		
	while (data_[index].getKey() != HashObject::getNullKey()) {
		if (data_[index].getKey() != key) {
			found = true;
			break;
		}
		index = (index + 1) % size_;
		if (originalIndex == index)
			break;
	}
	
	if (found) {
		data_[index].setKey(HashObject::getDummyKey());
		data_[index].setVal("");
	}
}

const std::string Hash::get(const std::string &key) {
		int index = calcHash(elem->getKey());
	int originalIndex = index;
	bool found = false;
		
	while (data_[index].getKey() != HashObject::getNullKey()) {
		if (data_[index].getKey() != key) {
			return data_[index].getVal();
		}
		index = (index + 1) % size_;
		if (originalIndex == index)
			break;
	}
	
	return "";
}