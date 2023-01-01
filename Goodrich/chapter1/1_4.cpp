#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
using std::string;

int const_reference(const string& s){
  // s = "Changed"; // ILLEGAL
  cout << s << endl;
  return EXIT_SUCCESS;
};


int main() {
  const_reference("constant");
  return EXIT_SUCCESS;
};