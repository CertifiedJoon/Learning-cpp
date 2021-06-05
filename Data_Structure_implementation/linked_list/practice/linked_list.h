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
private:
	node<T> *head;
}



#endif