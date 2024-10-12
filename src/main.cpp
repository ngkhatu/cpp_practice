
#include <iostream>
#include <string>

// learncpp.com: section 12.12- Return by Reference and Return by Address

/* // ############################################
// returns a reference that is bound to the object being returned, which avoids
// making a copy of the return value. To return by reference, we simply define
// the return value of the function to be a reference type
// * std::string &returnByReference(); // returns a reference to an existing
// std::string (cheap)
//
// * const std::string& returnByReferenceToConst(); // returns a const reference
// to an existing std::string (cheap)

const std::string &getProgramName() // returns a const reference
{
  static const std::string s_programName{
      "Calculator"}; // has static duration, destroyed at end of program

  return s_programName;
}

int main() {
  std::cout << "This program is named " << getProgramName();

  return 0;
}
// * Using return by reference has one major caveat: the programmer must be sure
// that the object being referenced outlives the function returning the
// reference. Otherwise, the reference being returned will be left dangling
// (referencing an object that has been destroyed), and use of that reference
// will result in undefined behavior
 */

// ####################################################################
/* // function returns a dangling reference:
const std::string &getProgramName() {
  const std::string programName{
      "Calculator"}; // now a non-static local variable, destroyed when function
                     // ends

  return programName;
}

int main() {
  std::cout << "This program is named "
            << getProgramName(); // undefined behavior

  return 0;
}
 */

// ########################bottom###############################################

// ###########################top############################################
/* // Return a temporary by Reference
const int &returnByConstReference() {
  return 5; // returns const reference to temporary object
}

int main() {
  const int &ref{returnByConstReference()};

  std::cout << ref; // undefined behavior

  return 0;
}
// returning an integer literal, but the return type of the function is const
// int&. This results in the creation and return of a temporary reference bound
// to a temporary object holding value 5. This returned reference is copied into
// a temporary reference in the scope of the caller. The temporary object then
// goes out of scope, leaving the temporary reference in the scope of the caller
// dangling */

// ###############################bottom########################################

// ###############################top########################################
/* const int &returnByConstReference(const int &ref) { return ref; }

int main() {
  // case 1: direct binding
  const int &ref1{5};        // extends lifetime
  std::cout << ref1 << '\n'; // okay

  // case 2: indirect binding
  const int &ref2{returnByConstReference(5)}; // binds to dangling reference
  std::cout << ref2 << '\n';                  // undefined behavior

  return 0;
}
// WARNING: Reference lifetime extension does not work across function
// boundaries.
 */

//  #################################bottom######################################

//  ###############################top########################################
/* // Don't return non-const static local variables by reference
// * returning non-const static local variables by reference is fairly
// non-idiomatic, and should generally be avoided
const int &getNextId() {
  static int s_x{0}; // note: variable is non-const
  std::cout << "s_x: " << s_x << std::endl;
  ++s_x; // generate the next id
  std::cout << "s_x: " << s_x << std::endl;
  return s_x; // and return a reference to it
}

int main() {
  const int &id1{getNextId()}; // id1 is a reference
  int i_id1 = id1;
  const int &id2{getNextId()}; // id2 is a reference
  int i_id2 = id2;

  std::cout << id1 << "---" << id2 << '\n';
  std::cout << "Works: " << i_id1 << "---" << i_id2 << '\n';

  return 0;
}
// * id1 and id2 are referencing the same object (the static variable s_x), so
// when anything (e.g. getNextId()) modifies that value, all references are now
// accessing the modified value
// * fixed by making id1 and id2 normal variables (rather than references) so
// they save a copy of the return value rather than a reference
 */
// #################################bottom######################################

// ###############################top########################################
// Correct way from above example (using a normal variable)
/* const int &getNextId() {
  static int s_x{0};
  ++s_x;
  return s_x;
}

int main() {
  const int id1{
      getNextId()}; // id1 is a normal variable now and receives a copy of the
                    // value returned by reference from getNextId()
  const int id2{
      getNextId()}; // id2 is a normal variable now and receives a copy of the
                    // value returned by reference from getNextId()

  std::cout << id1 << id2 << '\n';

  return 0;
} */
// #################################bottom######################################

// ###############################top########################################
/* // Dangling Reference
#include <iostream>
#include <string>

const std::string &getProgramName() // will return a const reference
{
  const std::string programName{"Calculator"};

  return programName;
}

int main() {
  std::string name{getProgramName()}; // makes a copy of a dangling reference
  std::cout << "This program is named " << name << '\n'; // undefined behavior

  return 0;
} */
// #################################bottom######################################

// ###############################top########################################
/* // If a parameter is passed into a function by reference, it’s safe to return
// that parameter by reference. This makes sense: in order to pass an argument
// to a function, the argument must exist in the scope of the caller. When the
// called function returns, that object must still exist in the scope of the
// caller.

// Takes two std::string objects, returns the one that comes first
// alphabetically
const std::string &firstAlphabetical(const std::string &a,
                                     const std::string &b) {
  return (a < b) ? a : b; // We can use operator< on std::string to determine
                          // which comes first alphabetically
}

int main() {
  std::string hello{"Hello"};
  std::string world{"World"};

  std::cout << firstAlphabetical(hello, world) << '\n';

  return 0;
}
 */
// #################################bottom######################################

// ###############################top########################################
/* // * When an argument for a const reference parameter is an rvalue, it’s
still
// okay to return that parameter by const reference.

// This is because rvalues are not destroyed until the end of the full
// expression in which they are created.
std::string getHello() { return std::string{"Hello"}; }

int main() {
  const std::string s{getHello()};

  std::cout << s;

  return 0;
}
// In this case, getHello() returns a std::string by value, which is an rvalue.
// This rvalue is then used to initialize s. After the initialization of s, the
// expression in which the rvalue was created has finished evaluating, and the
// rvalue is destroyed. */
// #################################bottom######################################

// ###############################top########################################
/* // difference in this case is that the rvalue is passed by const reference to
// foo() and then returned by const reference back to the caller before it is
// used to initialize s. Everything else works identically.

const std::string &foo(const std::string &s) { return s; }

std::string getHello() { return std::string{"Hello"}; }

int main() {
  const std::string s{foo(getHello())};

  std::cout << s;

  return 0;
} */
// #################################bottom######################################

// ###############################top########################################
// takes two integers by non-const reference, and returns the greater by
// reference
int &max(int &x, int &y) { return (x > y) ? x : y; }

int main() {
  int a{5};
  int b{6};

  max(a, b) = 7; // sets the greater of a or b to 7

  std::cout << a << b << '\n';

  return 0;
}
// #################################bottom######################################

// ###############################top########################################

// #################################bottom######################################

// ###############################top########################################

// #################################bottom######################################

// ###############################top########################################

// #################################bottom######################################

// ###############################top########################################

// #################################bottom######################################

// ###############################top########################################

// #################################bottom######################################

// ###############################top########################################

// #################################bottom######################################
