class string;
void swap(string &, string &);

class string{
    friend void swap(string &, string &);
public:
    string();
    string(const char *arr);
    string(const string&);
    ~string() {free();}
    string& operator=(string&) noexcept;
    string& operator=(string &&) noexcept;

    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    char* begin() const {return elements;}
    char* end() const {return first_free;}
private:
    static std::allocator<char> alloc;
    void chk_n_alloc()
        {if (size() == capacity()) reallocate();}
    std::pair<char*, char*>
    alloc_n_copy(const char*, const char*);
    void reallocate();
    void free();

    char* elements;
    char* first_free;
    char* cap;
};

static size_t INITIAL_CAP = 2;
std::allocator<char> string::alloc;

void swap (string &s1, string &s2)
{
    using std::swap;
    swap(s1.elements, s2.elements);
    swap(s1.first_free, s2.first_free);
    swap(s1.cap, s2.cap);
}

void print(const string &s)
{
    std::for_each(s.begin(), s.end(), std::putchar);
}

void string::reallocate()
{
    size_t newCap = size() ? 2 * size() : 2;
    auto first = alloc.allocate(newCap);
    
    auto last = std::uninitialized_copy(std::make_move_iterator(begin()),
                                   std::make_move_iterator(end()),
                                   first);
    elements = first;
    first_free = last;
    cap = first + newCap;
}

std::pair<char*, char*> 
string::alloc_n_copy(const char *b, const char *e){
    auto newp = alloc.allocate(e - b);
    return {newp, std::uninitialized_copy(b,e,newp)};
}

void string::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap-elements);
    }
}

string::string()
{
    auto newc = alloc.allocate(INITIAL_CAP);
    *newc = '\0';
    elements = newc;
    first_free = cap = elements + 1;
}

string::string(const char *arr)
{
    auto len =  sizeof(arr) / sizeof(arr[0]);
    auto newc = alloc_n_copy(arr, arr+len);
    elements = newc.first;
    first_free = cap = newc.second;
}

string::string(const string &s)
{
    auto newp = alloc_n_copy(s.begin(), s.end());
    elements = newp.first;
    first_free = cap = newp.second;
}

string& string::operator=(string &rhs) noexcept
{
    swap(*this, rhs);
    return *this;
}

string& string::operator=(string &&rhs) noexcept
{
    swap(*this, rhs);
    return *this;
}