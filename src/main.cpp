#include <iostream>

// Learncpp.com: section 14.5- Public and private members and access specifiers

// - Access Level: Each member of a class type has a property called an access
// level that determines who can access that member.
// * Three levels- Public, Private, Protected

// - Public Members- Members of a class type that do not have any restrictions
// on how they can be accessed
// * Can be accessed by other members of the same class
// * Can be accessed by code that exists outside the members of a given class
// type
// * By default, all members of a struct(and union) are public members.
// struct Date{int day{};}; int main{Date today{14}; today.day=16;}
// Because main() is not a member of Date, it is considered to be part of the
// public

// - Private Members- Members that have private access level.\
// * Members of a class type that can only be accessed by other members of the same class
// * Members of a class are private by default

#include <iostream>

class Date // now a class instead of a struct
{

private: // private access specifier
  // class members are private by default, can only be accessed by other members
  // private members given "_m" prefix
  int m_year{2020}; // private by default
  int m_month{14};  // private by default
  int m_day{10};    // private by default

public:              // public access specifier
  void print() const // private by default
  {
    // private members can be accessed in member functions
    std::cout << m_year << '/' << m_month << '/' << m_day;
  }
};

int main() {
  // Date today{2020, 10, 14}; // compile error: can no longer use aggregate
  // initialization

  // private members can not be accessed by the public
  // today.m_day = 16; // compile error: the m_day member is private
  // today.print(); // compile error: the print() member function is private

  // Because we have private members, we can not aggregate initialize d. For
  // this example, we’re using default member initialization instead (as a
  // temporary workaround)
  Date d{};
  d.print();

  return 0;
}

// BEST PRACTICES
// * Structs should avoid access specifiers altogether, meaning all struct
// members will be public by default
// * Classes should generally only have private (or protected) data members
// (either by using the default private access level, or the private: (or
// protected:) access specifier)
// * Classes normally have public member functions (so those member functions
// can be used by the public after the object is created). However, occasionally
// member functions are made private (or protected) if they are not intended to
// be used by the public.

/*
Structs vs Classes
---------------------
* A class defaults its members to private, whereas a struct defaults its members
to public.

In practice, we use structs and classes differently.
-----------------
As a rule of thumb, use a struct when all of the following are true:

* You have a simple collection of data that doesn’t benefit from restricting
access.
* Aggregate initialization is sufficient.
* You have no class invariants,setup needs, or cleanup needs. A few examples of
where structs might be used: constexpr global program data, a point struct (a
simple collection of int members that don’t benefit from being made private),
structs used to return a set of data from a function.
---------------
Use a class otherwise.

We want our structs to be aggregates. So if you use any capabilities that makes
your struct a non-aggregate, you should probably be using a class instead (and
following all of the best practices for classes).

*/
