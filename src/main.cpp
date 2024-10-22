// Learncpp.com: section 10.6- Explicit type conversion (casting) and
// static_cast

/* double d = 10 / 4; // does integer division, initializes d with value 2.0
double d =
    10.0 / 4.0; // does floating point division, initializes d with value 2.5

int x{10};
int y{4};
double d = x / y; // does integer division, initializes d with value 2.0
 */

/*
C++ comes with a number of different type casting operators (more commonly
called casts) that can be used by the programmer to have the compiler perform
type conversion. Because casts are explicit requests by the programmer, this
form of type conversion is often called an explicit type conversion
*/
//---------------------------------------------------------------------------
// C++ supports 5 different types of casts:
// * C-style casts
// * static casts
// * const casts (should generally be avoided because they are only useful in
//                  rare cases and can be harmful if used incorrectly)
// * dynamic casts
// * reinterpret casts (should generally be avoided because they are only useful
// in rare cases and can be harmful if used incorrectly)
// The latter four are sometimes referred to as named casts.

// - Each cast works the same way. As input, the cast takes an expression whose
// value will be converted, and a target type. As output, the cast returns a
// temporary object of the target type that contains the converted value.
// - The difference between the casts is in what kind of conversions they are
// allowed to perform.

// #########################################################################
// C-style Casts

// In standard C programming, casts are done via operator(), with the name of
// the type to convert to placed inside the parentheses, and the value to
// convert to the right. You may still see these used in code that has been
// converted from C.

/* #include <iostream>

int main() {
  int x{10};
  int y{4};

  double d{(double)x /
           y}; // convert x to a double so we get floating point division
  std::cout << d << '\n'; // prints 2.5

  // C++ will also let you use a C-style cast with a more function-call like
  // syntax:
  double e{double(x) /
           y}; // convert x to a double so we get floating point division
  std::cout << e << '\n'; // prints 2.5

  return 0;
}
 */
// Although a C-style cast appears to be a single cast, it can actually perform
// a variety of different conversions depending on context. This can include a
// static cast, a const cast or a reinterpret cast (the latter two of which we
// mentioned above you should avoid). As a result, C-style casts are at risk for
// being inadvertently misused and not producing the expected behavior,
// something which is easily avoidable by using the C++ casts instead.

// Also, because C-style casts are just a type name, parenthesis, and variable
// or value, they are both difficult to identify (making your code harder to
// read) and even more difficult to search for.

// BEST PRACTICE- Avoid using C-style casts.

/*
For advanced readers
A C-style cast tries to perform the following C++ style casts, in order:

const_cast
static_cast
static_cast, followed by const_cast
reinterpret_cast
reinterpret_cast, followed by const_cast

* There is one thing you can do with a C-style cast that you can’t do with C++
casts: C-style casts can convert a derived object to a base class that is
inaccessible (e.g. because it was privately inherited)
*/

// ##########################################################################
// static_cast should be used to cast most values

// By far the most used cast in C++ is the static cast operator, which is
// accessed via the static_cast keyword. static_cast is used when we want to
// explicitly convert a value of one type into a value of another type.

/* #include <iostream>

int main() {
  char c{'a'};
  std::cout << static_cast<int>(c) << '\n'; // prints 97 rather than a

  return 0;
}
 */
// To perform a static cast, we start with the static_cast keyword, and then
// place the type to convert to inside angled brackets. Then inside parenthesis,
// we place the expression whose value will be converted.
/*
#include <iostream>

int main() {
  int x{10};
  int y{4};

  // static cast x to a double so we get floating point division
  double d{static_cast<double>(x) / y};
  std::cout << d << '\n'; // prints 2.5

  return 0;
} */
// There are two important properties of static_cast.
// * First, static_cast provides compile-time type checking. If we try to
// convert a value to a type and the compiler doesn’t know how to perform that
// conversion, we will get a compilation error.
// a C-style string literal can't be converted to an int, so the following is an
// invalid conversion
// int x{static_cast<int>("Hello")}; // invalid: will produce compilation error
// * Second, static_cast is (intentionally) less powerful than a C-style cast,
// as it will prevent certain kinds of dangerous conversions (such as those that
// require reinterpretation or discarding const).

// BEST PRACTICE- Favor static_cast when you need to convert a value from one
// type to another type.

// ########################################################################
// Using static_cast to make narrowing conversions explicit

// Compilers will often issue warnings when a potentially unsafe (narrowing)
// implicit type conversion is performed. For example, consider the following
// snippet:

int i{48};
char ch = i; // implicit narrowing conversion
// Casting an int (2 or 4 bytes) to a char (1 byte) is potentially unsafe (as
// the compiler can’t tell whether the integer value will overflow the range of
// the char or not), and so the compiler will typically print a warning. If we
// used list initialization, the compiler would yield an error.

// To get around this, we can use a static cast to explicitly convert our
// integer to a char:
int i{48};

// explicit conversion from int to char, so that a char is assigned to variable
// ch
char ch{static_cast<char>(i)};

// When we do this, we’re explicitly telling the compiler that this conversion
// is intended, and we accept responsibility for the consequences (e.g.
// overflowing the range of a char if that happens). Since the output of this
// static cast is of type char, the initialization of variable ch doesn’t
// generate any type mismatches, and hence no warnings or errors.

// Here’s another example where the compiler will typically complain that
// converting a double to an int may result in loss of data:
int i{100};
i = i / 2.5;

// To tell the compiler that we explicitly mean to do this:

int i{100};
i = static_cast<int>(i / 2.5);
