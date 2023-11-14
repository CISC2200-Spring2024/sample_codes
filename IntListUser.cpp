#include <iostream>
#include "IntList.h"
using namespace std;

int main() {
  IntList *aList = new IntList(5, NULL);
  IntList *x = new IntList(10, aList);
  cout << x->get(1) << endl;
  return 0;
}