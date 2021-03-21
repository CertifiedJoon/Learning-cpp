#ifndef VECTOR_H
#definde VECTOR_H

#include <memory>
#include <utility>

template<typename> class vector;
template <typename T> bool operator==(const vector<T>&, const vector<T>&);
template <typename T> bool operator<(const vector<T>&, const vector<T>&);
template <typename T> void swap(vector<T>&, vector<T>&);

template<typename T>
class vector {
friend bool operator==(const vector<T>&, const vector<T>&);
friend bool operator<(const vector<T>&, const vector<T>&);
friend void swap(vector<T>&, vector<T>&);
public:
	vector() : elements(nullptr), first_free(nullptr), cap (nullptr) {}
	vector(const vector<T> &v) ;
	vector(vector<T> &&v) : elements(v.elements), first_free(v.first_free), cap(v.cap) 
		{v.elements = v.first_free = v.cap = nullptr}
	vector(std::intializer_list<T> il);
	~vector() {free();}
	
	vector<T>& operator= (vector<T> rhs);
	vector<T>& operator= (std::initializer_list<T> il);
	T& operator[](std::size_t n);
	
	std::size_t size() const { return first_free - elements; }
	std::size_t capacity() const { return cap - elements; }
	T* begin() const { return elements; }
	T* end() cosnt { return first_free; }
	
private:
	static std::allocator<T> alloc;
	std::pair<T*, T*> alloc_n_copy (const T*, const T*);
	void free();
	void reallocate();
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	
	T *elements;
	T *first_free;
	T *cap;
};

template<typename T>
std::allocator<T> vector<T>::alloc;

template<typename T>
std::pair<T*, T*> alloc_n_copy (const T *b, const T *e)
{
	auto data = alloc.allocate(e - b);
	return {data, std::uninitialized_copy(b, e, data)}
}

template<typename T>
void vector<T>::free() 
{
	if(elements)
	{
		for (auto it = first_free; it != elements;)
			alloc.destroy(--it);
		alloc.deallocate(elements, cap - elements);
	}
}

template<typename T>
void vector<T>::reallocate()
{
	size_t new_cap = size() ? 2*size() : 16;
	auto first = alloc.allocate(new_cap);
	auto last = std::unitialized_copy(std::make_move_iterator(begin()),
									  std::make_move_iterator(end()),
									 first);
	free();
	elements = first;
	first_free = last;
	cap = first + new_cap;
}

template<typename T>
vector<T>::vector(const vector<T> &v)
{
	auto newp = alloc_n_copy(v.begin(), v,end());
	free();
	first = newp.first;
	first = cap = newp.second;
}

template<typename T>
vector<T>::vector(std::initializer_list<T> il)
{
	auto newp = alloc_n_copy(il.begin(), il.end());
	elements =  newp.first;
	first_free = cap = newp.second;
}


#endif