// Learncpp.com: section 15.1- hidden “this” pointer and member function
// chaining

/*
We use -> to select a member from a pointer to an object. this->m_id is the
equivalent of (*this).m_id.
*/

// Inside every member function, the keyword this is a const pointer that holds
// the address of the current implicit object.

// For non-const member functions
// this is a const pointer to a non-const value
// (meaning this cannot be pointed at something else, but the object pointing to
// may be modified).

// With const member functions
// this is a const pointer to a const value (meaning the pointer cannot be
// pointed at something else, nor may the object being pointed to be modified).

#include <iostream>
/*
class Simple {
private:
  int m_id{};

public:
  Simple(int id) : m_id{id} {}

  int getID() const { return this->m_id; }
  void setID(int id) { this->m_id = id; }

  void print() const {
    std::cout << this->m_id;
  } // use `this` pointer to access the implicit object and operator-> to select
    // member m_id
};

int main() {
  Simple simple{1};
  simple.setID(2);

  simple.print();

  return 0;
}
 */
/*
void print() const { std::cout << m_id; }       // implicit use of this
void print() const { std::cout << this->m_id; } // explicit use of this

How the compiler rewrites functions is an implementation-specific detail, but
the end-result is something like this:
*/
// static void setID(Simple* const this, int id) { this->m_id = id; }

/*
int main()
{
    Simple a{1}; // this = &a inside the Simple constructor
    Simple b{2}; // this = &b inside the Simple constructor
    a.setID(3); // this = &a inside member function setID()
    b.setID(4); // this = &b inside member function setID()

    return 0;
}
*/

// #################################
/* //  Example of where 'this' can be useful
struct Something {
  int data{}; // not using m_ prefix because this is a struct

  void setData(int data) {
    this->data = data; // this->data is the member, data is the local parameter
  }
};
 */
// ########################################
// Function chaining/ Method chaining
// it can sometimes be useful to have a member function return the implicit
// object as a return value. The primary reason to do this is to allow member
// functions to be “chained” together, so several member functions can be called
// on the same object in a single expression! This is called function chaining
// (or method chaining).

class Calc {
private:
  int m_value{};

public:
  Calc &add(int value) {
    m_value += value;
    return *this;
  }
  Calc &sub(int value) {
    m_value -= value;
    return *this;
  }
  Calc &mult(int value) {
    m_value *= value;
    return *this;
  }

  int getValue() const { return m_value; }

  // The best way to reset a class back to a default state is to create a
  // reset() member function, have that function create a new object (using the
  // default constructor), and then assign that new object to the current
  // implicit object, like this:
  void reset() { *this = {}; }
};

int main() {
  Calc calc{};
  calc.add(5).sub(3).mult(4);

  std::cout << calc.getValue() << '\n'; // prints 8

  calc.reset();

  std::cout << calc.getValue() << '\n'; // prints 0

  return 0;
}
