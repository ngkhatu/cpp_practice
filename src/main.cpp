// Learncpp.com: section 9.6- Assert and Static Assert

// In a function that takes parameters, the caller may be able to pass in
// arguments that are syntactically valid but semantically meaningless

// ###############################################
/* //  Preconditions, invariants, and postconditions
//-----------------------------------------------
//  * In programming, a precondition is any condition that must be true prior to
//  the execution of some section of code (typically the body of a function). In
//  the prior example, our check that y != 0 is a precondition that ensures y
//  has a non-zero value before dividing by y.

// Preconditions for a function are best placed at the top of a function, using
// an early return to return back to the caller if the precondition isn’t met
void printDivision(int x, int y) {
  if (y == 0) // handle
  {
    std::cerr << "Error: Could not divide by zero\n";
    return; // bounce the user back to the caller
  }

  // We now know that y != 0
  std::cout << static_cast<double>(x) / y;
}
// * An invariant is a condition that must be true while some section of code is
// executing. This is often used with loops, where the loop body will only
// execute so long as the invariant is true.

// * Similarly, a postcondition is something that must be true after the
// execution of some section of code. Our function doesn’t have any
// postconditions.
 */
// ##############################################

/* // An assertion is an expression that will be true unless there is a bug in
the
// program. If the expression evaluates to true, the assertion statement does
// nothing. If the conditional expression evaluates to false, an error message
// is displayed and the program is terminated (via std::abort). This error
// message typically contains the expression that failed as text, along with the
// name of the code file and the line number of the assertion

// In C++, runtime assertions are implemented via the assert preprocessor macro,
// which lives in the <cassert> header.

#include <cassert> // for assert()
#include <cmath>   // for std::sqrt
#include <iostream>

double calculateTimeUntilObjectHitsGround(double initialHeight,
                                          double gravity) {
  assert(gravity > 0.0); // The object won't reach the ground unless there is
                         // positive gravity.

  if (initialHeight <= 0.0) {
    // The object is already on the ground. Or buried.
    return 0.0;
  }

  return std::sqrt((2.0 * initialHeight) / gravity);
}

int main() {
  std::cout << "Took " << calculateTimeUntilObjectHitsGround(100.0, -9.8)
            << " second(s)\n";

  return 0;
} */

// Make assert statements more descriptive(string literal always evaluates to
// Boolean true): assert(found && "Car could not be found in database");

// Can use assertions to document cases that were not implemented because not
// needed at the time. code will fail with a useful error message, and the
// programmer can then determine how to implement that case
// assert(moved && "Need to handle case where student was just moved to another
// classroom");

// ##################################################
// NDEBUG
// assert macro comes with a small performance cost that is incurred each time
// the assert condition is checked. Furthermore, asserts should (ideally) never
// be encountered in production code (because your code should already be
// thoroughly tested). Consequently, most developers prefer that asserts are
// only active in debug builds. C++ comes with a built-in way to turn off
// asserts in production code: if the preprocessor macro NDEBUG is defined, the
// assert macro gets disabled.

// ######################################################
//  static_assert

// A static_assert is an assertion that is checked at compile-time rather than
// at runtime, with a failing static_assert causing a compile error. Unlike
// assert, which is declared in the <cassert> header, static_assert is a
// keyword, so no header needs to be included to use it.

static_assert(sizeof(long) == 8, "long must be 8 bytes");
static_assert(sizeof(int) >= 4, "int must be at least 4 bytes");

int main() { return 0; }
// Useful notes on static_assert
// ------------------------------------------
// * Because static_assert is evaluated by the compiler, the condition must be a
// constant expression.
// * static_assert can be placed anywhere in the code file (even in the global
// namespace).
// * static_assert is not deactivated in release builds (like normal assert is).
// * Because the compiler does the evaluation, there is no runtime cost to a
// static_assert

// BEST PRACTICE- Favor static_assert over assert() whenever possible.
// #############################################################

// Assertions are used to detect programming errors during development by
// documenting assumptions about things that should never happen. And if they do
// happen, it’s the fault of the programmer. Assertions do not allow recovery
// from errors (after all, if something should never happen, there’s no need to
// recover from it). Because asserts are typically compiled-out in release
// builds, you can put a lot of them in without worrying about performance, so
// there’s little reason not to use them liberally.

// Error handling is used when we need to gracefully handle cases that could
// happen (however rarely) in a release build. These may either be recoverable
// issues (where the program can keep running), or unrecoverable issues (where
// the program has to shut down, but we can at least show a nice error message
// and ensure everything is cleaned up properly). Error detection and handling
// has both a runtime performance cost and a development time cost.

// *** Also note that the abort() function terminates the program immediately,
// without a chance to do any further cleanup (e.g. close a file or database).
// Because of this, asserts should be used only in cases where corruption isn’t
// likely to occur if the program terminates unexpectedly.
