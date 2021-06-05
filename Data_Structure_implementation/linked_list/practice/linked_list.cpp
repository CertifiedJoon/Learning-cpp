#include "linkied_list.h"

using namespace cj;

template<class T>
node<T>* llst<T>::back() {
	node<T> *curr = head;
	
	while (curr->next != nullptr)
		curr = curr->next;
	
	return curr;
}

template<class T>
size_t llst<T>::size() {
	size_t s = 0;
	node<T> curr = head;
	
	while (curr != nullptr){
		++s;
		curr = curr->next;
	}
	
	return s;
}

template<class T>
const T llst<T>::val_at(size_t index) {
	size_t i = 0;
	node<T> *curr = head;
	try {
		while (i != index) {
			curr = curr->next;
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

