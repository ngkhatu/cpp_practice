// learncpp.com: section 10.9- Type Deduction for Functions

#include <iostream>

// BEST PRACTICE- Favor explicit return types over function return type
// deduction for normal functions.

// Trailing Return Syntax
//----------------------------
// In this case, auto does not perform type deduction -- it is just part of the
// syntax to use a trailing return type.
// - std::common_type_t<x, y> add(int x, double y);// Compile error:
// compiler hasn't seen definitions of x and y yet
// - auto add(int x, double y) -> std::common_type_t<x, y>; // ok
// *** The trailing return syntax is also required for some advanced features of
// C++, such as lambdas
auto add(auto x, auto y) -> int { return (x + y); }

// When using an auto return type, all return statements within the function
// must return values of the same type, otherwise an error will result
/* auto someFcn(bool b) {
  if (b)
    return 5; // return type int
  else
    return 6.7; // return type double
} */

int main() {
  std::cout << add(5.1, 6.5314) << std::endl;
  std::cout << add(3243243, 132532) << std::endl;
  // std::cout << someFcn(true) << std::endl;
}
