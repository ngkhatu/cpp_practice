// Learncpp.com: section 14.12 Delegating Constructors

// Constructors are allowed to delegate (transfer responsibility for)
// initialization to another constructor from the same class type. This process
// is sometimes called constructor chaining and such constructors are called
// delegating constructors.

// To make one constructor delegate initialization to another constructor,
// simply call the constructor in the member initializer list.

#include <iostream>
#include <string>
#include <string_view>

/*
// BEST PRACTICE- If you have multiple constructors, consider whether you can
// use delegating constructors to reduce duplicate code.
class Employee {
private:
  std::string m_name{};
  int m_id{0};

public:
  // First, a constructor that delegates to another constructor is not allowed
  // to do any member initialization itself. So your constructors can delegate
  // or initialize, but not both.
  // Second, it’s possible for one constructor to delegate to another
  // constructor, which delegates back to the first constructor. This forms an
  // infinite loop, and will cause your program to run out of stack space and
  // crash. You can avoid this by ensuring all of your constructors resolve to a
  // non-delegating constructor
  Employee(std::string_view name)
      : Employee{name, 0}
  // delegate initialization to Employee(std::string_view, int) constructor
  {}
  // The downside of this method is that it sometimes requires duplication of
  // initialization values. In the delegation to the Employee(std::string_view,
  // int) constructor, we need an initialization value for the int parameter. We
  // had to hardcode literal 0, as there is no way to reference the default
  // member initializer

  Employee(std::string_view name, int id)
      : m_name{name}, m_id{id} // actually initializes the members
  {
    std::cout << "Employee " << m_name << " created\n";
  }
};

int main() {
  Employee e1{"James"};
  Employee e2{"Dave", 42};
}
*/
// ##################################################################
// When we have an initialization value that is used in multiple places (e.g. as
// a default member initializer and a default argument for a constructor
// parameter), we can instead define a named constant and use that wherever our
// initialization value is needed. This allows the initialization value to be
// defined in one place.

// The best way to do this is to use a static constexpr member inside the class:

class Employee {
private:
  static constexpr int default_id{
      0}; // define a named constant with our desired initialization value

  std::string m_name{};
  int m_id{default_id}; // we can use it here

public:
  Employee(std::string_view name, int id = default_id) // and we can use it here
      : m_name{name}, m_id{id} {
    std::cout << "Employee " << m_name << " created\n";
  }
};

int main() {
  Employee e1{"James"};
  Employee e2{"Dave", 42};
}
