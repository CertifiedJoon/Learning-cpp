#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include "Stack.cpp"

using namespace std;
using std::string;
using std::stack;

int main() {
  stack<string> stdStack;
  stdStack.push("first");
  cout << stdStack.top() << endl;

  Stack<string> myStack(10);
  myStack.push("first");
  cout << myStack.top() << endl;

  return EXIT_SUCCESS;
}
