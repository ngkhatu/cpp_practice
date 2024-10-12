// learncpp.com: section 10.8- Type Deduction for objects using auto keyword

#include <iostream>
int add(int x, int y) { return x + y; }

int main() {
  auto sum{add(
      5, 6)}; // add() returns an int, so sum's type will be deduced as an int
  std::cout << sum << std::endl;
  return 0;
}

/*
//Type deduction will not work for objects that either do not have initializers
or have empty initializers. It also will not work when the initializer has type
void (or any other incomplete type). Thus, the following is not valid:

void foo()
{
}

int main()
{
    auto a;           // The compiler is unable to deduce the type of a
    auto b { };       // The compiler is unable to deduce the type of b
    auto c { foo() }; // Invalid: c can't have type incomplete type void

    return 0;
}
*/

/* // In most cases, type deduction will drop the const from deduced types. For
example:

int main()
{
    const int a { 5 }; // a has type const int
    auto b { a };      // b has type int (const dropped)

    return 0;
}
 */

/*
//If you want a deduced type to be const, you must supply the const yourself as
// part of the definition:

int main()
{
    const int a { 5 };  // a has type const int
    const auto b { a }; // b has type const int (const dropped but reapplied)


    return 0;
}
*/

/*
//For historical reasons, string literals in C++ have a strange type. Therefore,
//the following probably won’t work as expected:

auto s { "Hello, world" }; // s will be type const char*, not std::string

// If you want the type deduced from a string literal to be std::string or
// std::string_view, you’ll need to use the s or sv literal suffixes

int main()
{
    using namespace std::literals; // easiest way to access the s and sv
suffixes

    auto s1 { "goo"s };  // "goo"s is a std::string literal, so s1 will be
deduced as a std::string auto s2 { "moo"sv }; // "moo"sv is a std::string_view
literal, so s2 will be deduced as a std::string_view

    return 0;
}

*/

/* // Because constexpr is not part of the type system, it cannot be deduced as
// part of type deduction. However, a constexpr variable is implicitly const,
// and this const will be dropped during type deduction (and can be readded if
// desired):

int main() {
  constexpr double a{3.4}; // a has type const double (constexpr not part of
                           // type, const is implicit)

  auto b{a};           // b has type double (const dropped)
  const auto c{a};     // c has type const double (const dropped but reapplied)
  constexpr auto d{a}; // d has type const double (const dropped but implicitly
                       // reapplied by constexpr)

  return 0;
}
 */

/*
int x;  // oops, we forgot to initialize x, but the compiler may not complain
auto y; // the compiler will error out because it can't deduce a type for y

std::string_view getString();   // some function that returns a std::string_view

std::string s1 { getString() }; // bad: expensive conversion from
std::string_view to std::string (assuming you didn't want this) auto s2 {
getString() };        // good: no conversion required */
