// Learncpp.com: section 7.9- Sharing global constants across multiple
// files(using inline variables)

// In some applications, certain symbolic constants may need to be used
// throughout your code (not just in one location). These can include physics or
// mathematical constants that don’t change (e.g. pi or Avogadro’s number), or
// application-specific “tuning” values (e.g. friction or gravity coefficients).
// Instead of redefining these constants in every file that needs them (a
// violation of the “Don’t Repeat Yourself” rule), it’s better to declare them
// once in a central location and use them wherever needed. That way, if you
// ever need to change them, you only need to change them in one place, and
// those changes can be propagated out.

// ################################################################
//  METHOD 1
//  Prior to C++17. add constants in a header file (constants.h)
//  Downsides:
//* Changing a single constant value would require recompiling every file that
//  includes the constants header, which can lead to lengthy rebuild times for
//  larger projects.
//  * If the constants are large in size and can’t be optimized away, this can
//  use a lot of memory.
/*
#ifndef CONSTANTS_H
#define CONSTANTS_H

// define your own namespace to hold constants
namespace constants
{
    // constants have internal linkage by default
    constexpr double pi { 3.14159 };
    constexpr double avogadro { 6.0221413e23 };
    constexpr double myGravity { 9.2 }; // m/s^2 -- gravity is light on this
planet
    // ... other related constants
}
#endif
*/

// #####################################################
/* // METHOD 2
// One way to avoid these problems is by turning these constants into external
// variables, since we can then have a single variable (initialized once) that
// is shared across all files. In this method, we’ll define the constants in a
// .cpp file (to ensure the definitions only exist in one place), and put
// forward declarations in the header (which will be included by other files)
#include "constants.h" // include all the forward declarations

#include <iostream>

int main() {
  std::cout << "Enter a radius: ";
  double radius{};
  std::cin >> radius;

  std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

  return 0;
}
 */

// #####################################################
// METHOD 3
// By making our constexpr variables inline, we can define them in a header file
// and then #include them into any .cpp file that requires them. This avoids
// both ODR violations and the downside of duplicated variables.
// * Constexpr functions are implicitly inline, but constexpr variables are not
// implicitly inline. If you want an inline constexpr variable, you must
// explicitly mark it as inline.

// * This method does retain the downside of requiring every file that includes
// the constants header be recompiled if any constant value is changed.

// BEST PRACTICE-If you need global constants and your compiler is C++17
// capable, prefer defining inline constexpr global variables in a header file.

// constants.h
/* #ifndef CONSTANTS_H
#define CONSTANTS_H

// define your own namespace to hold constants
namespace constants
{
    inline constexpr double pi { 3.14159 }; // note: now inline constexpr
    inline constexpr double avogadro { 6.0221413e23 };
    inline constexpr double myGravity { 9.2 }; // m/s^2 -- gravity is light on
this planet
    // ... other related constants
}
#endif
*/

//--------------------------------------------
// main.cpp
/*
#include "constants.h"

#include <iostream>

int main()
{
    std::cout << "Enter a radius: ";
    double radius{};
    std::cin >> radius;

    std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

    return 0;
}
*/
