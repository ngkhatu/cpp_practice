// learncpp.com Section 12.15- std::optional
/*Third, we could abandon returning a single value and return two values
instead: one (of type bool) that indicates whether the function succeeded, and
the other (of the desired return type) that holds the actual return value (if
the function succeeded) or an indeterminate value (if the function failed). This
is probably the best option of the bunch.

Prior to C++17, choosing this latter option required you to implement it
yourself. And while C++ provides multiple ways to do so, any roll-your-own
approach will inevitably lead to inconsistencies and errors.

C++17 introduces std::optional, which is a class template type that implements
an optional value. That is, a std::optional<T> can either have a value of type
T, or not. We can use this to implement the third option above*/
#include <iostream>
#include <optional> // for std::optional (C++17)

// #########################TOP###############################################
// Our function now optionally returns an int value
std::optional<int> doIntDivision(int x, int y) {
  if (y == 0)
    return {}; // or return std::nullopt
  return x / y;
}

int main() {

  std::optional<int> o1{5};            // initialize with a value
  std::optional<int> o2{};             // initialize with no value
  std::optional<int> o3{std::nullopt}; // initialize with no value
  std::optional<int> result1{doIntDivision(20, 5)};
  std::optional<int> result2{doIntDivision(5, 0)};

  if (o1.has_value()) // call has_value() to check if o1 has a value
                      //  if (o2) // use implicit conversion to bool to check if
                      //  o2 has a value

    if (result1) // if the function returned a value
      std::cout << "Result 1: " << *result1 << '\n'; // get the value
    else
      std::cout << "Result 1: failed\n";

  if (result2)
    std::cout << "Result 2: " << *result2 << '\n';
  else
    std::cout << "Result 2: failed\n";

  // Get values from std::optional
  std::cout << *o1; // dereference to get value stored in o1 (undefined behavior
                    // if o1 does not have a value)
  // std::cout << o2.value(); // call value() to get value stored in o2 (throws
  //  std::bad_optional_access exception if o2 does not
  //  have a value)
  std::cout << o3.value_or(42); // call value_or() to get value stored in o3 (or
                                // value `42` if o3 doesn't have a value)

  return 0;
}
// BEST PRACTICE: Return a std::optional (instead of a sentinel value) for
// functions that may fail, unless your function needs to return additional
// information about why it failed
// #################################BOTTOM#######################################

// #########################TOP###############################################
/* //  std::optional as optional function paramenter
void printIDNumber(std::optional<const int> id = std::nullopt) {
  if (id)
    std::cout << "Your ID number is " << *id << ".\n";
  else
    std::cout << "Your ID number is not known.\n";
}

int main() {
  printIDNumber(); // we don't know the user's ID yet

  int userid{34};
  printIDNumber(userid); // we know the user's ID now

  printIDNumber(62); // we can also pass an rvalue

  return 0;
}
 */
// #################################BOTTOM#######################################

// BEST PRACTICE:Prefer std::optional for optional return types.
// Prefer function overloading for optional function parameters (when possible).
// Otherwise, use std::optional<T> for optional arguments when T would normally
// be passed by value. Favor const T* when T is expensive to copy

/*
//ADVANCED
// Although std::optional doesn’t support references directly, you can use
// std::reference_wrapper (which we cover in lesson 17.5 -- Arrays of references
// via std::reference_wrapper) to mimic a reference. Let’s take a look at what
// the above program looks like using a std::string id and
// std::reference_wrapper:
#include <functional>  // for std::reference_wrapper
#include <iostream>
#include <optional>
#include <string>

struct Employee
{
    std::string name{}; // expensive to copy
    int id;
};

void printEmployeeID(std::optional<std::reference_wrapper<Employee>>
e=std::nullopt)
{
    if (e)
        std::cout << "Your ID number is " << e->get().id << ".\n";
    else
        std::cout << "Your ID number is not known.\n";
}

int main()
{
    printEmployeeID(); // we don't know the Employee yet

    Employee e { "James", 34 };
    printEmployeeID(e); // we know the Employee's ID now

    return 0;
} */
