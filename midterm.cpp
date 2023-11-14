#include <iostream>
using namespace std;

void swap1(int x, int y) {
  int temp = y;
  y = x;
  x = temp;
  cout << x << endl;
}
void swap2(int &x, int &y) {
  int temp = y;
  y = x;
  x = temp;
  cout << x << endl;
}
void swap3(int *x, int *y) {
  int *temp = y;
  y = x;
  x = temp;
  cout << *x << endl;
}
class Animal {};
class Cat : public Animal {};
class Dog : public Animal {};
class Huskie : public Dog {};

class IntList {
public:
  int first;
  IntList *rest;
  IntList(int f, IntList *r) {
    first = f;
    rest = r;
  }
};
void next1(IntList *list) {
  list = list->rest;
}
IntList *next2(IntList *list) {
  list = list->rest;
  return list;
}
void next3(IntList *list) {
  IntList *temp = list;
  temp = temp->rest;
}

template <typename T> class Node {
public:
  T item;
  Node<T> *next;
  Node(T i, Node<T> *n) { item = i; next = n; }
};

template <typename T> class SortedSLList {
private:
  Node<T> *sentinel;
  int count;
public:
  SortedSLList() { count = 0; sentinel = new Node<T>(T(), nullptr); }

  /**
   * Given a sorted singly-linked list - remove duplicates.
   * For example given 1 -> 2 -> 2 -> 2 -> 3 -> 3,
   * Mutate it to become 1 -> 2 -> 3
   */
  void removeDuplicates() {
    removeDuplicatesHelp(sentinel->next);
  }
  void addFirst(int x) {
    count = count + 1;
    sentinel->next = new Node<T>(x, sentinel->next);
  }

  int size() { return count; }
private:
  /** Helper function for removeDuplicates */
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

int main() {
  SortedSLList<int> *aList = new SortedSLList<int>();
  aList->addFirst(10);
  aList->addFirst(10);
  aList->addFirst(10);
  aList->addFirst(10);
  aList->addFirst(10);
  aList->addFirst(1);
  cout << aList->size() << endl;
  aList->removeDuplicates();
  cout << aList->size() << endl;
}
