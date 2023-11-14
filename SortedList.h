template <typename Item> class SortedList {
public:
  virtual int size() const = 0;
  virtual Item &get(int position) = 0;
  virtual Item remove(int position) = 0;
  virtual void put(const Item &x) = 0;
  virtual Item &smallest() = 0;
  virtual Item &greatest() = 0;
};

