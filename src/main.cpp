#include <iostream>

// Learncpp.com: section 14.11- Default constructors and default arguments

//  default constructor is a constructor that accepts no arguments. Typically,
//  this is a constructor that has been defined with no parameters.
/*
class Foo {
public:
  Foo() // default constructor
  {
    std::cout << "Foo default constructed\n";
  }
};

int main() {
  Foo foo{}; // No initialization values, calls Foo's default constructor

  // If a class type has a default constructor, both value initialization and
  // default initialization will call the default constructor. Thus, for such a
  // class such as the Foo class in the example above, the following are
  // essentially equivalent:
  //  Foo foo{}; // value initialization, calls Foo() default constructor
  //  Foo foo2;  // default initialization, calls Foo() default constructor
  // * Prefer value initialization over default initialization for all class
  // types.

  return 0;
}
 */

class Foo {
private:
  int m_x{7};
  int m_y{7};
  int m_z{7}; // These vals are ignored

public:
  // As with all functions, the rightmost parameters of constructors can have
  // default arguments
  // - If all of the parameters in a constructor have default arguments, the
  // constructor is a default constructor (because it can be called with no
  // arguments).
  Foo(int x,
      int y) // has default arguments (Overloaded non-default constructor)
      : m_x{x}, m_y{y} {
    std::cout << "Foo(" << m_x << ", " << m_y << ", " << m_z
              << ") constructed\n";
  }

  Foo(int x, int y,
      int z) // has default arguments (Overloaded non-default constructor)
      : m_x{x}, m_y{y}, m_z{z} {
    std::cout << "Foo(" << m_x << ", " << m_y << ", " << m_z
              << ") constructed\n";
  }

  // Because constructors are functions, they can be overloaded. That is, we can
  // have multiple constructors so that we can construct objects in different
  // ways
  Foo() // Default Constructor
  {
    std::cout << "Foo(" << m_x << ", " << m_y << ", " << m_z
              << ") constructed\n";
  }
};

int main() {
  Foo foo1{};        // calls Foo(int, int) constructor using default arguments
  Foo foo2{6, 1, 1}; // calls Foo(int, int) constructor
  Foo foo3{3, 5};

  return 0;
}

// A corollary of the above is that a class should only have one default
// constructor. If more than one default constructor is provided, the compiler
// will be unable to disambiguate which should be used:

/* This is considered a default constructor
    Foo(int x=1, int y=2) // default constructor
        : m_x { x }, m_y { y }
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
    }
*/
