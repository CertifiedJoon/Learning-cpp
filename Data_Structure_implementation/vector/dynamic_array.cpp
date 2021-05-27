#ifndef DYNAMIC_H
#define DYNAMIC_H

#include <memory>
#include <utility>
#include <exception>
#include <initializer_list>

template<typename T>
class vector {
public:
	vector() : elements(nullptr); first_free(nullptr), cap (nullptr) {}
	vector(const vector<T> &v);
	vector(vector<T> &&v) : elements(v.elements), first_free(v.first_free), cap(v.cap)
		{v.elements = v.first_free = v.cap = nullptr;}
	vector(std::initializer_list<T> il);
	~vector() {free();}
	
	vector<T>& operator= (vector<T> rhs);
	vector<T>& operator= (std::initializer_list<T> il);
	T& operator[](std::size_t n);
	
	std::size_t size() const { return first_free - elements; }
	std::size_t capacity() const { return cap - elements; }
	T* begin() const {return elements;}
	T* end() const {return first_free;}
	void reserve(std::size_t);
	vector<T>& push_back(const T &lv);
	vector<T>& push_back(T &&v);
	
private:
	
	static std::allocator<T> alloc;
	std::pair<T*, T*> alloc_n_copy (const T*, const T*);
	void free();
	void reallocate();
	void chk_n_alloc() {if (size() == capacity()) reallocate();}
	
	T *elements;
	T *first_free;
	T *cap;
};

#endif