#include <iostream>
#include <typeinfo>

int main() {
  /////////////////////////////
  // Address-of operator (&)
  int x{5};
  std::cout << x << '\n'; // print the value of variable x

  // Memory addresses are typically printed out as hex values
  std::cout << &x << '\n'; // print the memory address of variable x
  // * For objects that use more than one byte of memory, address-of will return
  // the memory address of the first byte used by the object.

  ///////////////////////////////
  // Dereference operator (*) --> Also called indirection operator
  // * most useful thing we can do with an address is access the value stored at
  // that address
  // * returns the value at a given memory address as an Ivalue
  std::cout << *(&x)
            << '\n'; // print the value at the memory address of variable x
                     // (parentheses not required, but make it easier to read)

  ///////////////////////////////
  // Pointers --> Raw Pointers --> Dumb Pointers
  // A pointer is an object that holds a memory address (typically of another
  // variable) as its value. This allows us to store the address of some other
  // object to use later
  // int &ref{x}; // an lvalue reference to an int value

  // int *ptr; // a pointer to an int value (holds the address of an integer
  // value)
  // * Note that this asterisk is part of the declaration syntax for pointers,
  // not a use of the dereference operator.
  // * Not initialized by default. Sometimes called a wild pointer. Contains a
  // garbage address.
  // * Always intialize to a known value.
  // int *ptr;      // an uninitialized pointer (holds a garbage address)
  int *ptr2{};   // a null pointer (we'll discuss these in the next lesson)
  int *ptr3{&x}; // a pointer initialized with the address of variable x

  std::cout << *ptr3
            << '\n'; // use dereference operator to print the value at the
                     // address that ptr3 is holding (which is x's address)

  ///////////////////////////////
  // Much like the type of a reference has to match the type of object being
  // referred to, the type of the pointer has to match the type of the object
  // being pointed to

  int i{5};
  double d{7.0};

  // int *iPtr{&i}; // ok: a pointer to an int can point to an int object
  //  int *iPtr2{&d}; // not okay: a pointer to an int can't point to a double
  //  object
  double *dPtr{&d}; // ok: a pointer to a double can point to a double object
  // double *dPtr2{&i}; // not okay: a pointer to a double can't point to an int
  // object

  // * One Exception- Initializing a pointer with a literal value is disallowed
  // int *ptr{5};          // not okay
  // int *ptr{0x0012FF7C}; // not okay, 0x0012FF7C is treated as an integer
  // literal

  /////////////////////////////////////
  int *ptr{&x}; // initialize ptr with address of variable x

  std::cout << x << '\n';    // print x's value
  std::cout << *ptr << '\n'; // print the value at the address that ptr is
                             // holding (x's address)

  *ptr = 6; // The object at the address held by ptr (x) assigned value 6 (note
            // that ptr is dereferenced here)

  std::cout << x << '\n';
  std::cout << *ptr << '\n'; // print the value at the address that ptr is
                             // holding (x's address)

  //////////////////////////////////////////////////////

  // Pointers and lvalue references behave similarly
  x = 5;
  int &ref{x}; // get a reference to x
  // int *ptr{&x}; // get a pointer to x

  std::cout << x;
  std::cout << ref;          // use the reference to print x's value (5)
  std::cout << *ptr << '\n'; // use the pointer to print x's value (5)

  ref = 6; // use the reference to change the value of x
  std::cout << x;
  std::cout << ref;          // use the reference to print x's value (6)
  std::cout << *ptr << '\n'; // use the pointer to print x's value (6)

  *ptr = 7; // use the pointer to change the value of x
  std::cout << x;
  std::cout << ref;          // use the reference to print x's value (7)
  std::cout << *ptr << '\n'; // use the pointer to print x's value (7)

  ////////////////////////////////////////
  // There are some other differences between pointers and references worth
  // mentioning :

  /*
  * References must be initialized, pointers are not required to be
  initialized (but should be).

  * References are not objects, pointers are.

  * References can not be reseated (changed to reference something else),
  pointers can change what they are pointing at.

  * References must always be bound to an object, pointers can point to
  nothing (we’ll see an example of this in the next lesson).

  * References are “safe” (outside of dangling references), pointers are
  inherently dangerous (we’ll also discuss this in the next lesson).
  */

  //////////////////////////
  // address-of operator (&) doesn’t return the address of its operand as a
  // literal. Instead, it returns a pointer containing the address of the
  // operand, whose type is derived from the argument (e.g. taking the address
  // of an int will return the address in an int pointer).
  std::cout << typeid(&x).name() << '\n'; // print the type of &x
  // * With gcc, this prints “pi” (pointer to int) instead. Because the result
  // of typeid().name() is compiler-dependent, your compiler may print something
  // different, but it will have the same meaning.

  // Size of Pointers
  // * The size of a pointer is dependent upon the architecture the executable
  // is compiled for -- a 32-bit executable uses 32-bit memory addresses --
  // consequently, a pointer on a 32-bit machine is 32 bits (4 bytes). With a
  // 64-bit executable, a pointer would be 64 bits (8 bytes). Note that this is
  // true regardless of the size of the object being pointed to:
  char *chPtr{};        // chars are 1 byte
  int *iPtr{};          // ints are usually 4 bytes
  long double *ldPtr{}; // long doubles are usually 8 or 12 bytes

  std::cout << sizeof(chPtr) << '\n'; // prints 8
  std::cout << sizeof(iPtr) << '\n';  // prints 8
  std::cout << sizeof(ldPtr) << '\n'; // prints 8
  // The size of the pointer is always the same. This is because a pointer is
  // just a memory address, and the number of bits needed to access a memory
  // address is constant.
  /////////////////////////////////////
  // * Much like a dangling reference, a dangling pointer is a pointer that is
  // holding the address of an object that is no longer valid
  // * assign an invalid pointer a new value, such as nullptr (because this
  // doesn’t use the invalid pointer’s value)
  // int x{5};
  // int *ptr{&x};
  x = 5;
  ptr = &x;
  std::cout << *ptr << '\n'; // valid

  {
    int y{6};
    ptr = &y;

    std::cout << *ptr << '\n'; // valid
  } // y goes out of scope, and ptr is now dangling

  std::cout << *ptr << '\n'; // undefined behavior from dereferencing a dangling
                             // pointer (may or may not print)

  return 0;
}
