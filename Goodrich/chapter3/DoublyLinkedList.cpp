#include <cstdlib>
#include <string>

typedef std::string Elem;

class DLinkedList;

class DNode {
  private:
    Elem elem;
    DNode *prev;
    DNode *next;
    friend class DLinkedList;
};

class DLinkedList {
  public:
    DLinkedList();
    ~DLinkedList();
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void addFront(const Elem& e);
    void addBack(const Elem& e);
    void removeFront();
    void removeBack();
  private:
    DNode* header;
    DNode* tailer;
  protected:
    void add(DNode* v, const Elem& e);
    void remove(DNode* v);
};

DLinkedList::DLinkedList(): header(NULL), tailer(NULL) {};
DLinkedList::~DLinkedList() {
  delete header;
  delete tailer;
}

bool DLinkedList::empty() const {
  return header == NULL;
};

const Elem& DLinkedList::front() const {
  return header->elem;
}

const Elem& DLinkedList::back() const {
  return tailer->elem;
}

void DLinkedList::addFront(const Elem& e) {
  DNode* newNode = new DNode;
  newNode->elem = e;
  newNode->next = header;
  header = newNode;
}

void DLinkedList::addBack(const Elem& e) {
  DNode* newNode = new DNode;
  newNode->elem = e;
  tailer->next = newNode;
  tailer = newNode;
}

void DLinkedList::removeFront() {
  DNode* temp = header;
  header = header->next;
  delete temp;
}

void DLinkedList::removeBack() {
  DNode* temp = tailer;
  tailer = tailer->prev;
  delete temp;
}

void DLinkedList::add(DNode* v, const Elem& e) {
  DNode* newNode = new DNode;
  newNode->elem = e;
  newNode->next = v;
  newNode->prev = v->prev;
}

void DLinkedList::remove(DNode* v){
  DNode* temp = v;
  v->prev->next = v->next;
  delete temp;
}

