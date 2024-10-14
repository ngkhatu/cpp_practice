// Learncpp.com: section 14.13- Temporary Class Objects

#include <iostream>
/*
class IntPair {
private:
  int m_x{};
  int m_y{};

public:
  IntPair(int x, int y) : m_x{x}, m_y{y} {}

  int x() const { return m_x; }
  int y() const { return m_y; }
};

void print(IntPair p) { std::cout << "(" << p.x() << ", " << p.y() << ")\n"; }

// Case 1: Create named variable and return
IntPair ret1() {
  IntPair p{3, 4};
  return p; // returns temporary object (initialized using p)
}

// Case 2: Create temporary IntPair and return
IntPair ret2() {
  return IntPair{5, 6}; // returns temporary object (initialized using another
                        // temporary object)
}

// Case 3: implicitly convert { 7, 8 } to IntPair and return
IntPair ret3() {
  return {7, 8}; // returns temporary object (initialized using another
                 // temporary object)
}

int main() {
  // Case 1: Pass variable
  IntPair p{3, 4};
  print(p);

  // Two common ways to create temporary class objects

  // 1) we’re telling the compiler to construct an IntPair object, and
  // initializing it with { 5, 6 }. Because this object has no name, it is a
  // temporary
  //  Case 2: Construct temporary IntPair and pass to function
  print(IntPair{5, 6});

  // 2) we’re also creating a temporary IntPair object to pass to function
  // print(). However, because we have not explicitly specified what type to
  // construct, the compiler will deduce the necessary type (IntPair) from the
  // function parameter, and then implicitly convert { 7, 8 } to an IntPair
  // object
  //  Case 3: Implicitly convert { 7, 8 } to a temporary Intpair and pass to
  //  function
  print({7, 8});

  print(ret1());
  print(ret2());
  print(ret3());

  return 0;
}
 */

#include "printString.h"

#include <string>
#include <string_view>

int main() {
  std::string_view sv{"Hello"};

  // We want to print sv using the printString() function

  //    printString(sv); // compile error: a std::string_view won't implicitly
  //    convert to a std::string

  printString(
      static_cast<std::string>(sv)); // Case 1: static_cast returns a temporary
                                     // std::string direct-initialized with sv
  printString(std::string{sv});      // Case 2: explicitly creates a temporary
                                     // std::string list-initialized with sv

  // printString(std::string(sv)); // Case 3: C-style cast returns temporary
  // std::string direct-initialized with sv (avoid this one!)

  return 0;
}
