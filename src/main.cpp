// Learncpp.com: section 13.3 Unscoped enumerator integral conversions

/*
Note in this case, horse and giraffe have been given the same value. When this
happens, the enumerators become non-distinct -- essentially, horse and giraffe
are interchangeable. Although C++ allows it, assigning the same value to two
enumerators in the same enumeration should generally be avoided.

Most of the time, the default values for enumerators will be exactly what you
want, so do not provide your own values unless you have a specific reason to do
so
*/

// BEST PRACTICE- Avoid assigning explicit values to your enumerators unless you
// have a compelling reason to do so.
#include <iostream>

/* enum Animal {
  cat = -3, // -3
  dog,      // -2
  pig,      // -1
  // note: no enumerator with value 0 in this list
  horse = 5,   // 5
  giraffe = 5, // 5
  // If there is an enumerator with value 0, value-initialization defaults the
  // enumeration to the meaning of that enumerator. For example, using the prior
  // enum Color example, a value-initialized Color will default to black). For
  // this reason, it is a good idea to consider making the enumerator with value
  // 0 the one that represents the best default meaning for your enumeration
  chicken = 0, // 6
};

int main() {
  Animal a{};     // value-initialization zero-initializes a to value 0
  std::cout << a; // prints 0

  // If there is no enumerator with value 0, value-initialization makes it easy
  // to create a semantically invalid enumeration. In such cases, we recommend
  // adding an “invalid” or “unknown” enumerator with value 0 so that you have
  // documentation for the meaning of that state, and a name for that state that
  // you can explicitly handle.

  return 0;
}
 */
// #######################################################
/* // an unscoped enumeration will implicitly convert to an integral value.
Because
// enumerators are compile-time constants, this is a constexpr conversion
enum Color {
  black,   // assigned 0
  red,     // assigned 1
  blue,    // assigned 2
  green,   // assigned 3
  white,   // assigned 4
  cyan,    // assigned 5
  yellow,  // assigned 6
  magenta, // assigned 7
};

int main() {
  Color shirt{blue};

  std::cout << "Your shirt is " << shirt << '\n'; // what does this do?

  return 0;
}
 */
/*
#include <cstdint> // for std::int8_t
#include <iostream>
// It is possible to explicitly specify an underlying type for an enumeration.
// The underlying type must be an integral type. For example, if you are working
// in some bandwidth-sensitive context (e.g. sending data over a network) you
// may want to specify a smaller type for your enumeration:

// BEST PRACTICE- Specify the base type of an enumeration only when necessary.

// Use an 8-bit integer as the enum underlying type
enum Color : std::int8_t {
  black,
  red,
  blue,
};

enum Pet // no specified base
{
  cat,   // assigned 0
  dog,   // assigned 1
  pig,   // assigned 2
  whale, // assigned 3
};

int main() {
  Color c{black};
  std::cout << sizeof(c) << '\n'; // prints 1 (byte)

  Pet pet{
      2};  // compile error: integer value 2 won't implicitly convert to a Pet
  pet = 3; // compile error: integer value 3 won't implicitly convert to a Pet
  Pet pet{static_cast<Pet>(2)}; // convert integer 2 to a Pet
  pet = static_cast<Pet>(3);    // our pig evolved into a whale!

  return 0;
}
 */

// if an unscoped enumeration has an explicitly specified base, then the
// compiler will allow you to list initialize an unscoped enumeration using an
// integral value:
enum Pet : int // we've specified a base
{
  cat,   // assigned 0
  dog,   // assigned 1
  pig,   // assigned 2
  whale, // assigned 3
};

int main() {
  Pet pet1{2}; // ok: can brace initialize unscoped enumeration with specified
               // base with integer (C++17)
  // Pet pet2(2);  // compile error: cannot direct initialize with integer
  // Pet pet3 = 2; // compile error: cannot copy initialize with integer

  // pet1 = 3; // compile error: cannot assign with integer

  return 0;
}
