// Learncpp.com: section 11.7- Function Template instantiation

#include <iostream>

// a declaration for our function template (we don't need the definition any
// more)
template <typename T> T max(T x, T y);

template <>
int max<int>(int x, int y) // the generated function max<int>(int, int)
{
  return (x < y) ? y : x;
}

template <>
double
max<double>(double x,
            double y) // the generated function max<double>(double, double)
{
  return (x < y) ? y : x;
}

// Here's a function template with a static local variable that is modified
template <typename T> void printIDAndValue(T value) {
  static int id{0};
  std::cout << ++id << ") " << value << '\n';
}

int main() {
  std::cout << max<int>(1, 2)
            << '\n'; // instantiates and calls function max<int>(int, int)
  std::cout << max<int>(4, 3)
            << '\n'; // calls already instantiated function max<int>(int, int)
  std::cout
      << max<double>(1, 2)
      << '\n'; // instantiates and calls function max<double>(double, double)
  std::cout << max<int>(1, 2) << '\n'; // specifying we want to call max<int>
  std::cout << max<>(1, 2) << '\n';
  std::cout << max(1, 2) << '\n';

  printIDAndValue(12);
  printIDAndValue(13);

  // static ID value is reinstantiated for double types
  printIDAndValue(14.5);

  return 0;
}
