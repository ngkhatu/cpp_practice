// Learncpp.com: section 10.2- Floating-point and integral promotion

// Because C++ is designed to be portable and performant across a wide range of
// architectures, the language designers did not want to assume a given CPU
// would be able to efficiently manipulate values that were narrower than the
// natural data size for that CPU.

// To help address this challenge, C++ defines a category of type conversions
// informally called the numeric promotions. A numeric promotion is the type
// conversion of certain narrower numeric types (such as a char) to certain
// wider numeric types (typically int or double) that can be processed
// efficiently.

// All numeric promotions are value-preserving. A value-preserving conversion
// (also called a safe conversion) is one where every possible source value can
// be converted into an equal value of the destination type.

// Because promotions are safe, the compiler will freely use numeric promotion
// as needed, and will not issue a warning when doing so.

// ----------------------------------------------------------
// Reduce Redundancy
// we can write functions that have int and/or double parameters (such as the
// printInt() function). That same code can then be called with arguments
// of types that can be numerically promoted to match the types of the function
// parameters

/* #include <iostream>

void printInt(int x) { std::cout << x << '\n'; } */

// ----------------------------------------------------------
// Categories:
// numeric promotion rules are divided into two subcategories: integral
// promotions and floating point promotions. Only the conversions listed in
// these categories are considered to be numeric promotions.
// ----------------------------------------------------------
// Floating Point Promotions
// Using the floating point promotion rules, a value of type float can be
// converted to a value of type double.

// This means we can write a function that takes a double and then call it with
// either a double or a float value:

/* #include <iostream>

void printDouble(double d) { std::cout << d << '\n'; }

int main() {
  printDouble(5.0);  // no conversion necessary
  printDouble(4.0f); // numeric promotion of float to double
  return 0;
} */
// ----------------------------------------------------------
// Integral Promotions
/*
the following conversions can be made:
....................................................
* signed char or signed short can be converted to int.
* unsigned char, char8_t, and unsigned short can be converted to int if int can
hold the entire range of the type, or unsigned int otherwise.
* If char is signed by default, it follows the signed char conversion rules
above. If it is unsigned by default, it follows the unsigned char conversion
rules above.
* bool can be converted to int, with false becoming 0 and true becoming 1.
Assuming an 8 bit byte and an int size of 4 bytes or larger (which is typical
these days), the above basically means that bool, char, signed char, unsigned
char, signed short, and unsigned short all get promoted to int.
*/
// *  while integral promotion is value-preserving, it does not necessarily
// preserve the signedness (signed/unsigned) of the type.
#include <iostream>

void printInt(int x) { std::cout << x << '\n'; }

int main() {
  printInt(2);

  short s{3};  // there is no short literal suffix, so we'll use a variable for
               // this one
  printInt(s); // numeric promotion of short to int

  printInt('a');  // numeric promotion of char to int
  printInt(true); // numeric promotion of bool to int

  return 0;
}
// ----------------------------------------------------------
// Not all widening converstions are numberic promotions
// widening type conversions (such as char to short, or int to long) are not
// considered to be numeric promotions in C++ (they are numeric conversions,
// which we’ll cover shortly in lesson 10.3 -- Numeric conversions). This is
// because such conversions do not assist in the goal of converting smaller
// types to larger types that can be processed more efficiently.

// ----------------------------------------------------------
// ----------------------------------------------------------
// ----------------------------------------------------------
// ----------------------------------------------------------
// ----------------------------------------------------------
// ----------------------------------------------------------
// ----------------------------------------------------------
