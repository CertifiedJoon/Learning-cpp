#ifndef QUEUE_H
#define QUEUE_H

#include "list_element.h"

namespace cj {
template <class T>
class queue {
	queue(): head_(nullptr), tail_(nullptr) {}
	~queue();
	queue (const queue &) {} = delete;
	
	bool empty() {return head_ == nullptr ;}
	
	void enqueue(const T &item);
	const T dequeue();
private:
	node<T> *head_;
	node<T> *tail_;
}
	
}
