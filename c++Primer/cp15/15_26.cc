#include <string>
#include <iostream>
#include <cstddef>
class Quote{
public:
    Quote(): bookNo(""), price(0.0) {std::cout << "q default\n";}
    Quote(const std::string &book, double original_price):
          bookNo(book), price(original_price){}
    Quote(const Quote& q): bookNo(q.bookNo), price(q.price) {std::cout<<"q copy\n";}
    Quote(Quote&& q) : bookNo(std::move(q.bookNo)), price(std::move(q.price)) {std::cout<<"q move\n";}
    virtual ~Quote() {std::cout<<"q destructor\n";}

    Quote& operator=(const Quote&);

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

Quote& Quote::operator=(const Quote& q)
{
    bookNo = q.bookNo;
    price  = q.price;
    std::cout<<"q copy assignment\n";
    return *this;
}

class Bulk_quote: public Quote{
public:
    Bulk_quote(const std::string &book, double p,
               size_t qty, double disc) :
               Quote(book, p), min_qty(qty), discount(disc){}
    Bulk_quote(const std::string &book, double p, double disc):
               Quote(book, p), discount(disc) {}
    Bulk_quote(): min_qty(0), discount(0.0) {std::cout<<"bq default\n";}
    Bulk_quote(const Bulk_quote& b): Quote(b), min_qty(b.min_qty), discount(b.discount) 
                                    {std::cout<<"bq copy\n";}
    Bulk_quote(Bulk_quote&& b): Quote(std::move(b)), min_qty(std::move(b.min_qty)), discount(std::move(b.discount))
                                {std::cout<<"bq move\n";}
    ~Bulk_quote() {std::cout<<"bq destructor\n";}

    Bulk_quote& operator=(const Bulk_quote&);

    double net_price(const size_t n) const override;
    std::ostream& debug(std::ostream& os) const override;
private:
    size_t min_qty = 0;
    double discount = 0.0;
};

Bulk_quote& Bulk_quote::operator=(const Bulk_quote &bq)
{
    Quote::operator=(bq);
    min_qty = bq.min_qty;
    discount = bq.discount;
    std::cout<<"bq copy assignment\n";
    return *this;
}

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
    Bulk_quote basic;
    Bulk_quote bq("Mobydick", 49.99, 10, 0.15);
    Bulk_quote bq1("catcher in the rye", 39.99, 10, 0.1);
    Bulk_quote bq2(bq);
    bq1 = bq;

}