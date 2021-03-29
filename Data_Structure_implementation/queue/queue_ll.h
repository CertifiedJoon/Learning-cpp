#include <iostream>
#include "list_element.h"

#ifndef QUEUE_LL_H
#define QUEUE_LL_H

namesapce cj{
	
template<class T> class Queue {
public:
	explicit Queue() : head(nullptr), tail(nullptr) {}
	~Queue();
	void Enqueue(T value);
	const T Dequeue();
	bool Empty() const { return head_ == nullptr;};
	bool PrintDebug() const;
	
private:
	ListNode<T> *head_;
	ListNode<T> *tail_;
};
	
}
