#include <string>
#include <iostream>
#include <cstddef>
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
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p,
               size_t qty, double disc) :
               Disk_quote(book, p, qty, disc){}

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
    Bulk_quote bq("Mobydick", 49.99, 10, 0.15);
    Quote q("Catcher in the rye", 49.99);
    Quote *q2 = &bq;
    bq.print_total(std::cout, 15);
    std::cout << std::endl;
    q2->print_total(std::cout, 15);
    std::cout << std::endl;
    q2->debug(std::cout);
}