#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<class T>
class llist {
public:
	explicit llist() : head(nullptr) {}
	~llist() {}
	llst(const llst &ll) : head(ll.front()) {}
	llst &operator=(const llst &ll) : head(ll.front()) {}
	
// 	accessors
	node<T> *front() { return head; }
	node<T> *back();
	size_t size();
	const T val_at(size_t index);
	bool empty() { return (head == nullptr) ? true : false; }
	
//  tester
	void print();
	
// 	mutator
	llst<T>& push_back(node<T>* n);
	llst<T>& push_back(T val);
	llst<T>& push_front(node<T> *n);
	llst<T>& push_front(T val);
	
	node<T> pop_back();
	node<T> pop_front();
	
	size_t insert(int index, T value);
	node<T>* insert_after(node<T> *after, node<T> *to_insert);
	node<T>* insert_before(node<T> *before, node<T> *to_insert);

	size_t erase(int index, T value);
	node<T>* erase_after(node<T> *after, node<T> *to_insert);
	node<T>* erase_before(node<T> *before, node<T> *to_insert);
	
	node<T>* T nth_last_node(int n);
	void reverse();
	void remove_value(T value);

private:
	node<T> *head;
}



#endif