#include <iostream>
class IntNode {
public:
  int item;
  IntNode *next;

  IntNode(int f, IntNode *r) {
    item = f;
    next = r;
  }
};

class SLList {
private:
  IntNode *sentinel;
  int count;

public:
  /**
   * @brief Construct a new empty list
   *
   */
  SLList() {
    count = 0;
    sentinel = new IntNode(63, nullptr);
  }
  /**
   * @brief Construct a new SLLIst object
   *
   * @param x the first element
   */
  SLList(int x) {
    count = 0;
    sentinel = new IntNode(63, nullptr);
    addFirst(x);
  }

  /**
   * @brief Prepend the list with item x
   *
   */
  void addFirst(int x) {
    count = count + 1;
    sentinel->next = new IntNode(x, sentinel->next);
  }

  /**
   * @brief Get the sentinel object
   *
   * @return int& the sentinel element in list
   */
  int &getFirst() { return sentinel->next->item; }

  /**
   * @brief Append the list with given item x
   *
   * @param x the item
   */
  void addLast(int x) {
    count = count + 1;

    IntNode *p = sentinel;
    while (p->next != nullptr) {
      p = p->next;
    }
    // p is pointing to the last node
    p->next = new IntNode(x, nullptr);
  }

  int size() { return count; }
};
