#include <cstdlib>
#include <string>

using std::string;

typedef string Elem;

class CircleList;

class CNode{
  private:
    Elem elem;
    CNode* next;
    friend class CircleList;
};

class CircleList {
  public:
    CircleList();
    ~CircleList();
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void advance();
    void add(const Elem& e);
    void remove();
  private:
    CNode* cursor;
};

CircleList::CircleList(): cursor(NULL) {};
CircleList::~CircleList() {
  while(!empty()) remove();
}

bool CircleList::empty() const {
  return cursor == NULL;
}

const Elem& CircleList::front() const {
  return cursor->next->elem;
}

const Elem& CircleList::back() const {
  return cursor->elem;
}

void CircleList::advance() {
  cursor = cursor->next;
}

void CircleList::add(const Elem& e) {
  CNode* newNode = new CNode;
  newNode->elem = e;
  if (cursor == NULL) {
    newNode->next = newNode;
    cursor = newNode;
  } else {
    newNode->next = cursor->next;
    cursor->next = newNode;
  }
}

void CircleList::remove() {
  CNode *temp = cursor->next;
  if (temp == cursor)
    cursor = NULL;
  else
    cursor->next = temp->next;
  delete temp;
}
