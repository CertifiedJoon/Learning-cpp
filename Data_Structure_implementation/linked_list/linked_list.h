#include "list_elements.h"
#include <stdlib.h>
#include <iostream>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace cj {
	
template<class T>
class LinkedList {
public:
	explicit LinkedList() : head_(nullptr) {}
	~LinkedList();
	LinkedList(const LinkedList&) = delete;
	LinkedList &operator=(const LinkedList &) = delete;
	
	int size() const; //
	void push_front(T value); //
	bool empty() const; //
	const T &value_at(int index) const; //
	void print_debug() const; 
	const T pop_front(); //
	void push_back(T value); //
	const T pop_back(); //
	const T front();  //
	const T back(); //
	void insert(int index, T value);
	void erase (int index);
	const T value_from_end(int n);
	void reverse();
	void remove_value(T value);
private:
	List_elements<T> *head_;
};
	
} // namespace cj

#endif