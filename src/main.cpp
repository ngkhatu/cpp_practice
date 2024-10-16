// Learncpp.com: section 15.4- Introduction to destructors

// Destructors are designed to allow a class to do any necessary clean up before
// an object of the class is destroyed.

/*
Like constructors, destructors have specific naming rules:

1) The destructor must have the same name as the class, preceded by a tilde (~).
2) The destructor can not take arguments.
3) The destructor has no return type.
A class can only have a single destructor.

Generally you should not call a destructor explicitly (as it will be called
automatically when the object is destroyed), since there are rarely cases where
you’d want to clean up an object more than once.
*/

#include <iostream>

class Simple {
private:
  int m_id{};

public:
  Simple(int id) : m_id{id} {
    std::cout << "Constructing Simple " << m_id << '\n';
  }

  ~Simple() // here's our destructor
  {
    std::cout << "Destructing Simple " << m_id << '\n';
  }

  int getID() const { return m_id; }
};

int main() {
  // Allocate a Simple
  Simple simple1{1};
  { Simple simple2{2}; } // simple2 dies here

  Simple Pimple{3};

  return 0;
} // simple1 dies here

// #################################################
//  Implicit Destructor- If a non-aggregate class type object has no
//  user-declared destructor, the compiler will generate a destructor with an
//  empty body. This destructor is called an implicit destructor, and it is
//  effectively just a placeholder.

// If your class does not need to do any cleanup on destruction, it’s fine to
// not define a destructor at all, and let the compiler generate an implicit
// destructor for your class.

// we discussed the std::exit() function, can be used to terminate your program
// immediately. When the program is terminated immediately, the program just
// ends. Local variables are not destroyed first, and because of this, no
// destructors will be called. Be wary if you’re relying on your destructors to
// do necessary cleanup work in such a case.
