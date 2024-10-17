// Learncpp.com: section 7.10 (static local variables)

// Using the static keyword on a local variable changes its duration from
// automatic duration to static duration. This means the variable is now created
// at the start of the program, and destroyed at the end of the program (just
// like a global variable). As a result, the static variable will retain its
// value even after it goes out of scope!

#include <iostream>

// BEST PRACTICE- Initialize your static local variables. Static local variables
// are only initialized the first time the code is executed, not on subsequent
// calls.

// BEST PRACTICE- Const static local variables are generally okay to use.
// * Non-const static local variables should generally be avoided. If you do use
// them, ensure the variable never needs to be reset, and isn’t used to alter
// program flow.

void incrementAndPrint() {

  // Static local variables that have no initializer or a non-constexpr
  // initializer are zero-initialized at program start. Static local variables
  // with a non-constexpr initializer are reinitialized the first time the
  // variable definition is encountered. The definition is skipped on subsequent
  // calls, so no futher reinitialization happens. Because they have static
  // duration, static local variables that are not explicitly initialized will
  // be zero-initialized by default.
  static int s_value{1}; // static duration via static keyword.  This
                         // initializer is only executed once.
  ++s_value;
  std::cout << s_value << '\n';
} // s_value is not destroyed here, but becomes inaccessible because it goes out
  // of scope

int main() {
  incrementAndPrint();
  incrementAndPrint();
  incrementAndPrint();

  return 0;
}

// #######################################################

// Static local variables can be made const (or constexpr). One good use for a
// const static local variable is when you have a function that needs to use a
// const value, but creating or initializing the object is expensive (e.g. you
// need to read the value from a database). If you used a normal local variable,
// the variable would be created and initialized every time the function was
// executed. With a const/constexpr static local variable, you can create and
// initialize the expensive object once, and then reuse it whenever the function
// is called.

// Key insight- Static local variables are best used to avoid expensive local
// object initialization each time a function is called.

// * Static local variables should only be used if in your entire program and in
// the foreseeable future of your program, the variable is unique and it
// wouldn’t make sense to reset the variable.
// #####################################################
