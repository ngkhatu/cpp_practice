// Learncpp.com: section 13.15- Alias templates

#include <iostream>

/* template <typename T> struct Pair {
  T first{};
  T second{};
};

template <typename T> void print(const Pair<T> &p) {
  std::cout << p.first << ' ' << p.second << '\n';
}

int main() {
  // Such aliases can be defined locally (e.g. inside a function) or globally
  using Point = Pair<int>; // create normal type alias
  Point p{1, 2};           // compiler replaces this with Pair<int>

  print(p);

  return 0;
}
 */

// Alias Template- template that can be used to instantiate type aliases. Just
// like type aliases do not define distinct types, alias templates do not define
// distinct types
#include <iostream>

template <typename T> struct Pair {
  T first{};
  T second{};
};

// Here's our alias template
// Alias templates must be defined in global scope
template <typename T> using Coord = Pair<T>; // Coord is an alias for Pair<T>

// Our print function template needs to know that Coord's template parameter T
// is a type template parameter
template <typename T> void print(const Coord<T> &c) {
  std::cout << c.first << ' ' << c.second << '\n';
}

int main() {
  Coord<int> p1{
      1,
      2}; // Pre C++-20: We must explicitly specify all type template argument
  // Coord p2{1, 2}; // In C++20, we can use alias template deduction to deduce
  // the
  //  template arguments in cases where CTAD works

  std::cout << p1.first << ' ' << p1.second << '\n';
  // print(p2);

  return 0;
}
