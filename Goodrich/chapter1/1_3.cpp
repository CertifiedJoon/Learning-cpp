#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
using std::string;

int switch_intro() {
  char command;
  cin >> command;
  
  switch (command) {
    case 'W':
      break;
    case 'A':
      break;
    case 'S':
      break;
    case 'D':
      break;
    default:
      cout << "Unrecognized command\n";
      break;
  }

  return EXIT_SUCCESS;
};

int main() {
  switch_intro();

  return EXIT_SUCCESS;  
};