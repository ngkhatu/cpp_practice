// Learncpp.com: Section 15.9- Friend classes and friend member functions

/* #include <iostream>

class Storage {
private:
  int m_nValue{};
  double m_dValue{};

public:
  Storage(int nValue, double dValue) : m_nValue{nValue}, m_dValue{dValue} {}

  // Make the Display class a friend of Storage
  friend class Display;
};

class Display {
private:
  bool m_displayIntFirst{};

public:
  Display(bool displayIntFirst) : m_displayIntFirst{displayIntFirst} {}

  // Because Display is a friend of Storage, Display members can access the
  // private members of Storage
  void displayStorage(const Storage &storage) {
    if (m_displayIntFirst)
      std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
    else // display double first
      std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
  }

  void setDisplayIntFirst(bool b) { m_displayIntFirst = b; }
};

int main() {
  Storage storage{5, 6.7};
  Display display{false};

  display.displayStorage(storage);

  display.setDisplayIntFirst(true);
  display.displayStorage(storage);

  return 0;
}
 */

// #################################################################

#include <iostream>
class Storage;

class Display {
private:
  bool m_displayIntFirst{};

public:
  Display(bool displayIntFirst) : m_displayIntFirst{displayIntFirst} {}

  void displayStorage(const Storage &storage);
};

class Storage {
private:
  int m_nValue{};
  double m_dValue{};

public:
  Storage(int nValue, double dValue) : m_nValue{nValue}, m_dValue{dValue} {}

  // Make the Display::displayStorage member function a friend of the Storage
  // class
  friend void Display::displayStorage(
      const Storage &storage); // error: Storage hasn't seen the full definition
                               // of class Display
};

void Display::displayStorage(const Storage &storage) {
  if (m_displayIntFirst)
    std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
  else // display double first
    std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
}

int main() {
  Storage storage{5, 6.7};
  Display display{false};
  display.displayStorage(storage);

  return 0;
}
