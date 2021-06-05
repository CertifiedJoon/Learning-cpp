#include "linkied_list.h"

using namespace cj;

template<class T>
node<T>* llst<T>::back() {
	node<T> *curr = head;
	
	while (curr->next != nullptr)
		curr = curr->get_next();
	
	return curr;
}

template<class T>
size_t llst<T>::size() {
	size_t s = 0;
	node<T> curr = head;
	
	while (curr != nullptr){
		++s;
		curr = curr->get_next();
	}
	
	return s;
}

template<class T>
const T llst<T>::val_at(size_t index) {
	size_t i = 0;
	node<T> *curr = head;
	try {
		while (i != index) {
			curr = curr->get_next();
			++i;
		}
		if (curr == nullptr) throw std::runtime_error("index out of range");
	} catch (std::runtime_error &e) {
		std::cerr<<e.what()<<std::end;
		exit(EXIT_FAILURE);
	}
	
	return curr->get_val();
}

template<class T>
void llst<T>::print() {
	node<T> *curr = head;
	std::cout << "head;
	while (curr != nullptr) {
		std::cout << " --> " << curr->get_val();
	}
}


template<class T>
llst<T>& llst<T>::push_back(const node<T> *n) {
	this->back()->set_next(n);
	return this;
}

template<class T>
llst<T>& llst<T>::push_back(const T& val) {
	node<T> *n = new node<T>(val);
	this->back()->set_next(n);
	return this;
}

template<class T>
llst<T>* llst<T>::push_front(const node<T> *n) {
	if (head == nullptr)
		head = n;
	else {
		n->set_next(head->get_next());
		head->set_next(n);
	}
	return this;
}

template<class T>
llst<T>* llst<T>::push_front(const T& val) {
	auto *n = new node<T>(val);
	
	if (head == nullptr) {
		head = n;
		return;
	}
	
	n->set_next(head->next);
	head->set_next(n);
	return this;
}

template<class T>
node<T>* llst<T>::pop_back() {  //user has to free the memory if he wishes to just use the value
	try {
		if(head == nullptr) throw std::runtime_error("Cannot pop from empty list");
		
		node<T>* curr = head;
		node<T>* prev = nullptr;
		
		if (curr->get_next() == nullptr) {
			head = nullptr;
			return curr;
		}
		
		while(curr->get_next() != nullptr) {
			prev = curr;
			curr = curr->get_next();
		}
		prev->set_next(nullptr);
	} catch (std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	
	return curr;
}

template<class T>
node<T>* llst<T>::pop_front() {
	try {
		if (head == nullptr) throw std::runtime_error("Cannot pop from empty list");
		
		node<T>* curr = head;
		
		if (head->get_next() == nullptr) {
			head = nullptr;
			return curr;
		}
		
		head = head->get_next();
		
		return curr;
	} catch (std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}

template<class T>
node<T>* llst<T>::nth_last_node(int n) {
	node<T>* slow = head;
	node<T>* fast = head;
	
	try {
		if (n < 1) throw std::runtime_error("not a valid n");
		
		while (n != 1) {
			fast = fast->get_next();
			--n;
		}
		
		while (fast != nullptr) {
			fast = fast->get_next();
			slow = slow->get_next();
		}
		
		if (slow == nullptr) throw std::runtime_error("n too large");
		
		return slow;
	} catch (std::runtime_error &e) {
		std::cer << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}

template<class T>
void llst<T>::reverse() {
	node<T>* curr = head;
	node<T>* prev = nullptr;
	node<T>* next = nullptr;
	
	while (curr != nullptr) {
		next = curr->get_next();
		curr->set_next(prev);
		prev = curr;
		curr = next;
	}
}

template<class T>
void llst<T>::remove_value(T value) {
	if (head->get_value() == value) this->pop_front();
	
	node<T>* curr = head;
	node<T>* prev = nullptr;
	
	while (curr != nullptr) {
		if ( curr->get_val() == value ) 
			prev->set_next(curr->get_next());
		prev = curr;
		curr = curr->get_next();
	}
}















