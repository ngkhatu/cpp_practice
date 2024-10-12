#include <cstddef> // for NUL
#include <iostream>

// 12.8- Null Pointers

int main() {

  // Besides a memory address, there is one additional value that a pointer can
  // hold: a null value. A null value (often shortened to null) is a special
  // value that means something has no value. When a pointer is holding a null
  // value, it means the pointer is not pointing at anything. Such a pointer is
  // called a null pointer.
  // * BEST PRACTICE: Value initialize your pointers (to be null pointers) if
  // you are not initializing them with the address of a valid object.
  int *ptr{}; // ptr is now a null pointer, and is not holding an address

  int x{5};
  ptr = &x; // ptr now pointing at object x (no longer a null pointer)

  std::cout << *ptr << '\n'; // print value of x through dereferenced ptr
  ////////////////////////////
  // Much like the keywords true and false represent Boolean literal values, the
  // nullptr keyword represents a null pointer literal. We can use nullptr to
  // explicitly initialize or assign a pointer a null value.

  int value{5};
  int *ptr2{&value}; // ptr2 is a valid pointer
  ptr2 = nullptr;    // Can assign nullptr to make the pointer a null pointer

  // someFunction(nullptr); // we can also pass nullptr to a function that has a
  //  pointer parameter
  /////////////////////////////
  // Much like dereferencing a dangling (or wild) pointer leads to undefined
  // behavior, dereferencing a null pointer also leads to undefined behavior. In
  // most cases, it will crash your application
  ptr = nullptr;
  // std::cout << *ptr << '\n'; // Dereference the null pointer
  ////////////////////////////
  // Checking for null pointers

  // use a conditional to test whether a pointer has value nullptr or not

  // int x{5};
  x = 5;
  // int *ptr{&x};
  ptr = &x;

  if (ptr == nullptr) // explicit test for equivalence
    std::cout << "ptr is null\n";
  else
    std::cout << "ptr is non-null\n";

  int *nullPtr{};
  std::cout << "nullPtr is "
            << (nullPtr == nullptr
                    ? "null\n"
                    : "non-null\n"); // explicit test for equivalence

  /////////////////////////////////
  // pointers will also implicitly convert to Boolean values: a null pointer
  // converts to Boolean value false, and a non-null pointer converts to Boolean
  // value true. This allows us to skip explicitly testing for nullptr and just
  // use the implicit conversion to Boolean to test whether a pointer is a null
  // pointer.
  // int x { 5 };
  // int* ptr { &x };

  // pointers convert to Boolean false if they are null, and Boolean true if
  // they are non-null
  if (ptr) // implicit conversion to Boolean
    std::cout << "ptr is non-null\n";
  else
    std::cout << "ptr is null\n";

  // int *nullPtr{};
  std::cout << "nullPtr is "
            << (nullPtr ? "non-null\n"
                        : "null\n"); // implicit conversion to Boolean

  ///////////////////////
  // avoid dereferencing a null pointer by using a conditional to ensure a
  // pointer is non-null before trying to dereference it
  if (ptr)                     // if ptr is not a null pointer
    std::cout << *ptr << '\n'; // okay to dereference
  else
    // do something else that doesn't involve dereferencing ptr (print an error
    // message, do nothing at all, etc...)
    /////////////////////////////////
    // * Legacy null pointer literals: 0 and NULL
    // float *ptr{0}; // ptr is now a null pointer (for example only, don't do
    // this)

    // float *ptr2; // ptr2 is uninitialized
    // ptr2 = 0;      // ptr2 is now a null pointer (for example only, don't do
    // this)

    // there is a preprocessor macro named NULL (defined in the <cstddef>
    // header). This macro is inherited from C, where it is commonly used to
    // indicate a null pointe
    double *d_ptr{NULL}; // ptr is a null pointer

  // double *ptr2; // ptr2 is uninitialized
  ptr2 = NULL; // ptr2 is now a null pointer
  // * Both 0 and NULL should be avoided in modern C++ (use nullptr instead)

  ////////////////////////////////
  // Favor references over pointers whenever possible

  // * Pointers and references both give us the ability to access some other
  // object indirectly.

  // * Pointers have the additional abilities of being able to change what
  // they are pointing at, and to be pointed at null. However, these pointer
  // abilities are also inherently dangerous: A null pointer runs the risk
  // of being dereferenced, and the ability to change what a pointer is
  // pointing at can make creating dangling pointers easier
  // int *ptr{};
  ptr = nullptr;

  {
    int x{5};
    ptr = &x; // assign the pointer to an object that will be destroyed (not
              // possible with a reference)
  } // ptr is now dangling and pointing to invalid object

  /*
    if (ptr)             // condition evaluates to true because ptr is not
    nullptr std::cout << *ptr; // undefined behavior
  */

  // Since references can’t be bound to null, we don’t have to worry about null
  // references. And because references must be bound to a valid object upon
  // creation and then can not be reseated, dangling references are harder to
  // create.

  return 0;
}
