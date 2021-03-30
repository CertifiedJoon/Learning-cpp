#include "hash.h"

namespace cj {

Hash::Hash(const int size) {
	size_ = size;
	data_ = new HashObject[size];
	assert(data_ != nullptr);
	
	for (int i = 0; i < size; ++i) {
		data_[i].SetKey(HashObject::GetNullKey());
	}
}
	
Hash::~Hash() { delete[] data_; }
	
int Hash::CalcHash(const std::string & key) {
	int hash = 0;
	
	int key_length = static_cast<int>(key.length());
	for (int i = 0; i < key_length; ++i) {
		hash = hash * 31 + key[i];
	}
	
	return abs(hash % size_);
}
	
bool Hash::Exists(const std::string &key) {
	int index = CalcHash(key);
	int original_index = index;
	bool found = false;
	
	while (data_[index].GetKey() != HashObject::GetNullKey()) {
		if (data_[index].GetKey() == key) {
			found = true;
			break;
		}
		
		index = (index + 1) % size_;
		
		if (index == original_index) {
			break;
		}
	}
	
	return found;
}
	
void Hash::Add(HashObject *elem) {
	int index = CalcHash(elem->GetKey());
	int original_index = index;
	int dummy_index = -1;
	
	bool found = false;
	
	while (data_[index].GetKey() != HashObject::GetNullKey()) {
		if (data_[index].GetKey() == elem->GetKey()){
			found = true;
			break;
		} else if (data_[index].GetKey() == HashObject::GetDummyKey()) {
			dummy_index = index;
		}
	}
	
	if (!found && dummy_index != -1) {
		index = dummy_index;
	}
	
	data_[index].SetKey(elem->GetKey());
	data_[index].SetValue(elem->GetValue());
}

	
void Hash::PrintDebug() {
	for (int i = 0; i < size_; ++i) {
		std::cout << i << ": " << data_[i].GetKey() <<": " << data_[i].GetValue() << std::endl;
	}
	
	std::cout << "=============================" << std::endl;
}
	
void Hash::Remove(const std::string &key) {
	int index = CalcHash(key);
	int original_index = index;
	
	while (data_[index].GetKey() != HashObject::GetNullKey()) {
		if (data_[index].GetKey() == key) {
			data_[index].SetKey(HashObject::GetDummyKey());
			data_[index].SetValue("");
			break;
		}
		
		index = (index + 1) % size_;
		
		if (index == original_index) {
			break;
		}
	}
}

const std::string Hash::Get(const std::string &key) {
	int index = CalcHash(key);
	int original_index = index;
	
	while(data_[index].GetKey() != HashObject::GetNullKey()) {
		if (data_[index].GetKey() == key) {
			return data_[index].GetValue();
		}
		index = (index + 1) % size_;
		if (index == original_index)
			break;
	}
	
	return "";
}
}
