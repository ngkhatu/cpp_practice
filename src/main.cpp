// Learncpp.com: section 10.3- Numeric conversions

/* // There are five basic types of numeric conversions.
// .................................................................
// 1) Converting an integral type to any other integral type (excluding
// integral promotions):
short s = 3;        // convert int to short
long l = 3;         // convert int to long
char ch = s;        // convert short to char
unsigned int u = 3; // convert int to unsigned int

// 2) Converting a floating point type to any other floating point type
// (excluding floating point promotions):
float f = 3.0;        // convert double to float
long double ld = 3.0; // convert double to long double

// 3) Converting a floating point type to any integral type:
int i = 3.5; // convert double to int

// 4) Converting an integral type to any floating point type:
double d = 3; // convert int to double

// 5) Converting an integral type or a floating point type to a bool:
bool b1 = 3;   // convert int to bool
bool b2 = 3.0; // convert double to bool

// NOTE: brace initialization strictly disallows some types of numeric
conversions, we use copy initialization
 */

// #######################################################################################
// An unsafe conversion is one where at least one value of the source type
// cannot be converted into an equal value of the destination type.

// Numeric conversions fall into three general safety categories:
//..................................................................

// 1) Value-preserving conversions: are safe numeric conversions where the
// destination type can exactly represent all possible values in the source
// type.

/* int main() {
  int n{5};
  long l = n; // okay, produces long value 5

  short s{5};
  double d = s; // okay, produces double value 5.0

  return 0;
} */
// Compilers will typically not issue warnings for implicit value-preserving
// conversions.

// A value converted using a value-preserving conversion can always be converted
// back to the source type, resulting in a value that is equivalent to the
// original value:
/* #include <iostream>

int main() {
  int n =
      static_cast<int>(static_cast<long>(3)); // convert int 3 to long and back
  std::cout << n << '\n';                     // prints 3

  char c = static_cast<char>(
      static_cast<double>('c')); // convert 'c' to double and back
  std::cout << c << '\n';        // prints 'c'

  return 0;
} */

// 2) Reinterpretive conversions: are unsafe numeric conversions where the
// converted value may be different than the source value, but no data is lost.
// Signed/unsigned conversions fall into this category.
// For example, when converting a signed int to an unsigned int:

/* int main() {
  int n1{5};
  unsigned int u1{
      n1}; // okay: will be converted to unsigned int 5 (value preserved)

  int n2{-5};
  unsigned int u2{
      n2}; // bad: will result in large integer outside range of signed int

  return 0;
} */
// Such value changes are typically undesirable, and will often cause the
// program to exhibit unexpected or implementation-defined behavior.

// Values converted using a reinterpretive conversion can be converted back to
// the source type, resulting in a value equivalent to the original value (even
// if the initial conversion produced a value out of range of the source type).
// As such, reinterpretive conversions do not lose data during the conversion
// process.

/* #include <iostream>

int main() {
  int u = static_cast<int>(
      static_cast<unsigned int>(-5)); // convert '-5' to unsigned and back
  std::cout << u << '\n';             // prints -5

  return 0;
}
 */

// 3) Lossy conversions: are unsafe numeric conversions where data may be lost
// during the conversion.

// For example, double to int is a conversion that may result in data loss:
/* int i = 3.0; // okay: will be converted to int value 3 (value preserved)
int j = 3.5; // data lost: will be converted to int value 3 (fractional value
             // 0.5 lost) */
// Conversion from double to float can also result in data loss:
/* float f = 1.2; // okay: will be converted to float value 1.2 (value
preserved)
float g = 1.23456789; // data lost: will be converted to float 1.23457
                      // (precision lost)
*/

// Converting a value that has lost data back to the source type will result in
// a value that is different than the original value:

/* #include <iostream>

int main() {
  double d{static_cast<double>(
      static_cast<int>(3.5))}; // convert double 3.5 to int and back
  std::cout << d << '\n';      // prints 3

  double d2{static_cast<double>(static_cast<float>(
      1.23456789))};       // convert double 1.23456789 to float and back
  std::cout << d2 << '\n'; // prints 1.23457

  return 0;
} */
// For example, if double value 3.5 is converted to int value 3, the fractional
// component 0.5 is lost. When 3 is converted back to a double, the result
// is 3.0, not 3.5.

// Compilers will generally issue a warning (or in some cases, an error) when an
// implicit lossy conversion would be performed at runtime.

// Unsafe conversions should be avoided as much as possible. However, this is
// not always possible. When unsafe conversions are used, it is most often when:
// * We can constrain the values to be converted to just those that can be
// converted to equal values. For example, an int can be safely converted to an
// unsigned int when we can guarantee that the int is non-negative.
// * We don’t mind that some data is lost because it is not relevant. For
// example, converting an int to a bool results in the loss of data, but we’re
// typically okay with this because we’re just checking if the int has value 0
// or not.
// ##########################################################
// * In all cases, converting a value into a type whose range doesn’t support
// that value will lead to results that are probably unexpected. For example:
/* #include <iostream>
int main() {
  int i{30000};
  char c = i; // chars have range -128 to 127

  std::cout << static_cast<int>(c) << '\n';

  return 0;
} */
// In this example, we’ve assigned a large integer to a variable with type char
// (that has range -128 to 127). This causes the char to overflow, and produces
// an unexpected result:

// * Remember that overflow is well-defined for unsigned values and produces
// undefined behavior for signed values.
// * Converting from a larger integral or floating point type to a smaller type
// from the same family will generally work so long as the value fits in the
// range of the smaller type. For example:
/* #include <iostream>
int main() {
  int i{10};
  float f = i;
  std::cout << f << '\n';
} */

// * Converting from a floating point to an integer works as long as the value
// fits within the range of the integer, but any fractional values are lost. For
// example:
#include <iostream>
int main() {
  int i = 3.5;
  std::cout << i << '\n';
  // In this example, the fractional value (.5) is lost, leaving the following
  // result:
}
// While the numeric conversion rules might seem scary, in reality the compiler
// will generally warn you if you try to do something dangerous (excluding some
// signed/unsigned conversions).
