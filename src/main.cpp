// Learncpp.com: section 13.1- Intro to program-defined (user-defined) types

// create entirely new, custom types for use in our programs

// two different categories of compound types that can be used to create
// program-defined types
// - Enumerated types (including unscoped and scoped enumerations)
// - Class types (including structs, classes, and unions).

// * The definition for a program-defined type is called a type definition

// Define a program-defined type named Fraction so the compiler understands what
// a Fraction is (we'll explain what a struct is and how to use them later in
// this chapter) This only defines what a Fraction type looks like, it doesn't
// create one
struct Fraction {
  int numerator{};
  int denominator{};
};

// * By convention, program-defined types are named starting with a capital
// letter and don’t use a suffix (e.g. Fraction, not fraction, fraction_t, or
// Fraction_t).

// Now we can make use of our Fraction type
int main() {
  Fraction f{3, 4}; // this actually instantiates a Fraction object named f

  return 0;
}

// BEST PRACTICE- Name your program-defined types starting with a capital letter
// and do not use a suffix.

// * To propagate type definitions into the code files that need them,
// program-defined types are typically defined in header files, and then
// #included into any code file that requires that type definition. These header
// files are typically given the same name as the program-defined type (e.g. a
// program-defined type named Fraction would be defined in Fraction.h)
