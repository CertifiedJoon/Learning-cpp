#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class numbered;

void f(const numbered &s);
void make_serial (numbered &s);

class numbered{
    friend void f(const numbered &s);
    friend void make_serial(numbered &s);
public:
    numbered(const numbered &n);
    numbered(const std::string& s);

    std::string mysn;
    std::string name;
    static int serial;
};
int numbered::serial;

void f (const numbered &s)
{
    std::cout << s.name << " : "<<s.mysn << std::endl;
}

void make_serial(numbered &n){
    std::ostringstream oss;
    oss << std::setw(8) << std::setfill('0') << ++numbered::serial;
    n.mysn = oss.str();
}

numbered::numbered(const std::string &s){
    name = s;
    make_serial(*this);
}

numbered::numbered(const numbered &n)
{
    name = n.name;
    make_serial(*this);
}

int main()
{
    numbered a ("Jean Valjean");
    numbered b = a;
    numbered c = b;
    f(a); f(b); f(c);
}