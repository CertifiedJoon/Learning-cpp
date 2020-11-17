#ifndef BLOB_H
#define BLOB_H
#include <memory>
#include <string>
#include <vector>
#include "blobptr.h"

template<typename T> class Blob {
    friend class BlobPtr<T>;
public:
    typedef typename std::vector<T>::size_type size_type;
    Blob(): data(std::make_shared<std::vector<T>>()) {}
    Blob(std::initializer_list<T> il):
                data(std::make_shared<std::vector<T>> (il)) {}
    
    T& operator[](size_type i);

    size_type size() const {return data->size();}
    bool empty() {return data->empty();}
    const T& front() const;
    T& front();
    const T& back() const;
    T& back();
    BlobPtr<T> begin();
    BlobPtr<T> end();

    void push_back(const T &t) {data->push_back(t);}
    void pop_back();

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template<typename T>
T& Blob<T>::operator[](size_type i)
{
    check(i, "Exception: subscript out of range");
    return (*data)[i];
}
template<typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template<typename T>
const T &Blob<T>::front() const
{
    check(0, "Exception: front on empty Blob<T>");
    return data->front();
}

template<typename T>
const T &Blob<T>::back() const
{
    check(0, "Exception: back on empty Blob<T>");
    return data->back();
}

template<typename T>
T &Blob<T>::front()
{
    check(0, "Exception: front on empty Blob<T>");
    return data->front();
}

template<typename T>
T &Blob<T>::back()
{
    check(0, "Exception: back on empty Blob<T>");
    return data->back();
}

template<typename T>
BlobPtr<T> Blob<T>::begin()
{
    return BlobPtr<T>(*this);
}

template<typename T>
BlobPtr<T> Blob<T>::end()
{
    return BlobPtr<T>(*this, data->size());
}

template<typename T>
void Blob<T>::pop_back()
{
    check(0, "Exception: pop_back on empty Blob<T>");
    data->pop_back();
}



#endif