#include <cstdlib>
#include "../chapter2/exceptions.h"
#include "../chapter3/DoublyLinkedList.cpp"

typedef string Elem;
class LinkedDeque {
  public:
    LinkedDeque() : D(), n(0) {};
    int size() const;
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void insertFront(const Elem& e);
    void insertBack(const Elem& e);
    void removeFront();
    void removeBack();
  private:
    DLinkedList D;
    int n;
};

int LinkedDeque::size() const {
  return n;
}

bool LinkedDeque::empty() const {
  return n == 0;
}

const Elem& LinkedDeque::front() const {
  if (empty()) throw DequeEmpty("Cannot front. Deque is empty.");
  return D.front();
}

const Elem& LinkedDeque::back() const {
  if (empty()) throw DequeEmpty("Cannot back. Deque is empty.");
  return D.back();
}

void LinkedDeque::insertFront(const Elem& e) {
  D.addFront(e);
  ++n;
}

void LinkedDeque::insertBack(const Elem& e) {
  D.addBack(e);
  ++n;
}

void LinkedDeque::removeFront() {
  if (empty()) throw DequeEmpty("Cannot removeFront. Deque is empty.");
  D.removeFront();
  --n;
}

void LinkedDeque::removeBack() {
  if (empty()) throw DequeEmpty("Cannot removeBack. Deque is empty.");
  D.removeBack();
  --n;
}