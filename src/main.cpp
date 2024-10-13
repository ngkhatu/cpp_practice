#include <iostream>
#include <string>
#include <string_view>

// Learncpp.com: section 14.8- Benefits of Data Hiding (encapsulation)

// data hiding (also called information hiding or data abstraction) is a
// technique used to enforce the separation of interface and implementation by
// hiding (making inaccessible) the implementation of a program-defined data
// type from users.

// * Data hiding make classes easier to use, and reduces complexity

// * Data hiding allows us to maintain invariants (conditions that must be true
// throughout the lifetime of an object in order for the object to stay in a
// valid state)

struct sEmployee // members are public by default
{
  std::string name{"John"};

  // Our Employee struct has a class invariant that firstInitial should always
  // equal the first character of name. If this is ever untrue, then the print()
  // function will malfunction
  char firstInitial{'J'}; // should match first initial of name

  void print() const {
    std::cout << "Employee " << name << " has first initial " << firstInitial
              << '\n';
  }
};

// Let’s rewrite this program, making our member variables private, and exposing
// a member function to set the name of an Employee

class Employee // members are private by default
{
  std::string m_name{};
  char m_firstInitial{};

public:
  void setName(std::string_view name) {
    m_name = name;
    m_firstInitial =
        name.front(); // use std::string::front() to get first letter of `name`
  }

  void print() const {
    std::cout << "Employee " << m_name << " has first initial "
              << m_firstInitial << '\n';
  }
};

int main() {
  sEmployee e{}; // defaults to "John" and 'J'
  e.print();

  e.name = "Mark"; // change employee's name to "Mark"
  e.print();       // prints wrong initial

  Employee new_e{};
  new_e.setName("John");
  new_e.print();

  new_e.setName("Mark");
  new_e.print();

  return 0;
}

// * Data hiding allows us to do better error detection (and handling)
// * Data hiding makes it possible to change implementation details without
// breaking existing programs
// * Classes with interfaces are easier to debug

// BEST PRACTICE: Prefer implementing functions as non-members when possible
// (especially functions that contain application specific data or logic).
// EXAMPLE:
/*
class Yogurt {
  std::string m_flavor{"vanilla"};

public:
  void setFlavor(std::string_view flavor) { m_flavor = flavor; }

  const std::string &getFlavor() const { return m_flavor; }
};

// Best: non-member function print() is not part of the class interface
void print(const Yogurt &y) {
  std::cout << "The yogurt has flavor " << y.getFlavor() << '\n';
}

int main() {
  Yogurt y{};
  y.setFlavor("cherry");
  print(y);

  return 0;
}
 */

/*
When writing code outside of a class, we are required to declare variables and
functions before we can use them. However, inside a class, this limitation does
not exist. As noted in lesson 14.3 -- Member functions, we can order our members
in any order we like.

So how should we order them?

There are two schools of thought here:

* List your private members first, and then list your public member functions.
This follows the traditional style of declare-before-use. Anybody looking at
your class code will see how you’ve defined your data members before they are
used, which can make reading through and understanding implementation details
easier.
* List your public members first, and put your private members down at the
bottom. Because someone who uses your class is interested in the public
interface, putting your public members first makes the information they need up
top, and puts the implementation details (which are least important) last.

In modern C++, the second method (public members go first) is more commonly
recommended, especially for code that will be shared with other developers.*/

// BEST PRACTICE- Declare public members first, protected members next, and
// private members last. This spotlights the public interface and de-emphasizes
// implementation details.
