#include <iostream>
#include <string>
#include <string_view>

// Learncpp.com: section 14.9- Introduction to Constructors

// A constructor is a special member function that is automatically called after
// a non-aggregate class type object is created.

// Beyond determining how an object may be created, constructors generally
// perform two functions:

// * They typically perform initialization of any member variables (via a member
// initialization list)
// * They may perform other setup functions (via statements in the body of the
// constructor). This might include things such as error checking the
// initialization values, opening a file or database, etc…

// After the constructor finishes executing, we say that the object has been
// “constructed”, and the object should now be in a consistent, usable state.

// Note that aggregates are not allowed to have constructors -- so if you add a
// constructor to an aggregate, it is no longer an aggregate.

// Unlike normal member functions, constructors have specific rules for how they
// must be named:

// * Constructors must have the same name as the class (with the same
// capitalization).
// - For template classes, this name excludes the template parameters.
// * Constructors have no return type (not even void).

// Because constructors are typically part of the interface for your class, they
// are usually public.

#include <iostream>
/*
class Foo {
private:
  int m_x{};
  int m_y{};

public:
  Foo(int x,
      int y) // here's our constructor function that takes two initializers
  {
    std::cout << "Foo(" << x << ", " << y << ") constructed\n";
  }

  void print() const { std::cout << "Foo(" << m_x << ", " << m_y << ")\n"; }
};

int main() {
  Foo foo{6, 7}; // calls Foo(int, int) constructor
  foo.print();

  return 0;
} */

// * Constructor implicit conversion of arguments
// - compiler will perform implicit conversion of arguments in a function call
// (if needed) in order to match a function definition where the parameters are
// a different type
// * A constructor needs to be able to initialize the object being constructed
// -- therefore, a constructor must not be const.
// ######################################################

class Something {
private:
  int m_x{};

public:
  Something() // constructors must be non-const
  {
    m_x = 5; // okay to modify members in non-const constructor
  }

  int getX() const { return m_x; } // const
};

int main() {

  // Normally a non-const member function can’t be invoked on a const object.
  // However, because the constructor is invoked implicitly, a non-const
  // constructor can be invoked on a const object
  const Something
      s{}; // const object, implicitly invokes (non-const) constructor

  std::cout << s.getX(); // prints 5

  return 0;
}
