#include <cstdlib>

template<typename T>
class SLinkedList;

template <typename T>
class SNode {
  private:
    T elem;
    SNode<T>* next;
    friend class SLinkedList<T>; 
};

template <typename T>
class SLinkedList {
  public:
    SLinkedList();
    ~SLinkedList();
    bool empty() const;
    const T& front() const;
    void addFront(const T& e);
    void removeFront();
  private:
    SNode<T>* head;
};

template <typename T>
SLinkedList<T>::SLinkedList(): head(NULL) {};

template <typename T>
SLinkedList<T>::~SLinkedList() {
  while (!empty()) removeFront();
};

template <typename T>
bool SLinkedList<T>::empty() const {
  return (head == NULL);
};

template <typename T>
const T& SLinkedList<T>::front() const {
  return head->elem;
};

template <typename T>
void SLinkedList<T>::addFront(const T& e) {
  SNode<T>* newFront = new SNode<T>;
  newFront->elem = e;
  newFront->next = head;
  head = newFront;
}

template <typename T>
void SLinkedList<T>::removeFront() {
  SNode<T> *temp = head;
  head = head->next;
  delete temp;
}