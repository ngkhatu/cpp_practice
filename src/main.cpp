#include <cassert>
#include <iostream>
#include <string>

// Learncpp.com: Section 12.11- Pass by Address (Part 1)

/* //
################################################################################
//  sample program that shows a std::string object being passed by value and
//  by reference
void printByValue(std::string val) // The function parameter is a copy of str
{
  std::cout << val << '\n'; // print the value via the copy
}

// *  Because our reference parameter is const, we are not allowed to change
// ref. But if ref were non-const, any changes we made to ref would change str
void printByReference(const std::string &ref) // The function parameter is a
                                              // reference that binds to str
{
  std::cout << ref << '\n'; // print the value via the reference
}

// Since printByAddress() will use ptr in a read-only manner, ptr is a pointer
// to a const value
void printByAddress(
    const std::string *ptr) // The function parameter is a pointer that holds
                            // the address of str
{
  std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}

void changeValue(const int *ptr) // note: ptr is now a pointer to a const
{
  //*ptr = 6; // error: can not change const value
}

int main() {
  std::string str{"Hello, world!"};

  printByValue(str);     // pass str by value, makes a copy of str
  printByReference(str); // pass str by reference, does not make a copy of str
  printByAddress(&str);  // pass str by address, does not make a copy of str

  // if we already had a pointer variable holding address of str, could do this
  // instead:
  std::string *ptr{
      &str};           // define a pointer variable holding the address of str
  printByAddress(ptr); // pass str by address, does not make a copy of str

  return 0;
}
 */

/*
// #######################################################
//  When passing a parameter by address, care should be taken to ensure the
//  pointer is not a null pointer before you dereference the value. One way to
//  do that is to use a conditional statement:
void print(int *ptr) {
  if (ptr) // if ptr is not a null pointer
  {
    std::cout << *ptr << '\n';
  }
}

// In most cases, it is more effective to do the opposite: test whether the
// function parameter is null as a precondition (9.6 -- Assert and
// static_assert) and handle the negative case immediately:
void ntest_print(int *ptr) {
  // assert can be used instead
  // assert(ptr); // // fail the program in debug mode if a null pointer is
  // passed
  // (since this should never happen)

  //// (optionally) handle this as an error case in production mode so we don't
  /// crash if it does happen
  if (!ptr)
    return; // if ptr is a null pointer, early return back to the caller

  // if we reached this point, we can assume ptr is valid
  // so no more testing or nesting required

  std::cout << *ptr << '\n';
}
int main() {
  int x{5};

  print(&x);
  print(nullptr);
  ntest_print(&x);
  ntest_print(nullptr);

  return 0;
}
 */

// #########################################################
// “Pass by reference when you can, pass by address when you must”
// ################################################################
// * Prefer Pass by (const) Reference-  has a few other advantages over pass by
// address
// * because an object being passed by address must have an address, only
// lvalues can be passed by address (as rvalues don’t have addresses). Pass by
// const reference is more flexible, as it can accept lvalues and rvalues
// * the syntax for pass by reference is natural, as we can just pass in
// literals or objects. With pass by address, our code ends up littered with
// ampersands (&) and asterisks (*).

void printByValue(int val) // The function parameter is a copy of the argument
{
  std::cout << val << '\n'; // print the value via the copy
}

void printByReference(const int &ref) // The function parameter is a reference
                                      // that binds to the argument
{
  std::cout << ref << '\n'; // print the value via the reference
}

void printByAddress(const int *ptr) // The function parameter is a pointer that
                                    // holds the address of the argument
{
  std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}

int main() {
  printByValue(5);     // valid (but makes a copy)
  printByReference(5); // valid (because the parameter is a const reference)
  // printByAddress(&5);  // error: can't take address of r-value

  return 0;
}
