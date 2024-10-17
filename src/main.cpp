// Learncpp.com: section- 7.7 — External linkage and variable forward
// declarations

// An identifier with external linkage can be seen and used both from the file
// in which it is defined, and from other code files (via a forward
// declaration). In this sense, identifiers with external linkage are truly
// “global” in that they can be used anywhere in your program

// * In order to call a function defined in another file, you must place a
// forward declaration for the function in any other files wishing to use the
// function. The forward declaration tells the compiler about the existence of
// the function, and the linker connects the function calls to the actual
// function definition.

#include <iostream>

extern int g_x; // this extern is a forward declaration of a variable named g_x
                // that is defined somewhere else
extern const int g_y; // this extern is a forward declaration of a const
                      // variable named g_y that is defined somewhere else

// Note that function forward declarations don’t need the extern keyword -- the
// compiler is able to tell whether you’re defining a new function or making a
// forward declaration based on whether you supply a function body or not.
// Variables forward declarations do need the extern keyword to help
// differentiate uninitialized variables definitions from variable forward
// declarations (they look otherwise identical):
void sayHi(); // forward declaration for function sayHi, makes sayHi
// accessible
//  in this file

int main() {
  sayHi(); // call to function defined in another file, linker will connect this
  // call to the function definition

  std::cout << g_x << ' ' << g_y << '\n'; // prints 2 3

  return 0;
}

// ###########################################
// Global Variables with external linkage
// use the 'extern' keyword

int g_x{2}; // non-constant globals are external by default

extern const int g_y{
    3}; // const globals can be defined as extern, making them external
extern constexpr int g_z{
    3}; // constexpr globals can be defined as extern, making them external (but
        // this is pretty useless, see the warning in the next section)
//--------------------------------------------------

// non-constant
int g_x;        // variable definition (can have initializer if desired)
extern int g_x; // forward declaration (no initializer)

// constant
extern const int g_y{1}; // variable definition (const requires initializers)
extern const int g_y;    // forward declaration (no initializer)

// SUMMARY
//----------------------------------------------
// Forward declarations:
extern int g_y;                // forward declaration for non-constant global
variable extern const int g_y; // forward declaration for const global
variable extern constexpr int
    g_y; // not allowed: constexpr variables can't be forward declared

// External global variable definitions:
int g_x; // defines non-initialized external global variable (zero initialized
         // by default)
extern const int g_x{1}; // defines initialized const external global variable
extern constexpr int g_x{
    2}; // defines initialized constexpr external global variable
