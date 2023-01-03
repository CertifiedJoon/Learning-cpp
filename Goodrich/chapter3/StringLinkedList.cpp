#include <string>

using std::string;

class StringNode {
  private:
    string elem;
    StringNode* next;
    friend class StringLinkedList; 
};

class StringLinkedList {
  public:
    StringLinkedList();
    ~StringLinkedList();
    bool empty() const;
    const string& front() const;
    void addFront(const string& e);
    void removeFront();
  private:
    StringNode* head;
};

StringLinkedList::StringLinkedList(): head(NULL) {};

StringLinkedList::StringLinkedList() {
  while (!empty()) removeFront();
};

bool StringLinkedList::empty() const {
  return head == NULL;
};

const string& StringLinkedList::front() const {
  return head->elem;
};

void StringLinkedList::addFront(const string& e) {
  StringNode* newFront = new StringNode;
  newFront->elem = e;
  newFront->next = head;
  head = newFront;
}

void StringLinkedList::removeFront() {
  StringNode *temp = head;
  head = head->next;
  delete temp;
}