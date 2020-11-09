#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <memory>
#include <set>
#include <map>
#include "query.h"

void runQueries (std::ifstream &fin);

int main(int argc, char *argv[]) {
    std::ifstream fin("input.txt");
    runQueries(fin);
}

void runQueries (std::ifstream &fin)
{
    TextQuery tq1(fin);
    TextQuery tq2 = tq1;
    TextQuery tq3(tq2);
    std::cout << "constrution successful" << std::endl;
    while(true)
    {
        std::cout << "Enter a word to search or enter q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq3.query(s)) << std::endl;
    }
}