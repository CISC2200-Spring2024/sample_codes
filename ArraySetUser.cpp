#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "ArraySet.h"
#include <doctest.h>
#include <iostream>
#include <string>

using namespace std;

TEST_CASE("constructor and destructor and size") {
  ArraySet<int> aset;
  CHECK(aset.size() == 0);
  ArraySet<string> aset2;
  CHECK(aset2.size() == 0);
}

TEST_CASE("add and contains") {
  ArraySet<int> aset;
  aset.add(5);
  aset.add(10);
  aset.add(15);
  aset.add(15); // this should do nothing
  CHECK(aset.size() == 3);
  CHECK(aset.contains(5) == true);
  CHECK(aset.contains(25) == false);
}

TEST_CASE("iterator") {
  ArraySet<int> aset;
  aset.add(5);
  aset.add(10);
  aset.add(15);
  aset.add(15); // this should do nothing
  for (int i : aset) {
    cout << i << endl;
  }

  ArraySet<int>::iterator it = aset.begin();
  while (it != aset.end()) {
    cout << *it << endl;
    ++it;
  }
}