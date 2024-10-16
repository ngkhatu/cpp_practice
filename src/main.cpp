// Learncpp.com: section 13.11- Struct miscellany

// Pass by Reference

#include <iostream>

struct Foo {
  short a{};
  int b{};
  double c{};
};

struct Foo1 {
  short a{}; // will have 2 bytes of padding after a
  int b{};
  short c{}; // will have 2 bytes of padding after c
};

struct Foo2 {
  int b{};
  short a{};
  short c{};
};

struct Employee {
  int id{};
  int age{};
  double wage{};
};

struct Company {
  int numberOfEmployees{};
  Employee CEO{}; // Employee is a struct within the Company struct
};

struct Company2 {
  struct Employee2 // accessed via Company::Employee
  {
    int id{};
    int age{};
    double wage{};
  };

  int numberOfEmployees{};
  Employee2 CEO{}; // Employee is a struct within the Company struct
};

int main() {
  Company myCompany{
      7, {1, 32, 55000.0}}; // Nested initialization list to initialize Employee
  std::cout << myCompany.CEO.wage << '\n'; // print the CEO's wage

  Company myCompany2{
      7, {1, 32, 55000.0}}; // Nested initialization list to initialize Employe
  std::cout << myCompany2.CEO.wage << '\n'; // print the CEO's wage

  // Typically, the size of a struct is the sum of the size of all its members,
  // but not always!
  // * we can only say that the size of a struct will be at least as large as
  // the size of all the variables it contains. But it could be larger! For
  // performance reasons, the compiler will sometimes add gaps into structures
  // (this is called padding)
  std::cout << "The size of short is " << sizeof(short) << " bytes\n";
  std::cout << "The size of int is " << sizeof(int) << " bytes\n";
  std::cout << "The size of double is " << sizeof(double) << " bytes\n";
  std::cout << "The size of Foo is " << sizeof(Foo) << " bytes\n";

  // Foo1 is 50% larger due to the added padding/ memory allocation
  std::cout << sizeof(Foo1) << '\n'; // prints 12
  std::cout << sizeof(Foo2) << '\n'; // prints 8
  return 0;
}
