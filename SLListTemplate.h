template <typename T> class Node {
public:
  T item;
  Node<T> *next;

  Node(T f, Node<T> *r) {
    item = f;
    next = r;
  }
};

template <typename T> class SLList {
private:
  Node<T> *sentinel;
  int count;

public:
  /**
   * @brief Construct a new empty list
   *
   */
  SLList() {
    count = 0;
    sentinel = new Node<T>(T(), nullptr);
  }
  /**
   * @brief Construct a new SLLIst object
   *
   * @param x the first element
   */
  SLList(int x) {
    count = 0;
    sentinel = new Node<T>(T(), nullptr);
    addFirst(x);
  }

  /**
   * @brief Prepend the list with item x
   *
   */
  void addFirst(T x) {
    count = count + 1;
    sentinel->next = new Node<T>(x, sentinel->next);
  }

  /**
   * @brief Get the sentinel object
   *
   * @return int& the sentinel element in list
   */
  T &getFirst() { return sentinel->next->item; }

  /**
   * @brief Append the list with given item x
   *
   * @param x the item
   */
  void addLast(T x) {
    count = count + 1;

    Node<T> *p = sentinel;
    while (p->next != nullptr) {
      p = p->next;
    }
    // p is pointing to the last node
    p->next = new Node<T>(x, nullptr);
  }

  int size() { return count; }
};