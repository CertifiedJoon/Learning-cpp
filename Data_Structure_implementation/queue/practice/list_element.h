#ifndef NODE_H
#define NODE_H

#include <memory>

namespace cj{

template<class T>
class node{
public:
	node(const T &val): val_(val) {}
	~node();
	node(const node &) = delete;
	node &operator=(const node&) = default;
	
// 	accessor
	const T& get_val() const {return val_;}
	node<T>* get_next() const {return next_;}
	
// 	mutator
	void set_val(const T  &val) { val_ = val; }
	void set_next(node<T> *next) {next_ = next;}
private:
	T val_;
	node<T>* next_ = nullptr;
}
}


#endif