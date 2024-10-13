#include <iostream>
#include <string>

// Learncpp.com: section 14.7- Member functions returning references to data
// members
/*
class Employee {
  std::string m_name{};

public:
  void setName(std::string_view name) { m_name = name; }

  // Returning by value is the safest, but also expensive due to to copying
  // std::string getName() const { return m_name; } //  getter returns by value

  // Returning by lvalue Reference
  // Since member functions are always called on an object, and that object must
  // exist in the scope of the caller, it is generally safe for a member
  // function to return a data member by (const) lvalue reference
  const std::string &getName() const {
    return m_name;
  } //  getter returns by const reference

  // useful way to ensure that no conversions occur:
  // const auto &getName() const {
  //   return m_name;
  // } // uses `auto` to deduce return type from m_name
};

// createEmployee() returns an Employee by value (which means the returned value
// is an rvalue)
Employee createEmployee(std::string_view name) {
  Employee e;
  e.setName(name);
  return e;
}

int main() {
  Employee e{};
  e.setName("Annah");
  std::cout << e.getName();

  // Case 1: okay: use returned reference to member of rvalue class object in
  // same expression
  std::cout << createEmployee("Frank").getName();

  // Case 2: bad: save returned reference to member of rvalue class object for
  // use later
  const std::string &ref{
      createEmployee("Garbo")
          .getName()}; // reference becomes dangling when return value of
                       // createEmployee() is destroyed
  std::cout << ref;    // undefined behavior

  // Case 3: okay: copy referenced value to local variable for use later
  std::string val{
      createEmployee("Hans").getName()}; // makes copy of referenced member
  std::cout << val; // okay: val is independent of referenced member

  return 0;
}

// BEST PRACTICE- Prefer to use the return value of a member function that
// returns by reference immediately, to avoid issues with dangling references
// when the implicit object is an rvalue. */

class Foo {
private:
  int m_value{4}; // private member

public:
  // Because a reference acts just like the object being referenced, a member
  // function that returns a non-const reference provides direct access to that
  // member (even if the member is private).
  int &value() {
    return m_value;
  } // returns a non-const reference (don't do this)
};

int main() {
  Foo f{};                // f.m_value is initialized to default value 4
  f.value() = 5;          // The equivalent of m_value = 5
  std::cout << f.value(); // prints 5

  return 0;
}
