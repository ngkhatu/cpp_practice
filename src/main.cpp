// Learncpp.com: section 15.2- Classes and Header Files

#include "Date.h"
#include <iostream>

// Header Files- Unlike functions, which only need a forward declaration to be
// used, the compiler typically needs to see the full definition of a class (or
// any program-defined type) in order for the type to be used. This is because
// the compiler needs to understand how members are declared in order to ensure
// they are used properly, and it needs to be able to calculate how large
// objects of that type are in order to instantiate them. So our header files
// usually contain the full definition of a class rather than just a forward
// declaration of the class.

// constructor and print() member functions defined outside the class
// definition. Note that the prototypes for these member functions still exist
// inside the class definition (as these functions need to be declared as part
// of the class type definition), but the actual implementation has been moved
// outside:
// * Most often, classes are defined in header files of the same name as the
// class, and any member functions defined outside of the class are put in a
// .cpp file of the same name as the class.

// BEST PRACTICE
// * Prefer to put your class definitions in a header file with the same name as
// the class. Trivial member functions (such as access functions, constructors
// with empty bodies, etc…) can be defined inside the class definition.
// * Prefer to define non-trivial member functions in a source file with the
// same name as the class.
int main() {
  const Date d{2015, 10, 14};
  d.print();

  return 0;
}
