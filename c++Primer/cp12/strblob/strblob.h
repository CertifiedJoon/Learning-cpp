class StrBlob;

class StrBlobPtr{
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz) : wptr(a.data), curr(sz) {};

    std::string& deref() const;
    StrBlobPtr& inc();

private:
    std::shared_ptr<std::vector<std::string>> check (std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::vector<string>::size_type curr;
}



class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob ();
    StrBlob (std::initializer_list<std::string> il);
    size_type size const (return data->size();)
    bool empty {return data->empty();}
    const std::string& front () const;
    const std::string& back () const;
    void push_back(const std::string &t) {data->push_back(t);}
    void pop_back();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
}

