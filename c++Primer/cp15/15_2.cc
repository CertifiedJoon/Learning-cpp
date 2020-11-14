#include <string>
#include <iostream>

class Quote{
public:
    Quote() = default;
    Quote(const string &book, double original_price):
          bookNo(book), price(original_price){}
    std::string isbn() const {return bookNo;}
    virtual double net_price(const size_t n) const 
        {return n*price;}
    virtual ~Quote() = default;
    virtual print_total(ostream& os, const size_t n)
        {os << bookNo << " : " << net_price(n)};
private:
    std::string bookNo;
protected:
    double price = 0.0;
}

