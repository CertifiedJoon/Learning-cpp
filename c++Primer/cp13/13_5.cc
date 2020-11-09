#include <string>
#include <vector>
#include <iostream>

class HasPtr{
public:
    friend void swap(HasPtr &, HasPtr&);
    friend bool operator<(const HasPtr&, const HasPtr&);

    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0), use(new std::size_t(1)) {} 
    HasPtr(const HasPtr & hp):
            ps(new std::string(*hp.ps)), i(hp.i), use(new std::size_t(++*hp.use)) {}
    HasPtr& operator=(const HasPtr &rhs);
    ~HasPtr();
private:
    std::string *ps;
    int i;
    std::size_t *use;
};

~HasPtr()
{
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs){
    ++*rhs.use;
    auto newp = rhs.ps;
    auto newu = rhs.use;
    
    if (--*use == 0){
        delete ps;
        delete use;
    }
    
    ps = newp;
    use = newu;
    i = rhs.i;

    return *this;
}

/*
HasPtr& HasPtr::operator=(HasPtr rhs){
    ++*rhs.use;
    swap(*this, rhs);
    return *this;
}
*/

void swap(HasPtr &p, HasPtr&q)
{
    using std::swap;
    swap(p.ps, q.ps);
    swap(p.i, q.i);
}

bool operator<(const HasPtr &p, const HasPtr &q)
{
    return *p.ps < *q.ps;
}

int main(){
}
