#ifndef SALES_DATA_H
#define SALES_DATA_H

struct Sales_data;
std::istream &read(std::istream&, Sales_data&);

struct Sales_data {

    Sales_data(const std::string &s, unsigned u, double p):
               bookNo(s), units_sold(u), revenue(p*u) {std::cout << 2;}
    Sales_data(std::istream &is) {read(is, *this);}
    Sales_data(std::string s = ""): Sales_data(s,0,0) {std::cout << 2;}

    std::string bookNo;
    unsigned units_sold;
    double revenue;

    std::string isbn() const{return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

};

Sales_data add (const Sales_data&, const Sales_data&);
std::ostream &print (std::ostream&, const Sales_data&);
std::istream &read (std::istream&, Sales_data&);

inline
double Sales_data::avg_price() const{
    if (units_sold)
        return revenue / units_sold;
    return 0.0;
}

Sales_data& Sales_data::combine (const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream &read(std::istream &is, Sales_data &item){
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() <<  " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();

    return os;
}

Sales_data add (const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
#endif
