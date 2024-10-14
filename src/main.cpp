// Learncpp.com: section 14.17- Constexpr aggregates and classes

#include <iostream>

/*
In this example, greater() is a constexpr function, and greater(5, 6) is a
constant expression, which may be evaluated at either compile-time or runtime.
*/
/* constexpr int greater(int x, int y) { return (x > y ? x : y); }

int main() {
  // Because std::cout << greater(5, 6) calls greater(5, 6) in a non-constexpr
  // context, the compiler is free to choose whether to evaluate greater(5, 6)
  // at compile-time or runtime.
  std::cout
      << greater(5, 6)
      << '\n'; // greater(5, 6) may be evaluated at compile-time or runtime

  // When greater(5, 6) is used to initialize constexpr
  // variable g, greater(5, 6) is called in a constexpr context, and must be
  // evaluated at compile-time.
  constexpr int g{
      greater(5, 6)};     // greater(5, 6) must be evaluated at compile-time
  std::cout << g << '\n'; // prints 6

  return 0;
}
 */

// #############################################
// Aggregate Structure
/* struct Pair {
  int m_x{};
  int m_y{};

  constexpr int greater() const { return (m_x > m_y ? m_x : m_y); }
  // The following will give compile error due to non-constexpr
  // int greater() const { return (m_x > m_y ? m_x : m_y); }
};

int main() {
  constexpr Pair p{5, 6}; // inputs are constexpr values
  // Need to make the following constexpr for p.greater() to work
  // Pair p{5, 6};                     // inputs are constexpr values
  std::cout << p.greater() << '\n'; // p.greater() evaluates at runtime

  constexpr int g{p.greater()}; // compile error: greater() not constexpr
  std::cout << g << '\n';

  return 0;
} */

// ##################################################
/*
// Non-aggregate data structure
// BEST PRACTICE- If you want your class to be able to be evaluated at
// compile-time, make your member functions and constructor constexpr.

class Pair // Pair is no longer an aggregate
{
private:
  int m_x{};
  int m_y{};

public:
  constexpr Pair(int x, int y) : m_x{x}, m_y{y} {}
  // Compiler fails since constuctor is not constexpr
  // Pair(int x, int y) : m_x{x}, m_y{y} {}

  constexpr int greater() const { return (m_x > m_y ? m_x : m_y); }
};
constexpr int init() {
  Pair p{
      5,
      6}; // requires constructor to be constexpr when evaluated at compile-time
  return p.greater(); // requires greater() to be constexpr when evaluated at
                      // compile-time
}

int main() {
  constexpr Pair p{5, 6}; // compile error: p is not a literal type
  std::cout << p.greater() << '\n';

  // constexpr int g{p.greater()};
  // std::cout << g << '\n';

  constexpr int g{init()}; // init() evaluated in runtime context
  std::cout << g << '\n';

  return 0;
}

// get a compiler error about Pair not being a “literal type”
//* In C++, a literal type is any type for which it might be possible to create
// an object within a constant expression. Put another way, an object can’t be
// constexpr unless the type qualifies as a literal type. And our non-aggregate
// Pair does not qualify.
// * When a class object is instantiated, the compiler will call the constructor
// function to initialize the object. And the constructor function in our Pair
// class is not constexpr, so it can’t be invoked at compile-time. Therefore,
// Pair objects cannot be constexpr
 */

// #########################################################
// As of C++14, constexpr member functions are no longer implicitly
// const. This means a constexpr non-const member function can change data
// members of the class, so long as the implicit object isn’t const.

// * A non-const member function can modify members of non-const objects.
// * A constexpr member function can be called in either runtime contexts or
// compile-time contexts.

class Pair {
private:
  int m_x{};
  int m_y{};

public:
  constexpr Pair(int x, int y) : m_x{x}, m_y{y} {}

  constexpr int greater() const // constexpr and const
  {
    return (m_x > m_y ? m_x : m_y);
  }

  constexpr void reset() // constexpr but non-const
  {
    m_x = m_y = 0; // non-const member function can change members
  }

  // Normally you won’t see constexpr and const used right next to each other,
  // but one case where this does happen is when you have a constexpr member
  // function that returns a const reference (or pointer-to-const).

  // The constexpr indicates that the member function can be evaluated at
  // compile-time. The const int& is the return type of the function. The
  // rightmost const means the member-function itself is const so it can be
  // called on const objects.
  constexpr const int &getX() const { return m_x; }
};

// This function is constexpr
constexpr Pair zero() {
  Pair p{1, 2}; // p is non-const
  p.reset();    // okay to call non-const member function on non-const object
  return p;
}

int main() {
  Pair p1{3, 4};
  p1.reset(); // okay to call non-const member function on non-const object
  std::cout << p1.getX() << '\n'; // prints 0

  Pair p2{zero()}; // zero() will be evaluated at runtime
  p2.reset();      // okay to call non-const member function on non-const object
  std::cout << p2.getX() << '\n'; // prints 0

  constexpr Pair p3{zero()}; // zero() will be evaluated at compile-time
  //    p3.reset();                   // Compile error: can't call non-const
  //    member function on const object

  std::cout << p3.getX() << '\n'; // prints 0

  return 0;
}
