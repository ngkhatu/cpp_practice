// Learncpp.com: section 13.2- Unscoped enumerations
/*
// Define a new unscoped enumeration named Color
enum Color {
  // Here are the enumerators
  // These symbolic constants define all the possible values this type can hold
  // Each enumerator is separated by a comma, not a semicolon
  red,
  green,
  blue, // trailing comma optional but recommended
}; // the enum definition must end with a semicolon

int main() {
  // Define a few variables of enumerated type Color
  Color apple{red};   // my apple is red
  Color shirt{green}; // my shirt is green
  Color cup{blue};    // my cup is blue

  // Color socks{white}; // error: white is not an enumerator of Color
  // Color hat{2};       // error: 2 is not an enumerator of Color

  return 0;
} */

// Enumerators are implicitly constexpr.
/*
using Color = int; // define a type alias named Color

// The following color values should be used for a Color
constexpr Color red{ 0 };
constexpr Color green{ 1 };
constexpr Color blue{ 2 };

int main()
{
    Color appleColor{ red };
    Color shirtColor{ green };

    return 0;
}
*/

// Scoped Enum

// BEST PRACTICE- Prefer putting your enumerations inside a named scope region
// (such as a namespace or class) so the enumerators don’t pollute the global
// namespace.

#include <iostream>

namespace Color {
// The names Color, red, blue, and green are defined inside namespace Color
enum Color {
  red,
  green,
  blue,
};
} // namespace Color

namespace Feeling {
enum Feeling {
  happy,
  tired,
  blue, // Feeling::blue doesn't collide with Color::blue
};
}

int main() {
  Color::Color paint{Color::blue};
  Feeling::Feeling me{Feeling::blue};

  switch (paint) {
  case Color::red:
    std::cout << "red" << std::endl;
    break;
  case Color::green:
    std::cout << "green" << std::endl;
    break;
  case Color::blue:
    std::cout << "blue" << std::endl;
    break;
  }

  return 0;
}
