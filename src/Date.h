#ifndef DATE_H
#define DATE_H

class Date {
private:
  int m_year{};
  int m_month{};
  int m_day{};

public:
  // Put any default arguments for member functions inside the class definition.
  Date(int year, int month, int day);

  void print() const;

  // access functions defined inside the class definition. Because access
  // functions are typically only one line, defining these functions inside the
  // class definition adds minimal clutter, whereas moving them outside the
  // class definition would result in many extra lines of code. For this reason,
  // the definitions of access functions (and other trivial, one-line functions)
  // are often left inside the class definition.
  int getYear() const { return m_year; }
  int getMonth() const { return m_month; }
  int getDay() const { return m_day; }
};

// member functions defined outside the class definition can be left in the
// header file if they are made inline (using the inline keyword)
/*
Functions defined inside the class definition are implicitly inline, which
allows them to be #included into multiple code files without violating the ODR.

Functions defined outside the class definition are not implicitly inline. They
can be made inline by using the inline keyword.
*/

/*
inline Date::Date(int year, int month, int day) // now inline
    : m_year{ year }
    , m_month{ month }
    , m_day{ day }
{
}

inline void Date::print() const // now inline
{
    std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n";
};
*/

#endif
