// Learncpp.com: section 13.11- Struct miscellany

// Pass by Reference

#include <iostream>

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

  return 0;
}
