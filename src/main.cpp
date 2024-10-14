// Learncpp.com: section 14.15- Class initialization and copy elision

// Copy Elision- compiler optimization technique that allows the compiler to
// remove unnecessary copying of objects. In other words, in cases where the
// compiler would normally call a copy constructor, the compiler is free to
// rewrite the code to avoid the call to the copy constructor altogether. When
// the compiler optimizes away a call to the copy constructor, we say the
// constructor has been elided

//  Since the compiler is free to rewrite statements to optimize them, one might
//  wonder if the compiler can optimize away the
// unnecessary copy and treat Something s { Something{5} }; as if we had written
// Something s { 5 } in the first place.
#include <iostream>

class Something {
  int m_x{};

public:
  Something(int x) : m_x{x} { std::cout << "Normal constructor\n"; }

  Something(const Something &s) : m_x{s.m_x} {
    std::cout << "Copy constructor\n";
  }

  void print() const { std::cout << "Something(" << m_x << ")\n"; }
};

int main() {
  Something s{Something{5}}; // focus on this line
  s.print();

  return 0;
}

// ##################################################
/*
int a;         // no initializer (default initialization)
int b = 5;     // initializer after equals sign (copy initialization)
int c( 6 );    // initializer in parentheses (direct initialization)

// List initialization methods (C++11)
int d { 7 };   // initializer in braces (direct list initialization)
int e = { 8 }; // initializer in braces after equals sign (copy list
initialization) int f {};      // initializer is empty braces (value
initialization)
*/

// ################################################
/* //  Valid initialization types for object with class types
#include <iostream>

class Foo {
public:
  // Default constructor
  Foo() { std::cout << "Foo()\n"; }

  // Normal constructor
  Foo(int x) { std::cout << "Foo(int) " << x << '\n'; }

  // Copy constructor
  Foo(const Foo &) { std::cout << "Foo(const Foo&)\n"; }
};

int main() {
  // Calls Foo() default constructor
  Foo f1;   // default initialization
  Foo f2{}; // value initialization (preferred)

  // Calls foo(int) normal constructor
  Foo f3 = 3;   // copy initialization (non-explicit constructors only)
  Foo f4(4);    // direct initialization
  Foo f5{5};    // direct list initialization (preferred)
  Foo f6 = {6}; // copy list initialization (non-explicit constructors only)

  // Calls foo(const Foo&) copy constructor
  Foo f7 = f3;    // copy initialization
  Foo f8(f3);     // direct initialization
  Foo f9{f3};     // direct list initialization (preferred)
  Foo f10 = {f3}; // copy list initialization

  return 0;
}
 */
