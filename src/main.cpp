/* #include <iostream>

class Something {
private:
  static int s_value; // declares the static member variable

public:
  void static print_val() { std::cout << Something::s_value << std::endl; }
};

int Something::s_value{
    4}; // defines the static member variable (we'll discuss this section below)

int main() {

  Something::print_val();

  return 0;
}
 */

// #########################
/*
#include <iostream>

class Something
{
private:
    static inline int s_idGenerator { 1 };
    int m_id {};

public:
    // grab the next value from the id generator
    Something() : m_id { s_idGenerator++ }
    {
    }

    int getID() const { return m_id; }
};

int main()
{
    Something first{};
    Something second{};
    Something third{};

    std::cout << first.getID() << '\n';
    std::cout << second.getID() << '\n';
    std::cout << third.getID() << '\n';
    return 0;
} */

// ###############################################

#include <utility> // for std::pair<T, U>

class Foo {
private:
  auto m_x{5};           // auto not allowed for non-static members
  std::pair m_v{1, 2.3}; // CTAD not allowed for non-static members

  static inline auto s_x{5};           // auto allowed for static members
  static inline std::pair s_v{1, 2.3}; // CTAD allowed for static members

public:
  Foo() {};
};

int main() {
  Foo foo{};

  return 0;
}
