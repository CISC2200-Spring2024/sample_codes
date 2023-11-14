template <typename T> class ArraySet {
private:
  T *items;
  int count;

public:
  /** Create an empty set. */
  ArraySet() {
    items = new T[100];
    count = 0;
  }

  /** Destroy the set. */
  ~ArraySet() { delete[] items; }

  /** Returns the number of values in set. */
  int size() const { return count; }

  /** Checks if x is in the set. */
  bool contains(T x) {
    // i: [0, count - 1]
    for (int i = 0; i < count; i++) {
      if (items[i] == x) {
        return true;
      }
    }
    return false;
  }

  /** Add x to the set if it is not in set. */
  void add(T x) {
    if (!contains(x)) {
      // Copied from addLast in AList:
      items[count] = x;
      count++;
    }
  }

  class iterator {
  private:
    /** Pointing to an item in the underlying array. */
    T *ptr_;

  public:
    /** Constructor */
    iterator(T *ptr) { ptr_ = ptr; }

    T &operator*() { return *ptr_; }

    iterator operator++() {
      this->ptr_ += 1;
      return *this;
    }

    bool operator==(const iterator &rhs) { return this->ptr_ == rhs.ptr_; }

    bool operator!=(const iterator &rhs) { return !(*this == rhs); }
  };

  /** Iterator whose pointer is pointing to the first value in items array. */
  iterator begin() { return iterator(items); }

  /** Iterator whose pointer is pointing to the memory box next to the last
   * value in items array. */
  iterator end() { return iterator(items + count); }
};
