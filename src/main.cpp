// Learncpp.com: section 13.12- Member selection with pointers and references

#include <iostream>
/*
// BEST PRACTICE- When using a pointer to access a member, use the member
// selection from pointer operator (->) instead of the member selection operator
// (.).

struct Employee {
  int id{};
  int age{};
  double wage{};
};

int main() {
  Employee joe{1, 34, 65000.0};

  ++joe.age;
  joe.wage = 68000.0;

  Employee *ptr{&joe};
  // std::cout << ptr.id << '\n'; // Compile error: can't use operator. with
  // pointers

  std::cout << (*ptr).id << '\n'; // Not great but works: First dereference ptr,
                                  // then use member selection
  // member selection from pointer operator (->) (also sometimes called the
  // arrow operator) that can be used to select members from a pointer to an
  // object
  std::cout << ptr->id
            << '\n'; // Better: use -> to select member from pointer to object

  return 0;
}
 */

struct Point {
  double x{};
  double y{};
};

struct Triangle {
  Point *a{};
  Point *b{};
  Point *c{};
};

int main() {
  Point a{1, 2};
  Point b{3, 7};
  Point c{10, 2};

  Triangle tr{&a, &b, &c};
  Triangle *ptr{&tr};

  // ptr is a pointer to a Triangle, which contains members that are pointers to
  // a Point To access member y of Point c of the Triangle pointed to by ptr,
  // the following are equivalent:

  // access via operator.
  std::cout << (*(*ptr).c).y << '\n'; // ugly!

  // access via operator->
  std::cout << ptr->c->y << '\n'; // much nicer
}
