#ifndef __SLLIST_H__
#define __SLLIST_H__

#include "List.h"
#include <iostream>

/** Node in singly linked list. */
template <typename ItemType> class Node {
public:
  ItemType item;
  Node *next;

  Node(ItemType i, Node *n = nullptr) {
    item = i;
    next = n;
  }
};

/** Singly linked list. */
template <typename ItemType> class SLList : public List<ItemType> {

private:
  /** Pointer pointing to the sentinel node. */
  Node<ItemType> *sentinel;

  /** Stores the current size of the list. */
  size_t count;

public:
  /** Construct a new SLList object. */
  SLList() {
    sentinel = new Node<ItemType>(ItemType(), nullptr);
    count = 0;
  }

  /** Return the number of elements in list. */
  size_t size() const override { return count; }

  /** Add x at the beginning of the list. */
  void addFirst(const ItemType &x) override {
    count += 1;
    sentinel->next = new Node<ItemType>(x, sentinel->next);
  }

  /** Append the list with x. */
  void addLast(const ItemType &x) override {
    count += 1;
    Node<ItemType> *p = sentinel;
    while (p->next != nullptr) {
      p = p->next;
    }
    p->next = new Node<ItemType>(x, nullptr);
  }

  /** Return the first element. */
  ItemType &getFirst() override { return get(0); }

  /** Return the first element. */
  ItemType &getLast() override { return get(count - 1); }

  // void print(std::ostream &os) const override {
  //   os << "[";
  //   for (Node<ItemType> *p = sentinel->next; p != nullptr; p = p->next) {
  //     if (p != sentinel->next) {
  //       os << ",";
  //     }
  //     os << p->item;
  //   }
  //   os << "]";
  // }

  SLList(const SLList<ItemType> &other) {
    count = other.count;
    Node<ItemType> *thisPrev = sentinel =
        new Node<ItemType>(ItemType(), nullptr);
    Node<ItemType> *otherFirst = other.sentinel->next;
    while (otherFirst != nullptr) {
      thisPrev = thisPrev->next = new Node<ItemType>(otherFirst->item);
      otherFirst = otherFirst->next;
    }
  }

  ~SLList() {
    count = 0;
    while (sentinel != nullptr) {
      Node<ItemType> *curr = sentinel;
      sentinel = sentinel->next;
      delete curr;
    }
  }

  ItemType &get(int i) override {
    Node<ItemType> *p = sentinel->next;
    for (int j = 0; j < i; j++)
      p = p->next;
    return p->item;
  }

  const ItemType &get(int i) const override {
    Node<ItemType> *p = sentinel->next;
    for (int j = 0; j < i; j++)
      p = p->next;
    return p->item;
  }

  ItemType removeFirst() override {
    ItemType it = sentinel->next->item;
    Node<ItemType> *del = sentinel->next;
    sentinel->next = sentinel->next->next;
    delete del;
    count -= 1;
    return it;
  }

  ItemType removeLast() override {
    Node<ItemType> *prev = sentinel;
    Node<ItemType> *del = prev->next;
    while (del->next != nullptr) {
      prev = prev->next;
      del = del->next;
    }
    ItemType it = del->item;
    prev->next = nullptr;
    delete del;
    count -= 1;
    return it;
  }

  void insert(const ItemType &x, int i) override {
    Node<ItemType> *p = sentinel;
    for (int j = 0; j < i; j++) {
      p = p->next;
    }
    p->next = new Node<ItemType>(x, p->next);
    count += 1;
  }

  ItemType remove(int i) override {
    Node<ItemType> *prev = sentinel;
    Node<ItemType> *del = prev->next;
    for (int j = 0; j < i; j++) {
      prev = prev->next;
      del = del->next;
    }
    ItemType it = del->item;
    prev->next = del->next;
    delete del;
    count -= 1;
    return it;
  }

  void concatDirect(const SLList<ItemType> &other) {
    count += other.count;
    Node<ItemType> *p = sentinel;
    while (p->next != nullptr) {
      p = p->next;
    }
    p->next = other.sentinel->next;
  }

  void concat(const SLList<ItemType> &other) {
    count += other.count;
    Node<ItemType> *p = sentinel;
    while (p->next != nullptr) {
      p = p->next;
    }
    Node<ItemType> *otherFirst = other.sentinel->next;
    while (otherFirst != nullptr) {
      p = p->next = new Node<ItemType>(otherFirst->item, nullptr);
      otherFirst = otherFirst->next;
    }
  }

  // void concat(const SLList<ItemType> &other) {
  //   Node<ItemType> *curr = sentinel;
  //   while (curr->next != nullptr) {
  //     curr = curr->next;
  //   }
  //   Node<ItemType> *newNode = new Node<ItemType>(other.sentinel->item, nullptr);
  //   Node<ItemType> *nextNode = newNode->next;
  //   int num = other.count;
  //   for (int i = 0; i < num; i++) {
  //     curr->next = newNode;
  //     curr = newNode;
  //     newNode = new Node<ItemType>(nextNode->item, nullptr);
  //   }
  //   count += other.count;
  // }

};

#endif // __SLLIST_H__