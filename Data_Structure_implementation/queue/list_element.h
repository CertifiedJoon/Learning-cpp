#include <memory>

#ifndef LIST_ELEMENT_H
#define LIST_ELEMENT_H

namespace cj {

template<class T> class ListNode {
public:
	ListNode(const T &value) : next_(nullptr) , val_ (value) {}
	~ListNode() {}
	ListNode(const ListNode &) = delete;
	ListNode &operator=(const ListNode &) = default;
	
	const T& GetData() const {return val_;}
	ListNode<T> *GetNext() const {return next_;}
	void SetData(const T &data) {val_ = data;}
	void SetNext(ListNode<T> *elem) {next_ = elem;}
private:
	ListNode<T>* next_ = nullptr;
	T val_;
}

}
#endif