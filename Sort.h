#include <string>
#include <vector>
using namespace std;

class Sort {
public:
  static int findSmallest(const vector<string> &x, int n) {
    int smallest = n;
    for (unsigned i = n + 1; i < x.size(); i++) {
      if (x.at(i) < x.at(smallest)) {
        smallest = i;
      }
    }
    return smallest;
  }

  static void swap(vector<string> &x, int a, int b) {
    string tmp = x[a];
    x[a] = x[b];
    x[b] = tmp;
  }

  static void sort(vector<string> &x) {
    for (unsigned i = 0; i < x.size(); i++) {
      int smallest = findSmallest(x, i);
      swap(x, i, smallest);
    }
  }
};
