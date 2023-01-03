#include <cstdlib>
#include <iostream>
#include <string>
#include "GenericLinkedList.cpp"

using namespace std;
using std::string;

int run_test() {
  SLinkedList<string> newList;
  newList.addFront("First");
  newList.addFront("Second");
  while (!newList.empty()) {
    cout << newList.front() << endl;
    newList.removeFront();
  };

  return EXIT_SUCCESS;
};

int main() {
  run_test();
  return EXIT_SUCCESS;
};