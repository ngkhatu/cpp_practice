// Learncpp.com: section 8.12- Halts (exiting your program early)

// std::exit() performs a number of cleanup functions. First, objects with
// static storage duration are destroyed. Then some other miscellaneous file
// cleanup is done if any files were used. Finally, control is returned back to
// the OS, with the argument passed to std::exit() used as the status code

// Although std::exit() is called implicitly after function main() returns,
// std::exit() can also be called explicitly to halt the program before it would
// normally terminate. When std::exit() is called this way, you will need to
// include the cstdlib header.
/*
#include <cstdlib> // for std::exit()
#include <iostream>

void cleanup() {
  // code here to do any kind of cleanup required
  std::cout << "cleanup!\n";
}

int main() {
  std::cout << 1 << '\n';
  cleanup();

  // Warning! The std::exit() function does not clean up local variables in the
  // current function or up the call stack.
  std::exit(0); // terminate and return status code 0 to operating system

  // std::exit() can be called from any function to terminate the program at
  // that point.
  //  The following statements never execute
  std::cout << 2 << '\n';

  return 0;
} */

// ##########################################################
// Because std::exit() terminates the program immediately, you may want to
// manually do some cleanup before terminating. In this context, cleanup means
// things like closing database or network connections, deallocating any memory
// you have allocated, writing information to a log file, etc…

// remembering to manually call a cleanup function before calling every call to
// exit() adds burden to the programmer and is a recipe for errors.

// To assist with this, C++ offers the std::atexit() function, which allows you
// to specify a function that will automatically be called on program
// termination via std::exit()
/*
#include <cstdlib> // for std::exit()
#include <iostream>

void cleanup() {
  // code here to do any kind of cleanup required
  std::cout << "cleanup!\n";
}

int main() {
  // register cleanup() to be called automatically when std::exit() is called

  // function being registered must take no parameters and have no return value.
  // Finally, you can register multiple cleanup functions using std::atexit() if
  // you want, and they will be called in reverse order of registration (the
  // last one registered will be called first).
  std::atexit(
      cleanup); // note: we use cleanup rather than cleanup() since we're not
                // making a function call to cleanup() right now

  std::cout << 1 << '\n';

  std::exit(0); // terminate and return status code 0 to operating system

  // The following statements never execute
  std::cout << 2 << '\n';

  return 0;
}
 */
// ############################################################

// The std::abort() function causes your program to terminate abnormally.
// Abnormal termination means the program had some kind of unusual runtime error
// and the program couldn’t continue to run. For example, trying to divide by 0
// will result in an abnormal termination. std::abort() does not do any cleanup

#include <cstdlib> // for std::abort()
#include <iostream>

int main() {
  std::cout << 1 << '\n';
  std::abort();

  // The following statements never execute
  std::cout << 2 << '\n';

  return 0;
}
