#include "linked_list.h"
#include <exception>
#include <iostream>

namespace cj {
	
template <class T>
LinknedList<T>::~LinkedList() {
	ListElement<T> *current = head_;
	ListElement<T> *next = nullptr;
	
	while(current) {
		next = current->get_next();
		delete current;
		current = next;
	}
}
	
template <class T>
int LinkedList<T>::size() const {
	int size = 0;
	
	auto current = head_;
	while(current) {
		current = current->get_next();
		size++;
	}
}

template <class T>
void LinkedList<T>::push_front(T value) {
	auto *new_head = new ListElement<T>{value};
	
	new_head->set_next(head_);
	head_ = new_head;
	
	return *this;
}
	
template <class T>
bool LinkedList<T>::empty() const {
	if (head_ == nullptr)
		return true;
	return false;
}

template <class T>
const T& LinkedList<T>::value_at(int index) const {
	int i = 0;
	
	auto current = head_;
	
	while(current && i != index) current = current->get_next();
	
	try{
		if (!current)
			throw std::runtime_error("index out of range");
	} catch (std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
		
	return current->get_data();
}

template <class T>
const T LinkedList<T>::pop_front() {
	try {
		if (head_ == nullptr) throw std::runtime_error("cannot pop_front from an empty list");
	} catch (std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	
	
	T ret = head_->get_data();
	ListElement<T>* temp = head_n;
	head_ = head_->get_next();
	
	delete temp;
	
	return ret;
}

template <class T>
void LinkedList<T>::push_back(T value) {
	auto *push = new ListElement<T>(value);
	push->set_next(nullptr);
	
	if (!head_){
		head_ = push;
		return;
	}
	ListElement<T> *slow = head_;
	
	while(slow->get_next()){
		slow = slow->get_next();
	}
	
	slow->set_next(push);
}

template <class T>
T LinkedList<T>::pop_back() {
	try {
		if (head_ == nullptr) throw std::runtime_error("Cannot pop_back from empty list");
	} catch (std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	
	ListElement<T> *slow = nullptr;
	ListElement<T> *fast = head_;
	
	while(fast->get_next()){
		slow = fast;
		fast = fast->get_next();
	}
	
	T ret = fast->get_data();
	
	if(slow == nullptr){
		head_ = nullptr;
	} else {
		slow->set_next(nullptr);
	}
	
	delete fast;
	
	return ret;
}

template <class T>
const T LinkedList<T>::front(){
	try{
		if (head_ == nullptr) throw std::runtime_error("Cannot front() at empty linklist");
	} catch (std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	
	return head_->get_data();
}

template <class T>
const T LinkedList<T>::back(){
	try{
		if (head_ == nullptr) throw std::runtime_error("Cannot back() at empty linklist");
	} catch (std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	
	ListElement<T> *curr = head_;
	
	while(current->get_next()) current = current->get_next();
	
	return current->get_data();
}

template <class T>
void LinkedList<T>::insert(int index, T value){
	
	ListElement<T> *slow = nullptr;
	ListElement<T> *fast = head_;
	
	int i;
	for (i = 0; i < index && fast; ++i){
		slow = fast;
		fast = fast->get_next();
	}
	
	if (i != index) {
		std::cerr << "Index out of bounds." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	auto *node = new ListElement<T>(value);
	
	if (prev == nullptr) {
		node->set_next(head_);
		head_ = node;
	} else {
		slow->set_next(node);
		node->set_next(fast);
	}	
}

template <class T>
void LinkedList<T>::erase(int index) {
	ListElement<T> *slow = nullptr;
	ListElement<T> *fast = head_;
	
	int i;
	for (i = 0; i < index && fast; ++i){
		slow = fast;
		fast = fast->get_next();
	}
	
	if (i != index) {
		std::cerr << "Index out of bounds." << std::endl;
		exit(EXIT_FAILURE);
	} 
	
	if (slow == nullptr) {
		head_ = fast->get_next();
	} else {
		slow->set_next(fast->get_next());
	}
	
	delete fast;
}


template <class T>
const T LinkedList<T>::value_from_end(int n) {
	ListElement<T> *slow = nullptr;
	ListElement<T> *fast = head_;
	
	int i ;
	for (i = 0; i < n && fast; ++i)
		fast = fast->get_next();
	
	if (i < n){
		std::cerr << "index out of range" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	while(fast){
		slow = slow->get_next();
		fast = fast->get_next();
	}
	
	return slow->get_data();
}

template <class T>
void LinkedList<T>::reverse() {
	ListElement<T> *curr = head_, next = nullptr, prev = nullptr;
	
	while(curr) {
		next = curr->get_next();
		curr->set_next(prev);
		prev = curr;
		curr = next;
	}
	
	head_ = prev;
}


template <class T>
void LinkedList<T>::remove_value(T value) {
	ListElement<T> *slow = nullptr;
	ListElement<T> *fast = head_;
	
	while (fast) {
		if (fast->get_data() == value) {
			if (slow == nullptr){
				head_ = fast->get_next();
			} else {
				slow->set_next(fast->get_next());
			}
			
			delete fast;
			fast = slow->get_next();
			break;
		}
		
		slow = fast;
		fast = fast->get_next();
	}
}

} //namespace cj



























