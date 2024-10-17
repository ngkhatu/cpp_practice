#include "constants.h"

// Because global symbolic constants should be namespaced (to avoid naming
// conflicts with other identifiers in the global namespace), the use of a “g_”
// naming prefix is not necessary.

// Now the symbolic constants will get instantiated only once (in constants.cpp)
// instead of in each code file where constants.h is #included, and all uses of
// these constants will be linked to the version instantiated in constants.cpp.
// Any changes made to constants.cpp will require recompiling only
// constants.cpp.

namespace constants {
// actual global variables
extern constexpr double pi{3.14159};
extern constexpr double avogadro{6.0221413e23};
extern constexpr double myGravity{
    9.2}; // m/s^2 -- gravity is light on this planet
} // namespace constants
