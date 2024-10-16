// Learncpp.com: section 13.8- Struct Aggregate Initialization
// selection

/* // Two primary forms of aggregate initialization
// BEST PRACTICE- Prefer the (non-copy) braced list form when initializing
// aggregates
struct Employee {
  int id{};
  int age{};
  double wage{};
};

int main() {
  Employee frank = {1, 32,
                    60000.0}; // copy-list initialization using braced list
  Employee joe{2, 28,
               45000.0}; // list initialization using braced list (preferred)

  return 0;
} */
/*
// Overloading operator<< to print a struct
#include <iostream>

struct Employee {
  int id{};
  int age{};
  double wage{};
};

std::ostream &operator<<(std::ostream &out, const Employee &e) {
  out << e.id << ' ' << e.age << ' ' << e.wage;
  return out;
}

int main() {
  Employee joe{2, 28}; // joe.wage will be value-initialized to 0.0
  std::cout << joe << '\n';

  return 0;
}

 */
/* // Variables of a struct type can be const (or constexpr), and just like all
// const variables, they must be initialized.
struct Rectangle {
  double length{};
  double width{};
};

int main() {
  const Rectangle unit{1.0, 1.0};
  const Rectangle zero{}; // value-initialize all members

  return 0;
}

// Designated Initializers
// BEST PRACTICE- When adding a new member to an aggregate, it’s safest to add
//it to the bottom of the definition list so the initializers for other members
//don’t shift.

struct Foo {
  int a{};
  int b{};
  int c{};
};

int main() {
  Foo f1{.a{1}, .c{3}}; // ok: f1.a = 1, f1.b = 0 (value initialized), f1.c = 3
  Foo f2{.a = 1,
         .c = 3};       // ok: f2.a = 1, f2.b = 0 (value initialized), f2.c = 3
  Foo f3{.b{2}, .a{1}}; // error: initialization order does not match order of
                        // declaration in struct

  return 0;
}
 */

// ###########################################################
// A struct may also be initialized using another struct of the same type:
#include <iostream>

struct Foo {
  int a{};
  int b{};
  int c{};
};

std::ostream &operator<<(std::ostream &out, const Foo &f) {
  out << f.a << ' ' << f.b << ' ' << f.c;
  return out;
}

int main() {
  Foo foo{1, 2, 3};

  Foo x = foo; // copy initialization
  Foo y(foo);  // direct initialization
  Foo z{foo};  // list initialization

  std::cout << x << '\n';
  std::cout << y << '\n';
  std::cout << z << '\n';

  return 0;
}
