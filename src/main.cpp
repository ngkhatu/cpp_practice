// Learncpp.com: section 13.14- Class template argument deduction (CTAD) and
// deduction guides

#include <iostream>
#include <utility>
// for std::pair
/*
// define our own Pair type
template <typename T, typename U> struct Pair {
  T first{};
  U second{};
};

// provide the compiler with a deduction guide, which tells the compiler how to
// deduce the template arguments for a given class template
// * Here's a deduction guide for our Pair (needed in C++17 only)
/// Pair objects initialized with arguments of type T and U should deduce to
// Pair<T, U>
template <typename T, typename U> Pair(T, U) -> Pair<T, U>;

int main() {
  std::pair<int, int> p1{1, 2}; // explicitly specify class template
                                // std::pair<int, int> (C++11 onward)
  std::pair p2{1, 2}; // CTAD used to deduce std::pair<int, int> from the
                      // initializers (C++17)

  // CTAD is only performed if no template argument list is present. Therefore,
  // both of the following are errors:
    //std::pair p3{1, 2}; // error: too few template arguments, both arguments
not deduced
  //std::pair<int> p4{3, 4}; // error: too few template arguments, second
argument not deduced

  // Since CTAD is a form of type deduction, we can use literal suffixes to
  // change the deduced type:
  std::pair p5{3.4f, 5.6f}; // deduced to pair<float, float>
  std::pair p6{1u, 2u};     // deduced to pair<unsigned int, unsigned int>

  Pair<int, int> p7{
      1, 2};     // ok: we're explicitly specifying the template arguments
  Pair p8{1, 2}; // compile error in C++17 (okay in C++20) CTAD used to deduce
                // Pair<int, int> from the initializers (C++17)

  return 0;
}
*/

/* template <typename T> struct Pair {
  T first{};
  T second{};
};

// Here's a deduction guide for our Pair (needed in C++17 only)
// Pair objects initialized with arguments of type T and T should deduce to
// Pair<T>
template <typename T> Pair(T, T) -> Pair<T>;

int main() {
  Pair<int> p1{1,
               2}; // explicitly specify class template Pair<int> (C++11 onward)
  Pair p2{1, 2}; // CTAD used to deduce Pair<int> from the initializers (C++17)

  return 0;
}
 */

/* // template parameters can be given default values. These will be used when
the
// template parameter isn’t explicitly specified and can’t be deduced.
template <typename T = int, typename U = int> // default T and U to type int
struct Pair {
  T first{};
  U second{};
};

template <typename T, typename U> Pair(T, U) -> Pair<T, U>;

int main() {
  Pair<int, int> p1{
      1, 2}; // explicitly specify class template Pair<int, int> (C++11 onward)
  Pair p2{
      1, 2}; // CTAD used to deduce Pair<int, int> from the initializers (C++17)

  Pair p3; // uses default Pair<int, int>

  return 0;
}
 */

/* // for std::pair

// When initializing the member of a class type using non-static member
// initialization, CTAD will not work in this context. All template arguments
// must be explicitly specified:
struct Foo {
  std::pair<int, int> p1{1, 2}; // ok, template arguments explicitly specified
  std::pair p2{1, 2}; // compile error, CTAD can't be used in this context
};

int main() {
  std::pair p3{1, 2}; // ok, CTAD can be used here
  return 0;
}
 */

/* // CTAD stands for class template argument deduction, not class template
// parameter deduction, so it will only deduce the type of template arguments,
// not template parameters. Therefore, CTAD can’t be used in function
// parameters.
void print(std::pair p) // compile error, CTAD can't be used here
{
  std::cout << p.first << ' ' << p.second << '\n';
}

int main() {
  std::pair p{1, 2}; // p deduced to std::pair<int, int>
  print(p);

  return 0;
} */
// ############################
// Use a template instead

#include <iostream>
#include <utility>

template <typename T, typename U> void print(std::pair<T, U> p) {
  std::cout << p.first << ' ' << p.second << '\n';
}

int main() {
  std::pair p{1, 2}; // p deduced to std::pair<int, int>
  print(p);

  return 0;
}
