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
    std::ostream& print_total(std::ostream& os, const size_t n)
        {os << bookNo << " : " << net_price(n); return os;}
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Bulk_quote: public Quote{
public:
    Bulk_quote(const std::string &book, double p,
               size_t qty, double disc) :
               Quote(book, p), min_qty(qty), discount(disc){}
    Bulk_quote(const std::string &book, double p, double disc):
               Quote(book, p), discount(disc) {}

    double net_price(const size_t n) const override;
private:
    size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(const size_t n) const
{
    if (min_qty <= n)
        return price * (1 - discount) * n;
    else 
        return price * n;
}

int main(){
    Bulk_quote bq("Mobydick", 49.99, 10, 0.15);
    Quote q("Catcher in the rye", 49.99);
    Quote q2 = bq;
    bq.print_total(std::cout, 15);
    std::cout << std::endl;
    q2.print_total(std::cout, 10);
}