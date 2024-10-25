#include <iostream>
#include <type_traits> // for std::underlying_type_t
#include <vector>

enum class StudentNames {
  kenny,       // 0
  kyle,        // 1
  stan,        // 2
  butters,     // 3
  cartman,     // 4
  max_students // 5
};

// Overload the unary + operator to convert StudentNames to the underlying type
constexpr auto operator+(StudentNames a) noexcept {
  return static_cast<std::underlying_type_t<StudentNames>>(a);
}

int main() {
  std::vector<int> testScores(+StudentNames::max_students);

  testScores[+StudentNames::stan] = 76;

  std::cout << "The class has " << +StudentNames::max_students << " students\n";

  return 0;
}
