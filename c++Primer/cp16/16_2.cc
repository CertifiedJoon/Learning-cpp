#include <string>
#include <iostream>

template<typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int main(){
    std::string s("joon"), t("fred");
    std::cout<<compare(s, t) <<std::endl;
}