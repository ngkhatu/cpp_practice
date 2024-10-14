#include "Date.h"
#include <iostream>

// Member functions can be defined outside the class definition just like
// non-member functions. The only difference is that we must prefix the member
// function names with the name of the class type (in this case, Date::) so the
// compiler knows we’re defining a member of that class type rather than a
// non-member.

Date::Date(int year, int month, int day) // constructor definition
    : m_year{year}, m_month{month}, m_day{day} {}

void Date::print() const // print function definition
{
  std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n";
};
