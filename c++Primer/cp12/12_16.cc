#include <memory>
#include <iostream>
int main()
{
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    
    typedef std::unique_ptr<int> intp;
    intp p0(&ix);
    intp p1(pi);
    
    std::cout << *p0;
}