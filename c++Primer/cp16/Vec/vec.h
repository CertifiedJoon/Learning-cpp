#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <iterator>
#include <utility>
#include <memory>
#include <exception>

template<typename> class vector;
template<typename T> bool operator==(const vector<T>&, const vector<T>&);
template<typename T> bool operator>(const vector<T>&, const vector<T>&);
template<typename T> void swap(vector<T>&, vector<T>&);

template<typename T> class vector{
    friend bool operator==<T>(const vector<T>&, const vector<T>&);
    friend bool operator><T>(const vector<T>&, const vector<T>&);
    friend void swap<T>(vector<T>&, vector<T>&);
public:
    vector() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    vector(const vector<T> &v);
    vector(vector<T> &&v) : elements(v.elements), first_free(v.first_free), cap(v.cap)
            {v.elements = v.first_free = v.cap = nullptr;}
    vector(std::initializer_list<T> il);
    ~vector(){ free(); }

    vector<T>& operator=(vector<T> rhs);
    vector<T>& operator=(std::initializer_list<T> il);
    T& operator[](std::size_t n);

    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return cap - first_free; }
    T* begin() const { return elements; }
    T* end() const { return first_free; }

    void reserve(std::size_t);
    vector<T>& push_back(const T &lv);
    vector<T>& push_back(T &&rv);
private:
    static std::allocator<T> alloc;
    void reallocate();
    void free();
    std::pair<T* ,T*> alloc_n_copy (const T*, const T*);
    void chk_n_alloc() 
        {if (size() == capacity()) reallocate();}
    T *elements;
    T *first_free;
    T *cap;
};


//private members
template<typename T>
std::allocator<T> vector<T>::alloc;

template<typename T>
std::pair<T*, T*> vector<T>::alloc_n_copy (const T* b, const T* e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

template<typename T>
void vector<T>::reallocate()
{
    auto new_cap = size() ? 2*size() : 1;
    auto first = alloc.allocate(new_cap);
    auto last = uninitialized_copy(make_move_iterator(begin()),
                                  make_move_iterator(end()),
                                  first);
    
    free();
    elements = first;
    first_free = last;
    cap = elements + new_cap;
}

template<typename T>
void vector<T>::free()
{
    if (elements)
    {
        for(auto it = first_free; it != elements;)
            alloc.destroy(--it);
        alloc.deallocate(elements, cap-elements);
    }
}

//constructors
template<typename T>
vector<T>::vector(std::initializer_list<T> il)
{
    auto newp = alloc_n_copy(il.begin(), il.end());
    elements = newp.first;
    first_free = cap = newp.second;
}

template<typename T>
vector<T>::vector(const vector<T>&v)
{
    auto newp = alloc_n_copy(v.begin(), v.end());
    elements = newp.first;
    first_free = cap = newp.second;
}

//swap
template<typename T>
void swap(vector<T> &lhs, vector<T> &rhs)
{   
    std::cout << "entered swap" << std::endl;
    using std::swap;
    swap(lhs.elements, rhs.elements);
    swap(lhs.first_free, rhs.first_free);
    swap(lhs.cap, rhs.cap);
}

//copy-assignment operators
template<typename T>
vector<T>& vector<T>::operator=(vector<T> rhs)
{
    std::cout << "entered copy assign" << std::endl;
    swap(*this, rhs);
    return *this;
}

template<typename T>
vector<T>& vector<T>::operator=(std::initializer_list<T> il)
{
    auto newp = alloc_n_copy(il.begin(), il.end());
    free();
    elements = newp.first;
    first_free = newp.second;
    return *this;
}

//public member function
template<typename T>
void vector<T>::reserve(std::size_t n)
{
    if (n < size()) n = size();
    auto newp = alloc.allocate(n);
    auto dest = newp;
    auto elem = elements;
    
    for(size_t i = 0; i < size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();

    elements = newp;
    first_free = dest;
    cap = elements + n;
}

template<typename T>
vector<T>& vector<T>::push_back(const T &lv)
{
    chk_n_alloc();
    alloc.construct(first_free++, lv);
    return *this; 
}

template<typename T>
vector<T>& vector<T>::push_back(T &&rv)
{
    chk_n_alloc();
    alloc.construct(first_free++, rv);
    return *this;
}

//relational operator
template<typename T>
bool operator==(const vector<T> &lhs, const vector<T> &rhs)
{
    if (lhs.size() != rhs.size()) return false;
    
    for(auto l = lhs.begin(), r = rhs.begin();
        l != lhs.end() && r != rhs.end(); ++l, ++r)
        if (*l != *r) return false;

    return true;
}

template<typename T>
bool operator>(const vector<T> &lhs, const vector<T> &rhs)
{
    for(auto l = lhs.begin(), r = rhs.begin();
        l != lhs.end() && r != rhs.end(); ++l, ++r)
        if (*l > *r) return true;

    return false;
}

template<typename T>
bool operator!=(const vector<T> &lhs, const vector<T> &rhs)
{
    return !(lhs == rhs);
}

//access operator
template<typename T>
T& vector<T>::operator[](std::size_t n)
{
    if (n >= size()) 
        throw std::runtime_error("Index out of bound");
    return elements[n];
}
#endif
