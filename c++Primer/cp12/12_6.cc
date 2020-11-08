#include <iostream>
#include <vector>
#include <memory>

void read(std::shared_ptr<std::vector<int>> v);
void print(std::shared_ptr<std::vector<int>> v);
std::shared_ptr<std::vector<int>> allocate();

int main()
{
    std::shared_ptr<std::vector<int>> v = allocate();
    read(v);
    print(v);
}

void print(std::shared_ptr<std::vector<int>> v){
    for (auto i : *v)
        std::cout << i << std::endl;
}

void read(std::shared_ptr<std::vector<int>> v){
    int i;
    while (std::cin >> i){
        v->push_back(i);
    }
}

std::shared_ptr<std::vector<int>> allocate (){
    return std::make_shared<std::vector<int>>();
}