#include <iostream>
#include "SLList.h"
using namespace std;

int main() {
  SLList *aList = new SLList(5);
  aList->addFirst(10);
  aList->addFirst(10);
  aList->addLast(10);
  aList->removeDuplicates();
  cout << aList->size();
  return 0;
}