#include "list_element.h"
#include "queue.h"

using namespace cj;

template<class T>
queue<T>::~queue() {
	node<T> *curr = head_;
	
	while(current) {
		node<T> *temp = curr;
		curr = curr.get_next();
		delete temp;
	}
}

template<class T>
void queue<T>::enqueue(const T&item) {
	node<T> *add = new node<T>(item);
	
	if (empty()) {
		head_ = add;
		tail_ = add;
	} else {
		tail_->set_next(add);
		tail_ = add;
	}
}

template<class T>
const T queue<T>::dequeue() {
	try {
		if (empty()) throw std::runtime_error("cannot dequeu from empty queue");
		
		node<T>* ret = head_;
		head_ = head->get_next();
		const T ret_val = ret->get_val();
		delete ret;
		return ret_val;
		
	} catch (std::runtime_error e) {
		std::cerr << e.what() << std::endl();
		exit(EXIT_FAILURE);
	}
}