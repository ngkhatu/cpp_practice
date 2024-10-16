// Learncpp.com: section 13.13- Class Templates

// a class template is a template definition for instantiating class types

#include <iostream>

/*
template <typename T> struct Pair {
  T first{};
  T second{};
};

template <typename T> constexpr T max(Pair<T> p) {
  return (p.first < p.second ? p.second : p.first);
}


int main() {
  Pair<int> p1{5, 6}; // instantiates Pair<int> and creates object p1
  std::cout << p1.first << ' ' << p1.second << '\n';
  std::cout << max<int>(p1) << " is larger\n"; // explicit call to max<int>

  Pair<double> p2{1.2, 3.4}; // instantiates Pair<double> and creates object p2
  std::cout << p2.first << ' ' << p2.second << '\n';
  std::cout << max(p2) << " is larger\n"; // call to max<double> using template
                                          // argument deduction (prefer this)

  Pair<double> p3{
      7.8, 9.0}; // creates object p3 using prior definition for Pair<double>
  std::cout << p3.first << ' ' << p3.second << '\n';

  return 0;
}
 */

/* template <typename T, typename U> struct Pair {
  T first{};
  U second{};
};

template <typename T, typename U> void print(Pair<T, U> p) {
  std::cout << '[' << p.first << ", " << p.second << ']';
}

int main() {
  Pair<int, double> p1{1, 2.3}; // a pair holding an int and a double
  Pair<double, int> p2{4.5, 6}; // a pair holding a double and an int
  Pair<int, int> p3{7, 8};      // a pair holding two ints

  print(p2);

  return 0;
}
 */

/* template <typename T, typename U> struct Pair {
  T first{};
  U second{};
};

struct Point {
  int first{};
  int second{};
};

template <typename T>
void print(T p) // type template parameter will match anything
{
  std::cout << '[' << p.first << ", " << p.second
            << ']'; // will only compile if type has first and second members
}

int main() {
  Pair<double, int> p1{4.5, 6};
  print(p1); // matches print(Pair<double, int>)

  std::cout << '\n';

  Point p2{7, 8};
  print(p2); // matches print(Point)

  std::cout << '\n';

  return 0;
}
 */
// ###################################################
/* //  Because working with pairs of data is common, the C++ standard library
//  contains a class template named std::pair (in the <utility> header) that is
//  defined identically to the Pair class template with multiple template types
//  in the preceding section. In fact, we can swap out the pair struct we
//  developed for std::pair:

#include <utility>

template <typename T, typename U> void print(std::pair<T, U> p) {
  std::cout << '[' << p.first << ", " << p.second << ']';
}

int main() {
  std::pair<int, double> p1{1, 2.3}; // a pair holding an int and a double
  std::pair<double, int> p2{4.5, 6}; // a pair holding a double and an int
  std::pair<int, int> p3{7, 8};      // a pair holding two ints

  print(p2);

  return 0;
}
 */

// #######################################################
#include "pair.h"
#include <iostream>

// Just like function templates, class templates are typically defined in header
// files so they can be included into any code file that needs them. Both
// template definitions and type definitions are exempt from the one-definition
// rule, so this won’t cause problems:

void foo(); // forward declaration for function foo()

int main() {
  Pair<double> p2{3.4, 5.6};
  std::cout << max(p2) << " is larger\n";

  foo();

  return 0;
}
