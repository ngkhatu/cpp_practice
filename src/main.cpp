/* #include <iostream>
#include <string>
#include <string_view>

class Employee {
private:
  std::string m_name{};

public:
  Employee(std::string_view name) : m_name{name} {}
  const std::string &getName() const {
    return m_name;
  } //  getter returns by const reference
};

// createEmployee() returns an Employee by value (which means the returned value
// is an rvalue)
Employee createEmployee(std::string_view name) {
  Employee e{name};
  return e;
}

int main() {
  // Case 1: okay: use returned reference to member of rvalue class object in
  // same expression
  std::cout << createEmployee("Frank").getName() << '\n';

  // Case 2: bad: save returned reference to member of rvalue class object for
  // use later
  const std::string &ref{
      createEmployee("Garbo")
          .getName()};      // reference becomes dangling when return value of
                            // createEmployee() is destroyed
  std::cout << ref << '\n'; // undefined behavior

  return 0;
}
 */
// ##############################################################
#include <iostream>
#include <string>
#include <string_view>

class Employee {
private:
  std::string m_name{};

public:
  Employee(std::string_view name) : m_name{name} {}

  const std::string &getName() const & {
    return m_name;
  } //  & qualifier overloads function to match only lvalue implicit objects
  std::string getName() const && {
    return m_name;
  } // && qualifier overloads function to match only rvalue implicit objects
};

// createEmployee() returns an Employee by value (which means the returned value
// is an rvalue)
Employee createEmployee(std::string_view name) {
  Employee e{name};
  return e;
}

int main() {
  Employee joe{"Joe"};
  std::cout << joe.getName()
            << '\n'; // Joe is an lvalue, so this calls std::string& getName() &
                     // (returns a reference)

  std::cout << createEmployee("Frank").getName()
            << '\n'; // Frank is an rvalue, so this calls std::string getName()
                     // && (makes a copy)

  return 0;
}
