#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Sort.h"
#include <doctest.h>
#include <string>
#include <vector>

using namespace std;

TEST_CASE("testFindSmallest") {
  vector<string> input{"cows", "dwell", "above", "clouds"};
  int smallest = Sort::findSmallest(input, 0);
  CHECK(smallest == 2);
}

TEST_CASE("testSwap") {
  vector<string> input{"cows", "dwell", "above", "clouds"};
  vector<string> expected{"cows", "clouds", "above", "dwell"};
  Sort::swap(input, 1, 3);
  CHECK(input == expected);
}

/** Tests the sort method of the Sort class. */
TEST_CASE("testSort") {
  vector<string> input{"beware", "of", "falling", "rocks"};
  vector<string> expected{"beware", "falling", "of", "rocks"};

  Sort::sort(input);

  CHECK(input == expected);
}
