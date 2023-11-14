class IntNode {
public:
  int item;
  IntNode *next;
  IntNode *prev;

  IntNode(int f, IntNode *p = nullptr, IntNode *n = nullptr) {
    item = f;
    prev = p;
    next = n;
  }
};

class DLList {
private:
  IntNode *sentFront, *sentBack;
  int count;

public:
  /**
   * @brief Construct a new empty list
   *
   */
  DLList() {
    count = 0;
    sentFront = new IntNode(63);
    sentBack = new IntNode(63);
    sentFront->next = sentBack;
    sentBack->prev = sentFront;
  }

  void addFirst(int i) {
    count = count + 1;
    IntNode *x = new IntNode(i, sentFront, sentFront->next);
    sentFront->next = x;
    x->next->prev = x;
  }

  void addLast(int i) {
    count = count + 1;
    IntNode *x = new IntNode(i, sentBack->prev, sentBack);
    sentBack->prev = x;
    x->prev->next = x;
  }

  int &getFirst() { return sentFront->next->item; }

  int &getLast() { return sentBack->prev->item; }

  int size() { return count; }
};
