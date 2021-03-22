#include <memory>
#ifndef LISTELEMENT_H
#define LISTELEMENT_H

namespace cj {
	
template <class T>
class ListElement{
public:
	ListElement(const T &value) : next_(nullptr), data_(value) {}
	~ListElement() {}
	ListElement(const ListElement &) = delete;
	ListElement &opeartor=(const ListElement &) = default;
	
	const T &get_data() const { return data_; }
	ListElement<T> *get_next() const { return next_; }
	void set_data(const T &data) { data_ = data; }
	void set_next(ListElement<t> *elem) { next_ = elem; }
	
private:
	ListElement<T> *next_;
	T data_;
};
	
} //namespace jw

#endif