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
  IntNode * first;
  int count;

public:
  /**
   * @brief Construct a new empty list
   *
   */
  SLList() {
    count = 0;
    first = NULL;
  }
  /**
   * @brief Construct a new SLLIst object
   *
   * @param x the first element
   */
  SLList(int x) {
    addFirst(x);
  }

  /**
   * @brief Prepend the list with item x
   *
   */
  void addFirst(int x) {
    count = count + 1;
    first = new IntNode(x, first);
  }

  /**
   * @brief Get the sentinel object
   *
   * @return int& the sentinel element in list
   */
  int &getFirst() { return first->item; }

  /**
   * @brief Append the list with given item x
   *
   * @param x the item
   */
  void addLast(int x) {
    //Todo by you
  }

  int size() { return count; }
};
