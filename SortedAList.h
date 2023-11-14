#include "SortedList.h"

template <typename Item> class SortedAList : public SortedList<Item> {
private:
  Item *items; // pointer pointing to the underlying Item arary
  int maxCnt;  // the size of array "items"
  int count;   // # of items in list, aka size of list

public:
  /**
   * @brief Construct a new Sorted A List object
   *
   * @param initSize default to 100
   */
  SortedAList(int initSize = 100) {
    count = 0;
    maxCnt = initSize;
    items = new Item[maxCnt];
  }

  ~SortedAList() { delete[] items; }

  virtual int size() const override { return count; }

  virtual Item &smallest() { return items[0]; }

  virtual Item &greatest() { return items[count - 1]; }

  virtual Item &get(int position) { return items[position]; }

  virtual void put(const Item &x) {
    // TODO:
  }

  virtual Item remove(int position) {
    // TODO:
  }
};
