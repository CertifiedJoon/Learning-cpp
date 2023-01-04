#include <cstdlib>
#include <iostream>
#include <queue>
#include "Queue.cpp"
#include "CircleListQueue.cpp"

using namespace std;
using std::queue;

int main() {
  queue<int> stdQueue;
  for (int i = 1; i <= 12; i++) {
    stdQueue.push(i);
  }
  for (int i = 0; i < 12; i++) {
    cout << stdQueue.front();
    stdQueue.pop();
  }

  cout << endl;
  cout << "MY Queue================" << endl;

  Queue<int> myQueue(10);
  for (int i = 0; i < 10; i++) {
    myQueue.enqueue(i + 1);
  }
  for (int i = 0; i < 10; i++) {
    cout << myQueue.front();
    myQueue.dequeue();
  }
  cout << endl;

  cout << endl;
  cout << "MY CQueue================" << endl;

  LinkedQueue cQueue;
  for (int i = 0; i < 12; i++) {
    cQueue.enqueue("a");
  }
  for (int i = 0; i < 12; i++) {
    cout << cQueue.front();
    cQueue.dequeue();
  }
  cout << endl;

}