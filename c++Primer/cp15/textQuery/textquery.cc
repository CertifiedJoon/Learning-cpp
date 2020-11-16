#include <string>
#include <map>
#include <set>
#include <memory>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

#include "textquery.h"
#include "WordQuery.h"
#include "NotQuery.h"
#include "OrQuery.h"
#include "AndQuery.h"

int main(){
    Query a = Query("devils") | Query("God");
    std::ifstream fin("input.txt");
    TextQuery tq1(fin);

    print(std::cout, a.eval(tq1)) << std::endl;
}