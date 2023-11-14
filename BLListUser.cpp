#include "BLList.h"
#include <iostream>

int main() {
  BLList<int> list;
  list.addLast(1);
  list.addLast(2);
  list.addLast(3);
  std::cout << list.get(0) << list.get(1) << list.get(2) << std::endl;
}