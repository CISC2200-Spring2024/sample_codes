class IntList {
private:
  int first;
  IntList *rest;

public:
  IntList(int f, IntList *r) {
    first = f;
    rest = r;
  }

  /**
   * @brief Returns the number of items in the list
   *
   * @return int count for the list
   */
  int size() {
    // base case: the smallest problem that we can solve using this method
    if (rest == nullptr) { // NULL or nullptr
      return 1;
    }
    // recursive part: shrink the size of the problem
    // we no longer want to know the size of the whole list,
    // but the size of the "rest" list
    return 1 + rest->size();
  }

/**
 * @brief Retrieve the i-th element (i.e., int) in the list
 * 
 * @param i index of element
 * @return int& the reference to the first element
 */
  int &get(int i) {
    if (i == 0)
      return first;
    return rest->get(i - 1);
  }
};
