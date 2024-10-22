// Learncpp.com: section 11.8- Function templates with multiple template types
/*
#include <iostream>

// template <typename T, typename U> auto max(T x, U y) { return (x < y) ? y :
// x; }

auto max(auto x, auto y) { return (x < y) ? y : x; }
// shorthand for
// template <typename T, typename U>
// auto max(T x, U y)
// {
//     return (x < y) ? y : x;
// }


int main() {
  std::cout << max(2, 3.5) << '\n';

  return 0;
}

// BEST PRACTICE- Feel free to use abbreviated function templates with a single
// auto parameter, or where each auto parameter should be an independent type
// (and your language standard is set to C++20 or newer).
 */
// #####################################################################

// Overloaded Function Templates
#include <iostream>

// Add two values with matching types
template <typename T> auto add(T x, T y) { return x + y; }

// Add two values with non-matching types
// As of C++20 we could also use auto add(auto x, auto y)
template <typename T, typename U> auto add(T x, U y) { return x + y; }

// Add three values with any type
// As of C++20 we could also use auto add(auto x, auto y, auto z)
template <typename T, typename U, typename V> auto add(T x, U y, V z) {
  return x + y + z;
}

int main() {
  std::cout << add(1.2, 3.4) << '\n'; // instantiates and calls add<double>()
  std::cout << add(5.6, 7) << '\n'; // instantiates and calls add<double, int>()
  std::cout << add(8, 9, 10)
            << '\n'; // instantiates and calls add<int, int, int>()

  return 0;
}
