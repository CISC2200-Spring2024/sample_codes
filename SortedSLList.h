#include "SortedList.h"

template <typename T> class Node {
public:
  T item;
  Node<T> *next;

  Node(T f, Node<T> *r) {
    item = f;
    next = r;
  }
};

template <typename T> class SortedSLList : public SortedList<T> {
private:
  Node<T> *sentinel;
  int count;

public:
  /**
   * @brief Construct a new empty list
   *
   */
  SortedSLList() {
    count = 0;
    sentinel = new Node<T>(T(), nullptr);
  }

  int size() const { return count; }

  T &get(int position) {}

  T &smallest() {}

  T &greatest() {}

  virtual void put(const T &x) {
    // TODO:
  }

  virtual T remove(int position) {
    // TODO:
  }

  void removeDuplicates() { removeDuplicatesHelp(sentinel->next); }

  void addFirst(T x) {
    count = count + 1;
    sentinel->next = new Node<T>(x, sentinel->next);
  }

private:
  void removeDuplicatesHelp(Node<T> *p) {
    if (p == nullptr) {
      return;
    }
    Node<T> *current = p->next;
    Node<T> *previous = p;
    while (current != nullptr) {
      if (current->item == previous->item) {
        previous->next = current->next;
        count--;
        delete current;
      } else {
        previous = previous->next;
      }
      current = previous->next;
    }
  }
};