#include "SLList.h"

int main() {
  SLList l;
  int i = 0;
  while (i < 1000000) {
      l.addFirst(i);
      i += 1;
  }
}