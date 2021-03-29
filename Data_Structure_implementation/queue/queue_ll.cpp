#include "queue_ll.h"

namespace cj{

template <class T> 
Queue<T>::~Queue() {
	ListNode<T> *current = head_;
	ListNode<T> *temp = head_;
	
	while(current) {
		temp = current;
		current = current->GetNext();
		delete temp;
	}
}


template <class T> 
void Queue<T>::Enqueue(const T& value) {
	ListNode<T>* add = new ListNode<T>(value);
	
	if (Empty()) {
		head_ = tail_ = add;
	} else {
		tail_->SetNext(add);
		tail_ = add;
	}
}

template <class T> 
const T Queue<T>::Dequeue() {
	if (Empty()) {
		std::cerr << "Cannot Dequeue from empty queue." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	T value = head_->GetData();
	
	ListNode<T> *temp = head_;
	
	if (head_ == tail_) {
		tail_ = head_->GetNext();
	}
	
	head_ = head_->GetNext();
	
	delete temp;
	
	return value;
}

template <class T> void Queue<T>::PrintDebug() const {
	ListElement<T> *current = head_;
	
	std::cout << "Queue elements: ";
	
	while(current) {
		std::cout << current->GetData() << " < ";
		current = current->GetNext();
	}
	
	std::cout << std::endl;
	
}

}