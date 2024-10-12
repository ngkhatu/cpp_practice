
#include <cmath>
#include <iostream>
#include <string>

// learncpp.com: section 12.13- In and Out Parameters
// ###############################top########################################
/* // * Parameters that are used only for receiving input from the caller are
// sometimes called in parameters
// * In-parameters are typically passed by value or by const reference.
void print(int x) // x is an in parameter
{
  std::cout << x << '\n';
}

void print(const std::string &s) // s is an in parameter
{
  std::cout << s << '\n';
}

int main() {
  print(5);
  std::string s{"Hello, world!"};
  print(s);

  return 0;
} */
// #################################bottom######################################
// ###############################top########################################
/* //* A function parameter that is used only for the purpose of returning
// information back to the caller is called an out parameter.

// sinOut and cosOut are out parameters
void getSinCos(double degrees, double &sinOut, double &cosOut) {
  // sin() and cos() take radians, not degrees, so we need to convert
  constexpr double pi{3.14159265358979323846}; // the value of pi
  double radians = degrees * pi / 180.0;
  sinOut = std::sin(radians);
  cosOut = std::cos(radians);
}

int main() {
  double sin{0.0};
  double cos{0.0};

  double degrees{};
  std::cout << "Enter the number of degrees: ";
  std::cin >> degrees;

  // getSinCos will return the sin and cos in variables sin and cos
  getSinCos(degrees, sin, cos);

  std::cout << "The sin is " << sin << '\n';
  std::cout << "The cos is " << cos << '\n';

  return 0;
} */
// out parameters with the suffix “out” to denote that they’re out parameters.
// This helps remind the caller that the initial value passed to these
// parameters doesn’t matter, and that we should expect them to be overwritten.
// By convention, output parameters are typically the rightmost parameters

// #################################bottom######################################

// ###############################top########################################
/*
// * First, the caller must instantiate (and initialize) objects and pass them
as
// arguments, even if it doesn’t intend to use them. These objects must be able
// to be assigned to, which means they can’t be made const.
// * Second, because the caller must pass in objects, these values can’t be used
// as temporaries, or easily used in a single expression.
int getByValue() { return 5; }

void getByReference(int &x) { x = 5; }

int main() {
  // return by value
  [[maybe_unused]] int x{getByValue()}; // can use to initialize object
  std::cout << getByValue()
            << '\n'; // can use temporary return value in expression

  // return by out parameter
  int y{};                // must first allocate an assignable object
  getByReference(y);      // then pass to function to assign the desired value
  std::cout << y << '\n'; // and only then can we use that value

  return 0;
} */
// #################################bottom######################################

// ###############################top########################################
/* // It is not clear from this function call(getSinCos(degrees, sin, cos);)
that
// degrees is an in parameter, but sin and cos are out-parameters. If the caller
// does not realize that sin and cos will be modified, a semantic error will
// likely result.

// Using pass by address instead of pass by reference can in some case help make
// out-parameters more obvious by requiring the caller to pass in the address of
// objects as arguments.
void foo1(int x);  // pass by value
void foo2(int &x); // pass by reference
void foo3(int *x); // pass by address

int main() {
  int i{};

  foo1(i);  // can't modify i
  foo2(i);  // can modify i (not obvious)
  foo3(&i); // can modify i

  int *ptr{&i};
  foo3(ptr); // can modify i (not obvious)
  // *** out-parameters should be avoided unless no other good options exist.

  return 0;
} */

// #################################bottom######################################
// ###############################top########################################

/* // In rare cases, a function will actually use the value of an out-parameter
// before overwriting its value. Such a parameter is called an in-out parameter.
// In-out-parameters work identically to out-parameters and have all the same
// challenges
// #################################bottom######################################
// ###############################top########################################
// it’s often more straightforward and performant to just modify that object
void modifyFoo(int &inout) {
  // modify inout
}

int main() {
  int foo{};
  modifyFoo(foo); // foo modified after this call, slightly more obvious

  return 0;
} */

// #################################bottom######################################

// ###############################top########################################
// alternative is to pass the object by value or const reference instead (as per
// usual) and return a new object by value, which the caller can then assign
// back to the original object:
int someFcn(const int &in) {
  int foo{in}; // copy here
  // modify foo
  return foo;
}

int main() {
  int foo{};
  foo = someFcn(
      foo); // makes it obvious foo is modified, but another copy made here

  return 0;
}
// * This has the benefit of using a more conventional return syntax, but
// requires making 2 extra copies (sometimes the compiler can optimize one of
// these copies away).
// * Second, use pass by non-const reference when a function would
// otherwise return an object by value to the caller, but making a copy of that
// object is extremely expensive. Especially if the function is called many
// times in a performance-critical section of code.

// #################################bottom######################################

// ###############################top########################################

// #################################bottom######################################

// ###############################top########################################

// #################################bottom######################################

// ###############################top########################################

// #################################bottom######################################

// ###############################top########################################

// #################################bottom######################################
