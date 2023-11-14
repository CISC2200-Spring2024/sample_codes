#include <iostream>

int larger(int x, int y) {
  if (x > y) {
    return x;
  }
  return y;
}

double larger(double x, double y) {
  if (x > y) {
    return x;
  }
  return y;
}

int main() {
  std::cout << larger(5, 10) << std::endl;
  std::cout << larger(0.1, 5.5) << std::endl;
  return 0;
}

/**
 * 1. Functions must be declared before using.
 * 2. All parameters of a function must have a delcared type.
 *    The return value of the function must have a declared type.
 * 3. Functions return only one value!
 */