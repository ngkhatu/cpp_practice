#include <cstddef> // for NUL
#include <iostream>

// 12.9- Pointers and Const

int main() {

  // const int x{5}; // x is now const
  //  int *ptr{&x};   // compile error: cannot convert from const int* to int*

  /////////////////////////////////
  // To declare a pointer to a const value, use the const keyword before the
  // pointer’s data type
  // const int x{5};
  // const int *c_ptr{&x}; // okay: ptr is pointing to a "const int"

  //*c_ptr = 6; // not allowed: we can't change a const value
  // * Because the data type being pointed to is const, the value being pointed
  // to can’t be changed.
  // * because a pointer to const is not const itself (it just points to a const
  // value), we can change what the pointer is pointing at by assigning the
  // pointer a new address:
  // const int x{5};
  // const int *cptr{&x}; // ptr points to const int x

  // const int y{6};
  // cptr = &y; // okay: ptr now points at const int y

  ///////////////////////////////////////////
  // * pointer to const can point to non-const variables too
  // int x{5};           // non-const
  // const int *ptr{&x}; // ptr points to a "const int"

  //*ptr = 6; // not allowed: ptr points to a "const int" so we can't change the
  // value through ptr
  // x = 6; // allowed: the value is still non-const when accessed through
  // non-const identifier x

  // #####################################################################
  ////////////////////////////////////////////////////////
  // A const pointer is a pointer whose address can not be changed after
  // initialization
  ///////////////////////////////////////////////////////////
  int x{5};
  // int *const ptr{&x}; // const after the asterisk means this is a const
  // pointer
  //  * Just like a normal const variable, a const pointer must be initialized
  //  upon definition, and this value can’t be changed via assignment:
  int y{6};

  // int *const ptr{&x};  // okay: the const pointer is initialized to the
  // address of x
  // ptr = &y; // error: once initialized, a const pointer can not be changed.
  //*ptr = 6; // okay: the value being pointed to is non-const

  // #####################################################################
  ////////////////////////////////////////////////////////
  // * it is possible to declare a const pointer to a const value by using the
  // const keyword both before the type and after the asterisk:
  int value{5};
  const int *const ptr{&value}; // a const pointer to a const value
  // A const pointer to a const value can not have its address changed, nor can
  // the value it is pointing to be changed through the pointer. It can only be
  // dereferenced to get the value it is pointing at.

  // you only need to remember 4 rules, and they are pretty logical:

  // * A non-const pointer can be assigned another address to change what it is
  // pointing at.
  // * A const pointer always points to the same address, and this address can
  // not be changed.
  // * A pointer to a non-const value can change the value it is pointing to.
  // These can not point to a const value.
  // * A pointer to a const value treats the value as const when accessed
  // through the pointer, and thus can not change the value it is pointing to.
  // These can be pointed to const or non-const l-values (but not r-values,
  // which don’t have an address).

  int v{5};

  int *ptr0{&v}; // points to an "int" but is not const itself, so this is a
                 // normal pointer.
  const int *ptr1{&v}; // points to a "const int" but is not const itself, so
                       // this is a pointer to a const value.
  int *const ptr2{&v}; // points to an "int" and is const itself, so this is a
                       // const pointer (to a non-const value).
  const int *const ptr3{&v}; // points to a "const int" and is const itself, so
                             // this is a const pointer to a const value.

  // if the const is on the left side of the *, the const belongs to the value
  // if the const is on the right side of the *, the const belongs to the
  // pointer

  return 0;
}
