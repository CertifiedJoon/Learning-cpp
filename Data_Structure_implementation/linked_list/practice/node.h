#ifndef NODE_H
#define NODE_H

namespace cj {

template <class T>
class node{
public:
	node(const T &value) : next_(nullptr), val_(value) {}
	~node() {}
	node(const node &);
	node &operator=(const node &) = default;
	
	const T &get_val() {return val_;}
	node<T> *get_next() {return next_;}
	void set_val(T val) { val_ = val; }
	void set_next(node<T> *next) { next_ = next;}
	
private:
	node<T> *next_;
	T val_;
}
	
}

#endif;