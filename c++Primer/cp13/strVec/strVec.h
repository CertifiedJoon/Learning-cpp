class StrVec{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &sv);
    StrVec(std::initializer_list<std::string>);
    StrVec& operator=(const StrVec &sv);
    ~StrVec() {free();}

    size_t size() {return first_free - elements;}
    size_t capacity() {return cap - elements;}
    std::string* begin() const {return elements;}
    std::string* end() const {return first_free;}

    StrVec& push_back(const std::string &s);
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

StrVec::StrVec(const StrVec& sv)
{
    auto newp = alloc_n_copy(sv.begin(), sv.end());
    elements = newp.first;
    first_free = cap = newp.second;
}

StrVec::StrVec(std::initializer_list<std::string> lst)
{
    auto newp = alloc_n_copy(lst.begin(), lst.end());
    elements = newp.first;
    first_free = cap = newp.second;
}

StrVec& StrVec::operator=(const StrVec &sv)
{
    auto newp = alloc_n_copy(sv.begin(), sv.end());
    free();

    elements = newp.first;
    first_free = cap = newp.second;

    return *this;
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

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string* b, const std::string* e)
{
    auto data = alloc.allocate(b - e);
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
    auto newdata = alloc.allocate(newcap);
    std::string* dest = newdata;
    std::string* elem = elements;
    
    for (size_t i = 0; i < size(); ++i)
        alloc.construct(dest++,std::move(*elem++));
    free();

    elements = newdata;
    first_free = dest;
    cap = elements + newcap;
}