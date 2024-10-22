// Learncpp.com: section 11.9- Non-type template parameters

/* A non-type template parameter is a template parameter with a fixed type that
serves as a placeholder for a constexpr value passed in as a template argument.

A non-type template parameter can be any of the following types:

An integral type
- std::nullptr_t
- An enumeration type
- A floating point type (since C++20)
- A pointer or reference to an object
- A pointer or reference to a function
- A pointer or reference to a member function
- A literal class type (since C++20)
 */
/*
// BEST PRACTICE- Use N as the name of an int non-type template parameter.
#include <iostream>

template <int N> // declare a non-type template parameter of type int named N
void print() {
  std::cout << N << '\n'; // use value of N here
}

int main() {
  print<5>(); // 5 is our non-type template argument

  return 0;
} */
// ####################################################################
//  As of C++20, function parameters cannot be constexpr. This is true for
//  normal functions, constexpr functions (which makes sense, as they must be
//  able to be run at runtime), and perhaps surprisingly, even consteval
//  functions.

/* #include <cassert>
#include <cmath> // for std::sqrt
#include <iostream>

double getSqrt(double d) {
  assert(d >= 0.0 && "getSqrt(): d must be non-negative");

  // The assert above will probably be compiled out in non-debug builds
  if (d >= 0)
    return std::sqrt(d);

  return 0.0;
}

int main() {
  std::cout << getSqrt(5.0) << '\n';
  std::cout << getSqrt(-5.0) << '\n';

  return 0;
}
 */
//-------------------------------------------------
/*
When run, the call to getSqrt(-5.0) will runtime assert out. While this is
better than nothing, because -5.0 is a literal (and implicitly constexpr), it
would be better if we could static_assert so that errors such as this one would
be caught at compile-time. However, static_assert requires a constant
expression, and function parameters can’t be constexpr…

However, if we change the function parameter to a non-type template parameter
instead, then we can do exactly as we want:
*/
/* #include <cmath> // for std::sqrt
#include <iostream>

template <double D> // requires C++20 for floating point non-type parameters
double getSqrt() {
  static_assert(D >= 0.0, "getSqrt(): D must be non-negative");

  if constexpr (D >= 0) // ignore the constexpr here for this example
    return std::sqrt(
        D); // strangely, std::sqrt isn't a constexpr function (until C++26)

  return 0.0;
}

int main() {
  std::cout << getSqrt<5.0>() << '\n';
  std::cout << getSqrt<-5.0>() << '\n';

  return 0;
} */
// ############################################################
// Implicit conversions for non-type template arguments
/*
#include <iostream>

template <int N> // int non-type template parameter
void print() {
  std::cout << N << '\n';
}

int main() {
  print<5>();   // no conversion necessary
  print<'c'>(); // 'c' converted to type int, prints 99
  // implicitly converted in order to match a non-type template parameter of a
  // different type

  return 0;
}
 */
/*
Most common types of allowed conversions include
-------------------------------------------------
- Integral promotions (e.g. char to int)
- Integral conversions (e.g. char to long or int to char)
- User-defined conversions (e.g. some program-defined class to int)
- Lvalue to rvalue conversions (e.g. some variable x to the value of x)
* Note that this list is less permissive than the type of implicit conversions
allowed for list initialization
*/
// ###############################################################
/*
// Unlike with normal functions, the algorithm for matching function template
// calls to function template definitions is not sophisticated, and certain
// matches are not prioritized over others based on the type of conversion
// required (or lack thereof). This means that if a function template is
// overloaded for different kinds of non-type template parameters, it can very
// easily result in an ambiguous match

#include <iostream>

template <int N> // int non-type template parameter
void print() {
  std::cout << N << '\n';
}

template <char N> // char non-type template parameter
void print() {
  std::cout << N << '\n';
}

int main() {
  print<5>();   // ambiguous match with int N = 5 and char N = 5
  print<'c'>(); // ambiguous match with int N = 99 and char N = 'c'

  return 0;
}
 */
// ##############################################################
// Type deduction for non-type template parameters using auto
//..............................................................
// As of C++17, non-type template parameters may use auto to have the compiler
// deduce the non-type template parameter from the template argument:
#include <iostream>

template <auto N> // deduce non-type template parameter from template argument
void print() {
  std::cout << N << '\n';
}

int main() {
  print<5>();   // N deduced as int `5`
  print<'c'>(); // N deduced as char `c`

  return 0;
}
