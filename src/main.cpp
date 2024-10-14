// Learncpp.com: section 14.14- Introduction to the copy constructor

#include <iostream>

/* // A copy constructor is a constructor that is used to initialize an object
with
// an existing object of the same type. After the copy constructor executes, the
// newly created object should be a copy of the object passed in as the
// initializer.

class Fraction {
private:
  int m_numerator{0};
  int m_denominator{1};

public:
  // Default constructor
  Fraction(int numerator = 0, int denominator = 1)
      : m_numerator{numerator}, m_denominator{denominator} {}

  void print() const {
    std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
  }
};

int main() {
  Fraction f{5, 3}; // Calls Fraction(int, int) constructor

  // invoking the implicit copy constructor to initialize fCopy with f.

  // By default, the implicit copy constructor will do memberwise
  // initialization. This means each member will be initialized using the
  // corresponding member of the class passed in as the initializer.
  Fraction fCopy{f};

  f.print();
  fCopy.print();

  return 0;
}
 */

// ############################################################
//  Explicitly define our own copy constructor
// BEST PRACTICE- Copy constructors should have no side effects beyond copying.
// BEST PRACTICE- Prefer the implicit copy constructor, unless you have a
// specific reason to create your own.
class Fraction {
private:
  int m_numerator{0};
  int m_denominator{1};

public:
  // Default constructor
  Fraction(int numerator = 0, int denominator = 1)
      : m_numerator{numerator}, m_denominator{denominator} {}

  // A copy constructor should not do anything other than copy an object. This
  // is because the compiler may optimize the copy constructor out in certain
  // cases. If you are relying on the copy constructor for some behavior other
  // than just copying, that behavior may or may not occur.

  // Copy constructor
  // BEST PRACTICE- The copy constructor’s parameter must be a reference
  Fraction(const Fraction &fraction)
      // Initialize our members using the corresponding member of the
      parameter : m_numerator{fraction.m_numerator},
                  m_denominator{fraction.m_denominator} {
    std::cout << "Copy constructor called\n"; // just to prove it works
  }

  // If a class has no copy constructor, the compiler will implicitly generate
  // one for us. If we prefer, we can explicitly request the compiler create a
  // default copy constructor for us using the = default syntax:
  // Fraction(const Fraction &fraction) = default;

  // -Occasionally we run into cases where we do not want objects of a certain
  // class to be copyable. We can prevent this by marking the copy constructor
  // function as deleted, using the = delete syntax
  //  - Delete the copy constructor so no copies can be made
  // - when the compiler goes to find a constructor to initialize fCopy with f,
  // it will see that the copy constructor has been deleted. This will cause it
  // to emit a compile error Fraction(const Fraction &fraction) = delete;

  void print() const {
    std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
  }
};

void printFraction(Fraction f) // f is pass by value
{
  f.print();
}

Fraction generateFraction(int n, int d) {
  Fraction f{n, d};
  return f;
}

int main() {
  Fraction f{5, 3};  // Calls Fraction(int, int) constructor
  Fraction fCopy{f}; // Calls Fraction(const Fraction&) copy constructor

  f.print();
  fCopy.print();

  Fraction g{5, 3};

  printFraction(
      g); // f is copied into the function parameter using copy constructor

  Fraction f2{
      generateFraction(1, 2)}; // Fraction is returned using copy constructor

  printFraction(
      f2); // f2 is copied into the function parameter using copy constructor

  return 0;
}
