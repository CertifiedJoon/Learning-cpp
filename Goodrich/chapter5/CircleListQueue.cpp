#include <cstdlib>
#include "../chapter2/exceptions.h"
#include "../chapter3/CircularLinkedList.cpp"

typedef string Elem;
class LinkedQueue {
  public:
    LinkedQueue() : n(0), C() {}
    int size() const;
    bool empty() const;
    const Elem& front() const;
    void enqueue(const Elem& e);
    void dequeue();
  private:
    CircleList C;
    int n;
};

int LinkedQueue::size() const {
  return n;
}

bool LinkedQueue::empty() const {
  return n == 0;
}

const Elem& LinkedQueue::front() const {
  if (empty()) throw QueueEmpty("Cannot front. Queue is empty.");
  return C.front();
}

void LinkedQueue::enqueue(const Elem& e) {
  C.add(e);
  C.advance();
  n++;
}

void LinkedQueue::dequeue() {
  if (empty()) throw QueueEmpty("Cannot dequeue. Queue is empty.");
  C.remove();
  n--;
}