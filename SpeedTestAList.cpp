#include "AList.h"

int main() {
  AList l;
  int i = 0;
  while (i < 1000000) {
      l.addLast(i);
      i += 1;
  }
}