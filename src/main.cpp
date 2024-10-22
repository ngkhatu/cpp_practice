// Learncpp.com: section 11.1- Intro to Function Overloading

#include <iostream>

int add(int x, int y) { return x + y; }

double add(double x, double y) { return x + y; }

int main() {
  std::cout << add(1, 2); // calls add(int, int)
  std::cout << '\n';
  std::cout << add(1.2, 3.4); // calls add(double, double)

  return 0;
}
