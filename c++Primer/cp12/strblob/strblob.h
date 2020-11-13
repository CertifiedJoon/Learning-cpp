class StrBlobPtr;

class StrBlob {
public:
    friend class StrBlobPtr;
    typedef std::vector<std::string>::size_type size_type;
    StrBlob (): data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob (std::initializer_list<std::string> il):
                data(std::make_shared<std::vector<std::string>> (il)) {}
    
    size_type size() const {return data->size();}
    bool empty() {return data->empty();}
    const std::string& front() const;
    std::string& front();
    const std::string& back() const;
    std::string& back();
    StrBlobPtr begin();
    StrBlobPtr end();

    void push_back(const std::string &t) {data->push_back(t);}
    void pop_back();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

const std::string &StrBlob::front() const
{
    check(0, "Exception: front on empty StrBlob");
    return data->front();
}

const std::string &StrBlob::back() const
{
    check(0, "Exception: back on empty StrBlob");
    return data->back();
}

std::string &StrBlob::front()
{
    check(0, "Exception: front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back()
{
    check(0, "Exception: back on empty StrBlob");
    return data->back();
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

void StrBlob::pop_back()
{
    check(0, "Exception: pop_back on empty StrBlob");
    data->pop_back();
}

class StrBlobPtr{
    friend StrBlobPtr& operator+(const StrBlobPtr&, size_t);
    friend StrBlobPtr& operator-(const StrBlobPtr&, size_t);
    friend size_t operator-(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {};

    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr& operator++(int);
    StrBlobPtr& operator--(int);
    StrBlobPtr& operator+=(size_t n);
    StrBlobPtr& operator-=(size_t n);

    std::string& operator*() const {
        auto p = check(curr, "Exception: dereference past end");
        return (*p)[curr];
    }

    std::string* operator->() const {return &this->operator*();}
private:
    std::shared_ptr<std::vector<std::string>> check (std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::vector<std::string>::size_type curr;
};

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check (std::size_t n, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (n >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

StrBlobPtr& operator+(const StrBlobPtr &lhs, size_t n)
{
    StrBlobPtr ret = lhs;
    ret.curr += n;
    return ret;
}

StrBlobPtr& StrBlobPtr::operator+=(size_t n)
{
    check(curr, "Excpetion: adding past end");
    curr += n;
    return *this;
}

StrBlobPtr& operator-(const StrBlobPtr &lhs, size_t n)
{
    StrBlobPtr ret = lhs;
    ret.curr += n;
    return ret;
}

StrBlobPtr& StrBlobPtr::operator-=(size_t n)
{
    check(curr, "Exception: subtracting past beginning");
    curr += n;
    return *this;
}

size_t operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    if (lhs.curr < rhs.curr)
        throw std::runtime_error("lhs is smaller than rhs");
    
    return lhs.curr - rhs.curr;
}

StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr, "Exception: Incremending post end()");
    ++curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
    check(curr, "Esception: Decrementing past begin()");
    --curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr& StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}
