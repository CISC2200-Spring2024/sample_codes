#include "SortedSLList.h"
#include <iostream>

int main() {
  SortedSLList<int> a;
  a.addFirst(15);
  a.addFirst(15);
  a.addFirst(15);
  a.addFirst(10);
  a.addFirst(10);
  // a.addFirst(5);
  // a.addFirst(5);
  // a.addFirst(5);
  // a.addFirst(5);
  a.removeDuplicates();
  std::cout << a.size();
  return 0;
}