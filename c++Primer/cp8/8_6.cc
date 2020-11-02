#include <iostream>
#include <fstream>
#include <string>
#include "sales_data.h"

using namespace std;

int main(int argc, char* argv[]){
    ifstream fin(argv[1]);
    ofstream fout(argv[2], ofstream::app);

    Sales_data total;
    if (read(fin, total)){
        Sales_data trans;
        while(read(fin, trans)){
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else{
                print(fout, total) << endl;
                total = trans;
            }
        }
        print(fout, total) << endl;
    } else {
        cerr << "No data you fuck" << endl;
    }
}