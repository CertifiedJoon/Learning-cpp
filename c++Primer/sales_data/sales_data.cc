#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include "sales_data.h"

using namespace std;

int main (){
    istream_iterator in(cin), eof;
    ostream_iterator out(cout);

    vector<Sales_data> v(in, eof);
    sort(v.begin(), v.end(), compareIsbn);

    vector<Sales_data>::iterator it = v.begin();
    
    
    while(it != v.end()){
        sum = accumulate(it, v.end(), 0); 
    }
}