#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
using std::string;

int integer_division() {
    int i1 = 18;
    int i2 = 16;
    double res = double(i1) / double(i2);
    cout << res << endl;

    return EXIT_SUCCESS;
};

int static_cast_intro() {
    double d1 = 1.234;
    int i1 = static_cast<int>(d1);
    cout << i1 << endl;

    return EXIT_SUCCESS;
};

int main() {
//   integer_division();
  static_cast_intro();

  return EXIT_SUCCESS;
};