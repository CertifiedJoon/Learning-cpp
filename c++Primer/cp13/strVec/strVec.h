class StrVec;
void swap(StrVec &, StrVec &);

class StrVec{
    friend void swap(StrVec &, StrVec &);
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &sv);
    StrVec(StrVec &&sv) noexcept : elements(sv.elements), first_free(sv.first_free), cap(sv.cap)
        {sv.elements = sv.first_free = sv.cap = nullptr;}
    StrVec(std::initializer_list<std::string>);
    
    StrVec& operator=(StrVec &rhs) noexcept;
    StrVec& operator=(StrVec &&rhs) noexcept;
    StrVec& operator=(std::initializer_list<std::string>);

    std::string& operator[](size_t n);
    ~StrVec() {free();}

    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    std::string* begin() const {return elements;}
    std::string* end() const {return first_free;}

    StrVec& push_back(const std::string &s);
    StrVec& push_back(std::string &&s);
    StrVec& resize(size_t n);
    void reserve(size_t n);

private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc()
        {if (size() == capacity()) reallocate();}
    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);
    void free();
    void reallocate();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

std::allocator<std::string> StrVec::alloc;

void swap(StrVec &lhs, StrVec &rhs)
{
    using std::swap;
    swap(lhs.elements, rhs.elements);
    swap(lhs.first_free, rhs.first_free);
    swap(lhs.cap, rhs.cap);
}

StrVec::StrVec(const StrVec& sv)
{
    auto newp = alloc_n_copy(sv.begin(), sv.end());
    elements = newp.first;
    first_free = cap = newp.second;
}

StrVec::StrVec(std::initializer_list<std::string> lst)
{
    auto newp = alloc_n_copy(std::begin(lst),std::end(lst));
    elements = newp.first;
    first_free = cap = newp.second;
}

StrVec& StrVec::operator=(StrVec &rhs) noexcept
{
    swap(*this, rhs);
    return *this;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
    swap(*this, rhs);
    return *this;
}

StrVec& StrVec::operator=(std::initializer_list<std::string> lst)
{
    auto newp = alloc_n_copy(lst.begin(), lst.end());
    free();
    elements = newp.first;
    first_free = cap = newp.second;

    return *this;
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
    auto lit = lhs.begin(), rit = rhs.begin();

    while (lit != lhs.end() && rit != rhs.end() && *lit == *rit)
         ++lit, ++rit;
        
    return (lit == lhs.end() && rit == rhs.end());
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
    auto lit = lhs.begin(), rit = rhs.begin();

    while (lit != lhs.end() && rit != rhs.end() && *lit == *rit)
         ++lit, ++rit;
        
    return (lit != lhs.end() && rit != rhs.end() && *lit < *rit);
}

bool operator<=(const StrVec &lhs, const StrVec &rhs)
{
    auto lit = lhs.begin(), rit = rhs.begin();

    while (lit != lhs.end() && rit != rhs.end() && *lit == *rit)
         ++lit, ++rit;
        
    return (lit == lhs.end() && rit == rhs.end() || *lit < *rit);
}

bool operator>(const StrVec &lhs, const StrVec &rhs)
{
    auto lit = lhs.begin(), rit = rhs.begin();

    while (lit != lhs.end() && rit != rhs.end() && *lit == *rit)
         ++lit, ++rit;
        
    return (lit != lhs.end() && rit != rhs.end() && *lit > *rit);
}

bool operator>=(const StrVec &lhs, const StrVec &rhs)
{
    auto lit = lhs.begin(), rit = rhs.begin();

    while (lit != lhs.end() && rit != rhs.end() && *lit == *rit)
         ++lit, ++rit;
        
    return (lit == lhs.end() && rit == rhs.end() || *lit > *rit);
}

std::string &StrVec::operator[](size_t n)
{
    return elements[n];
}

void StrVec::reserve(size_t n)
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
    cap = newp + n;
}

StrVec& StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
    
    return *this;
}

StrVec& StrVec::push_back(std::string &&s)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));

    return *this;
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string* b, const std::string* e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap-elements);
    }
}

void StrVec::reallocate()
{
    auto newcap = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcap);
    auto last = uninitialized_copy(make_move_iterator(begin()),
                                   make_move_iterator(end()),
                                   first);

    free();
    elements = first;
    first_free = last;
    cap = elements + newcap;
}