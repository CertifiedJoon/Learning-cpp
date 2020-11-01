#ifndef PERSON_H
#define PERSON_H

struct person;
std::istream&read(std::istream &, person&);

struct person{
    friend std::istream &read (std::istream&, person);
    friend std::ostream &print (std::ostream&, person);
    public:
        person() = default;
        person(const std::string &n) : name(n), address(""){}
        person(const std::string &n, const std::string &a):
                name(n), address(a) {}
        person(std::istream &is) {read(is, *this)}

        std::string name() const {return name;}
        std::string address() const {return address;}
    private:
        std::string name;
        std::string address;
};

std::istream &read (std::istream &is, person &p)
{
    is >> p.name >> p.address;
    return is;
}

std::ostream &print (std::ostream &os, const person &p)
{
    os << p.name() << " " << p.address();
    return os;
}

#endif
