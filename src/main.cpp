// Learncpp.com: section 14.16- Converting constructors and the explicit keyword

#include <iostream>

// BEST PRACTICE- * Make any constructor that accepts a single argument explicit
// by default. If an implicit conversion between types is both semantically
// equivalent and performant, you can consider making the constructor
// non-explicit.
// * Do not make copy or move constructors explicit, as these do not perform
// conversion

/* class Foo {
private:
  int m_x{};

public:
  Foo(int x) : m_x{x} {}

  int getX() const { return m_x; }
};

// printFoo has a Foo parameter but we’re passing in an argument of type int.
// Because these types do not match, the compiler will try to implicitly convert
// int value 5 into a Foo object so the function can be called
void printFoo(Foo f) // has a Foo parameter
{
  std::cout << f.getX();
}

int main() {
  // user-defined conversion: compiler will look to see if we have defined some
  // function that it can use to perform such a conversion
  printFoo(5); // we're supplying an int argument

  return 0;
}
 */

// ####################################################
/* #include <iostream>
#include <string>
#include <string_view>

class Employee {
private:
  std::string m_name{};

public:
  Employee(std::string_view name) : m_name{name} {}

  const std::string &getName() const { return m_name; }
};

void printEmployee(Employee e) // has an Employee parameter
{
  std::cout << e.getName();
}

int main() {

  // only one user-defined conversion may be applied to perform an implicit
  // conversion, and this example requires two.
  //* First, our C-style string literal has to be converted to a
  // std::string_view (using a std::string_view converting constructor)
  //* then our std::string_view has to be converted
  // into an Employee (using the Employee(std::string_view) converting
  // constructor).
  // printEmployee("Joe"); // we're supplying an string literal argument

  // Two ways to make this work:
  // 1) Use a string-view literal
  using namespace std::literals;
  printEmployee("Joe"sv);
  // This works because only one user-defined conversion is now required (from
  // std::string_view to Employee).

  // 2) Explicitly construct an Employee rather than implicitly creating one
  printEmployee(Employee{"Joe"});
  // This also works because only one user-defined conversion is now required
  // (from the string literal to the std::string_view used to initialize the
  // Employee object).

  return 0;
}
 */
// ##########################################################
/* // we can use the explicit keyword to tell the compiler that a constructor
// should not be used as a converting constructor. Two consequences:
// * An explicit constructor cannot be used to do copy initialization or copy
// list initialization.
// * An explicit constructor cannot be used to do implicit conversions (since
// this uses copy initialization or copy list initialization).
class Dollars {
private:
  int m_dollars{};

public:
  // Adding explicit keyword to constructor results in compilation error
  explicit Dollars(int d) : m_dollars{d} {}
  // Dollars(int d) : m_dollars{d} {}

  int getDollars() const { return m_dollars; }
};

// It would be better if our print(Dollars) function could only be called with a
// Dollars object, not any value that can be implicitly converted to a Dollars
// (especially a fundamental type like int). This would reduce the possibility
// of inadvertent errors.
void print(Dollars d) { std::cout << "$" << d.getDollars(); }

int main() {
  // print(5); // compilation error when using explicit constructor

  // Assume Dollars(int) is explicit

  Dollars d1(5);     // ok
  Dollars d2{5};     // ok
  print(Dollars{5}); // ok: explicitly create a Dollars
  print(static_cast<Dollars>(
      5)); // ok: static_cast will use explicit constructors

  return 0;
}
 */

class Foo {
public:
  explicit Foo() // note: explicit (just for sake of example)
  {}

  explicit Foo(int x) // note: explicit
  {}
};

// When we return a value from a function, if that value does not match the
// return type of the function, an implicit conversion will occur. Just like
// with pass by value, such conversions cannot use explicit constructors.
Foo getFoo() {
  /*   // explicit Foo() cases
    return Foo{}; // ok
    return {};    // error: can't implicitly convert initializer list to Foo

    // explicit Foo(int) cases
    return 5;      // error: can't implicitly convert int to Foo
    return Foo{5}; // ok
    return {5};    // error: can't implicitly convert initializer list to Foo */
}

int main() { return 0; }
/*
The modern best practice is to make any constructor that will accept a single
argument explicit by default. This includes constructors with multiple
parameters where most or all of them have default values. This will disallow the
compiler from using that constructor for implicit conversions. If an implicit
conversion is required, only non-explicit constructors will be considered. If no
non-explicit constructor can be found to perform the conversion, the compiler
will error.

If such a conversion is actually desired in a particular case, it is trivial to
convert the implicit conversion into an explicit definition using direct list
initialization.

The following should not be made explicit:

Copy (and move) constructors (as these do not perform conversions).
The following are typically not made explicit:

Default constructors with no parameters (as these are only used to convert {} to
a default object, not something we typically need to restrict). Constructors
that only accept multiple arguments (as these are typically not a candidate for
conversions anyway). However, if you prefer, the above can be marked as explicit
to prevent implicit conversions with empty and multiple-argument lists.

The following should usually be made explicit:

Constructors that take a single argument.
There are some occasions when it does make sense to make a single-argument
constructor non-explicit. This can be useful when all of the following are true:

The constructed object is semantically equivalent to the argument value.
The conversion is performant.
For example, the std::string_view constructor that accepts a C-style string
argument is not explicit, because there is unlikely to be a case when we
wouldn’t be okay with a C-style string being treated as a std::string_view
instead. Conversely, the std::string constructor that takes a std::string_view
is marked as explicit, because while a std::string value is semantically
equivalent to a std::string_view value, constructing a std::string is not
performant.*/
