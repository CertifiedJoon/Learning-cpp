#include <cstdlib>
#include <string>
#include "../chapter2/exceptions.h"

using std::string;

template <typename E>
class Stack {
  public:
    Stack(int c): p(new E[c]), len(0), capacity(c) {}
    ~Stack();
    int size() const;
    bool empty() const;
    const E& top() const;
    void push(const E& e);
    void pop();
  private:
    int len;
    int capacity;
    E* p;
};

template <typename E>
bool Stack<E>::empty() const {
  return len == 0;
};

template <typename E>
Stack<E>::~Stack() {
  delete[] p;
  len = 0;
}

template <typename E>
int Stack<E>::size() const {
  return len;
}

template <typename E>
const E& Stack<E>::top() const {
  if (empty()) throw StackEmpty("Cannot Top. Stack is empty.");
  return p[len - 1];
}

template <typename E>
void Stack<E>::push(const E& e) {
  if (size() == capacity) throw StackFull("Cannot push. Stack is full");
  p[len++] = e;
}

template <typename E>
void Stack<E>::pop() {
  if (empty()) throw StackEmpty("Cannot pop. Stack is empty");
  --len;
}