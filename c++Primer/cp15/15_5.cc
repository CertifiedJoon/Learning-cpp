#include <string>
#include <iostream>
#include <cstddef>
class Quote{
public:
    Quote() = default;
    Quote(const std::string &book, double original_price):
          bookNo(book), price(original_price){}
    std::string isbn() const {return bookNo;}
    virtual double net_price(const size_t n) const 
        {return n*price;}
    virtual ~Quote() = default;
    virtual print_total(std::ostream& os, const size_t n)
        {os << bookNo << " : " << net_price(n)};
private:
    std::string bookNo;
protected:
    double price = 0.0;
}

class Bulk_quote: public Quote{
public:
    Bulk_quote(const std::string &book, double p,
               size_t qty, double disc) :
               Quote(book, p), min_qty(qty), discount(dis){}
    Bulk_quote(const std::string &book, double p, double disc):
               Quote(book, p), discount(disc) {}

    double net_price(const size_t n) const override;
private:
    size_t min_qty = 0;
    double discount = 0.0;
}

double Bulk_quote::net_price(const size_t n) const
{
    if (min_qnt <= n)
        return price * (1 - discount) * n;
    else 
        return price * n;
}