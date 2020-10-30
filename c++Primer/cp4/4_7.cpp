#include <iostream>
#include <vector>

using namespace std;
int main(){
    unsigned grade = 90;

    string finalgrade = (grade > 90) ? "high pass"
                                        : (grade > 60) ? "pass" : "fail";
}
