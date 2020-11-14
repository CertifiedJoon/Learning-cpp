#include <string>
#include <iostream>
#include <cstddef>

class Quote{
public:
    Quote() = default;
    Quote(const std::string &book, double original_price, size_t limit):
          bookNo(book), price(original_price), maxDisc(limit){}
    virtual ~Quote() = default;
    
    std::string isbn() const {return bookNo;}
    virtual double net_price(const size_t n) const 
        {return n*price;}
    std::ostream& print_total(std::ostream& os, const size_t n)
        {os << bookNo << " : " << net_price(n); return os;}

private:
    std::string bookNo;
protected:
    double price = 0.0;
    size_t maxDisc = 0;
};

class Bulk_quote: public Quote{
public:
    Bulk_quote(const std::string &book, double p, size_t limit,
               size_t qty, double disc) :
               Quote(book, p, limit), min_qty(qty), discount(disc){}
    Bulk_quote(const std::string &book, double p, size_t lim,double disc):
               Quote(book, p, lim), discount(disc) {}

    double net_price(const size_t n) const override;
private:
    size_t min_qty = 0;
    double discount = 0.0;
};

size_t min(size_t n, size_t m)
{
    return (n ^ ((m^n) & -(m < n)));
}

double Bulk_quote::net_price(const size_t n) const
{
    if (min_qty <= n){
        size_t discounted = min(n, maxDisc);
        double ret = (price * (1 - discount) * discounted);
        return (discounted < n) ? ret + price*(n-discounted) : ret; 
    }
    else 
        return price * n;
}

int main(){
    Bulk_quote bq("Mobydick", 49.99, 10, 15, 0.15);
    Quote q("Catcher in the rye", 49.99, 10);
    Quote &q2 = bq;
    bq.print_total(std::cout, 15);
    std::cout << std::endl;
    q2.print_total(std::cout, 10);
}