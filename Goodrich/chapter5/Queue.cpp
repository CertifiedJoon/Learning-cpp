#include <cstdlib>
#include "../chapter2/exceptions.h"


template <typename E>
class Queue {
  public:
    Queue(int cap): f(0), r(0), n(0), capacity(cap), p(new E[cap]) {};
    ~Queue();
    int size() const;
    bool empty() const;
    const E& front() const;
    void enqueue (const E&);
    void dequeue ();
  private:
    int f;
    int r;
    int n;
    int capacity;
    int *p;
};

template <typename E> 
Queue<E>::~Queue() {
  f = 0;
  r = 0;
  n = 0;
  capacity = 0;
  delete[] p;
}

template <typename E>
int Queue<E>::size() const {
  return n;
}

template <typename E>
bool Queue<E>::empty() const {
  return n == 0;
}

template <typename E>
const E& Queue<E>::front() const {
  if (empty()) throw QueueEmpty("Cannot front(). Queue is empty.");
  return p[f % capacity];
}

template <typename E>
void Queue<E>::enqueue(const E& e) {
  if (n == capacity) throw QueueFull("Cannot enqueue. Queue is full.");
  p[r % capacity] = e;
  r = (r + 1) % capacity;
  ++n;
}

template <typename E>
void Queue<E>::dequeue() {
  if (empty()) throw QueueEmpty("Cannot dequeue. Queue is empty");
  f = (f + 1) % capacity;
  --n;
}