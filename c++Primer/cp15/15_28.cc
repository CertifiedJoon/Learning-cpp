#include <string>
#include <iostream>
#include <cstddef>
#include <vector>
#include <memory>
class Quote{
public:
    Quote() = default;
    Quote(const std::string &book, double original_price):
          bookNo(book), price(original_price){}
    virtual ~Quote() = default;

    std::string isbn() const {return bookNo;}
    virtual double net_price(const size_t n) const 
        {return n*price;}
    std::ostream& print_total(std::ostream& os, const size_t n)
        {os << bookNo << " : " << net_price(n); return os;}

    virtual std::ostream& debug (std::ostream& os) const
        {os << bookNo << " : " << price; return os;}
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote : public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double p,
               size_t qty, double disc):
               Quote(book, p), min_qty(qty), discount(disc) {}
    Disc_quote(const std::string &book, double p, double disc) :
               Quote(book, p), discount(disc) {}

    double net_price(std::size_t) const = 0;
    std::ostream& debug (std::ostream& os) const = 0;
protected:
    size_t min_qty = 0;
    double discount = 0.0;
};

class Bulk_quote: public Disc_quote{
public:
    using Disc_quote::Disc_quote;
    Bulk_quote() = default;

    double net_price(const size_t n) const override;
    std::ostream& debug(std::ostream& os) const override;
};

std::ostream& Bulk_quote::debug(std::ostream& os) const
{
    Quote::debug(os);
    os << " " << "min_qty: " << min_qty 
       << " " << "discount: " << discount;
    return os; 
}

double Bulk_quote::net_price(const size_t n) const
{
    if (min_qty <= n)
        return price * (1 - discount) * n;
    else 
        return price * n;
}

int main(){
    std::vector<std::shared_ptr<Quote>> vptr;
    vptr.push_back(std::make_shared<Bulk_quote>("catcher in the rye", 50, 10, 0.25));
    vptr.push_back(std::make_shared<Quote>("catcher in k rye", 40));

    vptr.back()->print_total(std::cout, 10);
}