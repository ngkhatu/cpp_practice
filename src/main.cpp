// Learncpp.com: section 10.7- Typedefs and type aliases

// When the compiler encounters a type alias name, it will substitute in the
// aliased type

#include <iostream>
/*
int main() {

  // * using is a keyword that creates an alias for an existing data type
  //  - followed by a name for the type alias, followed by an equals sign and an
  // existing data type

  using Distance = double; // define Distance as an alias for type double
  // Once defined, a type alias can be used anywhere a type is needed. For
  // example, we can create a variable with the type alias name as the type
  Distance milesToDestination{3.4}; // defines a variable of type double

  std::cout << milesToDestination << '\n'; // prints a double value

  return 0;
} */

/*
Naming type aliases

Historically, there hasn’t been a lot of consistency in how type aliases have
been named. There are three common naming conventions (and you will run across
all of them):

1) Type aliases that end in a “_t” suffix (the “_t” is short for “type”). This
convention is often used by the standard library for globally scoped type names
(like size_t and nullptr_t).

* This convention was inherited from C, and used to
be the most popular when defining your own type aliases (and sometimes other
types), but has fallen out of favor in modern C++. Note that POSIX reserves the
“_t” suffix for globally scoped type names, so using this convention may cause
type naming conflicts on POSIX systems.

2) Type aliases that end in a “_type” suffix. This convention is used by some
standard library types (like std::string) to name nested type aliases (e.g.
std::string::size_type).
* But many such nested type aliases do not use a suffix
at all (e.g. std::string::iterator), so this usage is inconsistent at best.

3) Type aliases that use no suffix.
* In modern C++, the convention is to name type aliases (or any other type) that
you define yourself starting with a capital letter, and using no suffix. The
capital letter helps differentiate the names of types from the names of
variables and functions (which start with a lower case letter), and prevents
naming collisions between them.
*/

/*
// BEST PRACTICE- Name your type aliases starting with a capital letter and do
not use a suffix
// (unless you have a specific reason to do otherwise).
// void printDistance(Distance distance); // Distance is some defined type
// In this case, Distance is the type, and distance is the parameter name. C++
// is case-sensitive, so this is fine. */

// ################################################################
/* // Type alias are not distinct types

// An alias does not actually define a new, distinct type (one that is
// considered separate from other types) -- it just introduces a new identifier
// for an existing type. A type alias is completely interchangeable with the
// aliased type.

// This allows us to do things that are syntactically valid but semantically
// meaningless

#include "mytypes.h"

int main() {
  // Because scope is a property of an identifier, type alias identifiers follow
  // the same scoping rules as variable identifiers
  // using Miles = long; // define Miles as an alias for type long
  // using Speed = long; // define Speed as an alias for type long

  Miles distance{5}; // distance is actually just a long
  Speed mhz{3200};   // mhz is actually just a long

  // The following is syntactically valid (but semantically meaningless)
  distance = mhz;

  // Because the compiler does not prevent these kinds of semantic errors for
  // type aliases, we say that aliases are not type safe. In spite of that, they
  // are still useful.

  // WARNING- Care must be taken not to mix values of aliases that are intended
  // to be semantically distinct.

  {
    using namespace std;
    cout << distance << mhz << endl;
  }
  return 0;
}
 */

// #################################################
/* // A typedef (which is short for “type definition”) is an older way of
creating
// an alias for a type
// - the name “typedef” suggests that a new type is being defined, but that’s
// not true. A typedef is just an alias.

// BEST PRACTICE- Prefer type aliases over typedefs.

// The following aliases are identical
typedef long Miles;
using Miles = long;

typedef int (*FcnType)(double, char);  // FcnType hard to find
using FcnType = int (*)(double, char); // FcnType easier to find
 */

// ####################################################
// Using type aliases to make complex types easier to read

#include <string>  // for std::string
#include <utility> // for std::pair
#include <vector>  // for std::vector

// easier to use a type alias
using VectPairSI =
    std::vector<std::pair<std::string, int>>; // make VectPairSI an alias for
                                              // this crazy type
// bool hasDuplicates(std::vector<std::pair<std::string, int>> pairlist)
bool hasDuplicates(VectPairSI pairlist) {
  // some code here
  return false;
}

int main() {
  // std::vector<std::pair<std::string, int>> pairlist;
  VectPairSI pairlist;

  return 0;
}

// #####################################################
// BEST PRACTICE- Use type aliases judiciously, when they provide a clear
// benefit to code readability or code maintenance.

// Using type aliases to document the meaning of a value

// Type aliases can also help with code documentation and comprehension.
using TestScore = int;
TestScore gradeTest();
