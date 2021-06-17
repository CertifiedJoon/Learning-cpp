#include <string>

#ifndef HASH_OBJECT_H
#define HASH_OBJECT_H

namespace cj {
class HashObject {
	HashObject() {}
	~HashObject() {}
	HashObject(const HashObject &) = delete;
	HashObject &operator=(const HashObject &) = default;
	
	
	std::string getKey() const { return key_; }
	std::string getVal() const { return vaue_; }
	void setAsDummy() {
		key_ = getDummyKey();
		value_ = "";
	}
	void setKey (const std::string &key) { key_ = key; }
	void setVal (const std::string &value) { value_ = value; }
	static const std::string getDummyKey() { return "<Dummy>"; }
	static const std::string getNullKey() { return "<Dummy>"; }
private:
	std::string key_;
	std::string val_;
};
}

#endif