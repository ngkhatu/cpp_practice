// Learncpp.com: section- 7.8- Global Variables

// Instead of:
constexpr double gravity{
    9.8}; // unclear if this is a local or global variable from the name

// Do this:

namespace constants {
constexpr double gravity{9.8};
}
// ##############################################
// Instead of this:
//--------------------------------
// constants.cpp
namespace constants {
extern const double gravity{
    9.8}; // has external linkage, can be accessed by other files
}
// main.cpp
#include <iostream>

namespace constants {
extern const double gravity; // forward declaration
}

int main() {
  std::cout << constants::gravity << '\n'; // direct access to global variable

  return 0;
}

// Do This:
//----------------------------------------
// constants.cpp
namespace constants {
constexpr double gravity{
    9.8}; // has internal linkage, is accessible only within this file
}

double getGravity() // has external linkage, can be accessed by other files
{
  // We could add logic here if needed later
  // or change the implementation transparently to the callers
  return constants::gravity;
}

// main.cpp
#include <iostream>

double getGravity(); // forward declaration

int main() {
  std::cout << getGravity() << '\n';

  return 0;
}
