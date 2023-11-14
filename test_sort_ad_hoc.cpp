#include "Sort.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/** Tests the sort method of the Sort class. */
void testSort() {
  vector<string> input{"beware", "of", "falling", "rocks"};
  vector<string> expected{"beware", "falling", "of", "rocks"};

  Sort::sort(input);

  if (input == expected) {
    cout << "Output as expected" << endl;
  } else {
    cout << "Mismatch" << endl;
  }
}

int main() {
  testSort();
  return 0;
}
