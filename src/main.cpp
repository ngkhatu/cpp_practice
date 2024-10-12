#include <cassert>
#include <cstddef> // for NULL
#include <iostream>
#include <string>

// Learncpp.com: Section 12.11- Pass by Address (Part 2)

/* // ###################################################
//  Pass by address for “optional” arguments
void printIDNumber(const int *id = nullptr) {
  if (id)
    std::cout << "Your ID number is " << *id << ".\n";
  else
    std::cout << "Your ID number is not known.\n";
}

int main() {
  printIDNumber(); // we don't know the user's ID yet

  int userid{34};
  printIDNumber(&userid); // we know the user's ID now

  return 0;
}
 */

/*
// #########################################################
//  in many cases, function overloading is a better alternative to achieve the
//  same result:
// * This has a number of advantages: we no longer have to worry about null
// dereferences, and we can pass in literals or other rvalues as an argument.
void printIDNumber() { std::cout << "Your ID is not known\n"; }

void printIDNumber(int id) { std::cout << "Your ID is " << id << "\n"; }

int main() {
 printIDNumber(); // we don't know the user's ID yet

 int userid{34};
 printIDNumber(userid); // we know the user is 34

 printIDNumber(62); // now also works with rvalue arguments

 return 0;
}
*/
/*
// ##################################################################
//  [[maybe_unused]] gets rid of compiler warnings about ptr2 being set but not
//  used
// * Changing what a pointer parameter points at

// Function is only affecting the copy of the pointer.
void nullify([[maybe_unused]] int *ptr2) {
  ptr2 = nullptr; // Make the function parameter a null pointer
}

void nullify2(int *&refptr) // refptr is now a reference to a pointer
{
  refptr = nullptr; // Make the function parameter a null pointer
}

int main() {
  int x{5};
  int *ptr{&x}; // ptr points to x

  std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

  nullify(ptr);

  std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

  nullify2(ptr);
  std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

  return 0;
}

 */

// #############################################################
// When using 0 or NULL, this can cause problems:
void print(int x) // this function accepts an integer
{
  std::cout << "print(int): " << x << '\n';
}

void print(int *ptr) // this function accepts an integer pointer
{
  std::cout << "print(int*): " << (ptr ? "non-null\n" : "null\n");
}

int main() {
  int x{5};
  int *ptr{&x};

  print(ptr); // always calls print(int*) because ptr has type int* (good)
  print(0);   // always calls print(int) because 0 is an integer literal
              // (hopefully this is what we expected)

  // print(NULL); // this statement could do any of the following:
  //  call print(int) (Visual Studio does this)
  //  call print(int*)
  //  result in an ambiguous function call compilation error (gcc and Clang do
  //  this)

  print(nullptr); // always calls print(int*)

  return 0;
}
