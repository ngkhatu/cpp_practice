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
/*
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
 */
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
// #################################################
/* //  Implicit Default Constructor
class Foo {
private:
  int m_x{};
  int m_y{};
  // Note: no constructors declared
};

int main() {
  Foo foo{};

  return 0;
} */

/*
public:
    Foo() // implicitly generated default constructor
    {
    }
*/

// #################################################
/* //  Explicit Default Constructor
// BEST PRACTICE- Prefer an explicitly defaulted default constructor (= default)
// over a default constructor with an empty body.
class Foo {
private:
  int m_x{};
  int m_y{};

public:
  // since we have a user-declared constructor (Foo(int, int)), an implicit
  // default constructor would not normally be generated. However, because we’ve
  // told the compiler to generate such a constructor, it will.
  Foo() = default; // generates an explicitly defaulted default constructor

  Foo(int x, int y) : m_x{x}, m_y{y} {
    std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
  }
};

int main() {
  Foo foo{}; // calls Foo() default constructor

  return 0;
} */

// #####################################################

class User {
private:
  int m_a; // note: no default initialization value
  int m_b{};

public:
  User() {} // user-defined empty constructor

  int a() const { return m_a; }
  int b() const { return m_b; }
};

class Default {
private:
  int m_a; // note: no default initialization value
  int m_b{};

public:
  Default() = default; // explicitly defaulted default constructor

  int a() const { return m_a; }
  int b() const { return m_b; }
};

class Implicit {
private:
  int m_a; // note: no default initialization value
  int m_b{};

public:
  // implicit default constructor

  int a() const { return m_a; }
  int b() const { return m_b; }
};

int main() {
  // if the class has a user-defined default constructor, the object will be
  // default initialized
  User user{}; // default initialized
  std::cout << user.a() << ' ' << user.b() << '\n';
  // Note that user.a was not zero initialized before being default initialized,
  // and thus was left uninitialized.
  // In practice, this shouldn’t matter since you should be providing default
  // member initializers for all data members!

  //-----------------------------

  // if the class has a default constructor that is not user-provided (that is,
  // a default constructor that is either implicitly defined, or defined using =
  // default), the object will be zero-initialized before being default
  // initialized
  Default def{}; // zero initialized, then default initialized
  std::cout << def.a() << ' ' << def.b() << '\n';

  Implicit imp{}; // zero initialized, then default initialized
  std::cout << imp.a() << ' ' << imp.b() << '\n';

  return 0;
}
// Prior to C++20, a class with a user-defined default constructor (even if it
// has an empty body) makes the class a non-aggregate, whereas an explicitly
// defaulted default constructor does not. Assuming the class was otherwise an
// aggregate, the former would cause the class to use list initialization
// instead of aggregate initialization. In C++20 onward, this inconsistency was
// addressed, so that both make the class a non-aggregate.
