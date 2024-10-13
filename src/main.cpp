#include <iostream>

// Learncpp.com: section 14.4- Const class objects and const member functions

/* //const int x;    // compile error: not initialized
const int y{};  // ok: value initialized
const int z{5}; // ok: list initialized
// Similarly, class type objects (struct, classes, and unions) can also be made
// const by using the const keyword. Such objects must also be initialized at
// the time of creation. */

/* struct Date {
  int year{};
  int month{};
  int day{};
  void incrementDay() { ++day; }
  // void print() { std::cout << year << '/' << month << '/' << day; }

  // now a const member function
  void print() const { std::cout << year << '/' << month << '/' << day; }
};

int main() {
  const Date today{2020, 10, 14}; // const class type object
  // today.day += 1; // compile error: can't modify member of const object
  //  today.incrementDay(); // compile error: can't call member function that
  //   modifies member of const object
  Date tomorrow{2020, 10, 15};

  // today.print(); // compile error: can't call non-const member function
  today.print(); // calling const member function, since today is const

  // const member functions can be called on both const and non-const objects,
  // if a member function does not modify the state of the object, it should be
  // made const
  tomorrow.print();

  return 0;
}
 */

struct Date {
  int year{};
  int month{};
  int day{};
  // it is possible to overload a member function to have a const and non-const
  // version of the same function. This works because the const qualifier is
  // considered part of the function’s signature, so two functions which differ
  // only in their const-ness are considered distinct

  void print() const // const
  {
    std::cout << year << '/' << month << '/' << day;
  }
  void print() // non-const
  {
    std::cout << year << '/' << month << '/' << day;
  }
};

// Since we can’t call non-const member functions on const objects, this will
// cause a compile error.
void doSomething(const Date &date) { date.print(); }

int main() {
  Date today{2020, 10, 14}; // non-const
  today.print();

  doSomething(today);

  return 0;
}
