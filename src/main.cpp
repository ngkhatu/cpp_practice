#include <iostream>
#include <string>

// Learncpp.com: section 13.8- Struct Aggregate Initialization

// an aggregate data type (also called an aggregate) is any type that can
// contain multiple data members. Some types of aggregates allow members to have
// different types (e.g. structs), while others require that all members must be
// of a single type

/* //  2 primary forms of aggregate initialization:
struct Employee {
  int id{};
  int age{};
  double wage{};
};

// Overloading operator<< to print a struct
std::ostream &operator<<(std::ostream &out, const Employee &e) {
  out << e.id << ' ' << e.age << ' ' << e.wage;
  return out;
}

int main() {
  Employee frank = {1, 32,
                    60000.0}; // copy-list initialization using braced list
  Employee joe{2, 28,
               45000.0}; // list initialization using braced list (preferred)

  // in C++20
  // Employee robert(3, 45, 62500.0); // direct initialization using
  // parenthesized list (C++20)

  Employee joey{2, 28}; // joe.wage will be value-initialized to 0.0
  std::cout << joe.wage << std::endl;
  Employee joseph{}; // value-initialize all members

  Employee jose{2, 28}; // jose.wage will be value-initialized to 0.0
  std::cout << jose << '\n';

  // struct type can be const (or constexpr)

  const Employee Ann{}; // value-initialize all members
  const Employee Linda{4, 21, 40000};

  std::cout << Linda.wage << std::endl;

  std::cout << joe << std::endl;
  joe = {joe.id, 33, 66000.0}; // Joe had a birthday and got a raise
  std::cout << joe << std::endl;
  joe = {.id = joe.id,
         .age = 34,
         .wage = 90000.0}; // Joe had a birthday and got a raise
  std::cout << joe << std::endl;

  return 0;
} */

// When initializing a struct from a list of values, the initializers are
// applied to the members in order of declaration
struct Foo {
  int a{};
  int b{}; // just added
  // Now all your initialization values have shifted, and worse, the compiler
  // may not detect this as an error (after all, the syntax is still valid).
  int c{};
};

// Overloading operator<< to print a struct
std::ostream &operator<<(std::ostream &out, const Foo &e) {
  out << e.a << ' ' << e.b << ' ' << e.c;
  return out;
}

int main() {
  // Foo f{1, 3}; // f.a = 1, f.c = 3

  // Designated Initializers- allow to explicitly define which initilization
  // values map to which members
  // C++20 add a new way to initialize struct members
  Foo f1{.a{1}, .c{3}}; // ok: f1.a = 1, f1.b = 0 (value initialized), f1.c = 3
  Foo f2{.a = 1,
         .c = 3}; // ok: f2.a = 1, f2.b = 0 (value initialized), f2.c = 3
  // Foo f3{.b{2}, .a{1}}; // error: initialization order does not match order
  // of declaration in struct

  std::cout << f1 << std::endl;
  std::cout << f2 << std::endl;

  Foo foo{1, 2, 3};

  Foo x = foo; // copy initialization
  Foo y(foo);  // direct initialization
  Foo z{foo};  // list initialization

  std::cout << x << '\n';
  std::cout << y << '\n';
  std::cout << z << '\n';
  return 0;
}
