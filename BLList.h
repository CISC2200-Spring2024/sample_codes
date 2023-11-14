template <typename T> class Node {
public:
  T item;
  Node<T> *prev;
  Node(T i, Node<T> *p) {
    item = i;
    prev = p;
  }
};
template <typename T> class BLList {
private:
  Node<T> *sentinel;
  int count;

public:
  BLList() {
    sentinel = new Node<T>(T(), nullptr);
    count = 0;
  }
  ~BLList() {
    count = 0;
    while (sentinel != nullptr) {
      Node<T> *curr = sentinel;
      sentinel = sentinel->prev;
      delete curr;
    }
  }
  void addLast(T item) {
    count++;
    sentinel->prev = new Node<T>(item, sentinel->prev);
  }

  T get(int i, Node<T> *p) {
    if (i == 0)
      return p->item;
    return get(i - 1, p->prev);
  }

  T get(int i) { return get(count - i - 1, sentinel->prev); }
};
