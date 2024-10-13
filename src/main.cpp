#include <iostream>

// Learncpp.com: section 14.10- Constructor Member Initializer Lists

// To have a constructor initialize members, we do so using a member initializer
// list (often called a “member initialization list”)

// member initializer list is defined after the constructor parameters. It
// begins with a colon (:), and then lists each member to initialize along with
// the initialization value for that variable, separated by a comma. You must
// use a direct form of initialization here (preferably using braces, but
// parentheses works as well) -- using copy initialization (with an equals) does
// not work here. Also note that the member initializer list does not end in a
// semicolon

// BEST PRACTICE- Member variables in a member initializer list should be listed
// in order that they are defined in the class.
// BEST PRACTICE- Prefer using the member initializer list to initialize your
// members over assigning values in the body of the constructor.

/* class Foo {
private:
  int m_x{};
  int m_y{};

public:
  // members in a member initializer list are always initialized in the order in
  // which they are defined inside the class (not in the order they are defined
  // in the member initializer list)
  Foo(int x, int y)
      : m_x{x}, m_y{y} // here's our member initialization list
  {
    std::cout << "Foo(" << x << ", " << y << ") constructed\n";
  }

  void print() const { std::cout << "Foo(" << m_x << ", " << m_y << ")\n"; }
};

int main() {
  Foo foo{6, 7};
  foo.print();

  return 0;
} */

// ######################################################
// Members can be initialized in a few different ways:

// * If a member is listed in the member initializer list, that initialization
// value is used
// * Otherwise, if the member has a default member initializer, that
// initialization value is used
// * Otherwise, the member is default initialized.
// This means that if a member has both a default member initializer and is
// listed in the member initializer list for the constructor, the member
// initializer list value takes precedence.

// Here’s an example showing all three initialization methods:
class Foo {
private:
  int m_x{}; // default member initializer (will be ignored)
  // m_x first to be initialized since it is in the list
  int m_y{2}; // default member initializer (will be used)
  // not in the list, use  default
  int m_z; // no initializer
  // no initializer or default. undefined behavior

public:
  Foo(int x)
      : m_x{x} // member initializer list

  // statements in the body of the constructor execute after the member
  // initializer list has executed, we can add statements to do any other setup
  // tasks required. In the above examples, we print something to the console to
  // show that the constructor executed, but we could do other things like open
  // a file or database, allocate memory, etc…
  {
    // m_x = x; // incorrect: this is an assignment, not an initialization
    // m_y = y; // incorrect: this is an assignment, not an initialization
    std::cout << "Foo constructed\n";
  }

  void print() const {
    std::cout << "Foo(" << m_x << ", " << m_y << ", " << m_z << ")\n";
  }
};

int main() {
  Foo foo{6};
  foo.print();

  return 0;
}
