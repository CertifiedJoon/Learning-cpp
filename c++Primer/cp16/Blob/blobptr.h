#ifndef BLOB_PTR_H
#define BLOB_PTR_H
#include <memory>
#include <string>
#include <vector>

template<typename> class BlobPtr;
template<typename> class Blob;

template<typename T>
BlobPtr<T>& operator+(const BlobPtr<T>&, std::size_t);

template<typename T>
BlobPtr<T>& operator-(const BlobPtr<T>&, std::size_t);

template<typename T>
std::size_t operator-(const BlobPtr<T>&, const BlobPtr<T>&);

template<typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T> &);

template<typename T>
bool operator!=(const BlobPtr<T>&, const BlobPtr<T> &);


template<typename T> class BlobPtr{
    friend BlobPtr<T>& operator+<T>(const BlobPtr<T>&, std::size_t);
    friend BlobPtr<T>& operator-<T>(const BlobPtr<T>&, std::size_t);
    friend std::size_t operator-<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T> &);
    friend bool operator!=<T>(const BlobPtr<T>&, const BlobPtr<T> &);
public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {};

    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr& operator++(int);
    BlobPtr& operator--(int);
    BlobPtr& operator+=(std::size_t n);
    BlobPtr& operator-=(std::size_t n);

    T& operator*() const {
        auto p = check(curr, "Exception: dereference past end");
        return (*p)[curr];
    }

    T* operator->() const {return &this->operator*();}
private:
    std::shared_ptr<std::vector<T>> check (std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<T>> wptr;
    typename std::vector<T>::size_type curr;
};

template<typename T> std::shared_ptr<std::vector<T>>
BlobPtr<T>::check (std::size_t n, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound BlobPtr<T>");
    if (n >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

template<typename T>
BlobPtr<T>& operator+(const BlobPtr<T> &lhs, std::size_t n)
{
    BlobPtr<T> ret = lhs;
    ret.curr += n;
    return ret;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator+=(std::size_t n)
{
    check(curr, "Excpetion: adding past end");
    curr += n;
    return *this;
}

template<typename T>
BlobPtr<T>& operator-(const BlobPtr<T> &lhs, std::size_t n)
{
    BlobPtr<T> ret = lhs;
    ret.curr += n;
    return ret;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator-=(std::size_t n)
{
    check(curr, "Exception: subtracting past beginning");
    curr += n;
    return *this;
}

template<typename T>
std::size_t operator-(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    if (lhs.curr < rhs.curr)
        throw std::runtime_error("lhs is smaller than rhs");
    
    return lhs.curr - rhs.curr;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
    check(curr, "Exception: Incremending post end()");
    ++curr;
    return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
    check(curr, "Esception: Decrementing past begin()");
    --curr;
    return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this;
    --*this;
    return ret;
}

template<typename T>
bool operator==(const BlobPtr<T> &p, const BlobPtr<T> &q)
{
    if (p.wptr.lock() == q.wptr.lock() && p.curr == q.curr);
        return true;
    
    return false;
}

template<typename T>
bool operator!=(const BlobPtr<T> &p, const BlobPtr<T> &q)
{
    return !(p == q);    
}

#endif