#include <array>
#include <iostream>
#include <string_view>

namespace Color {
enum Type {
  black,     // 0
  red,       // 1
  blue,      // 2
  max_colors // 3
};

using namespace std::string_view_literals; // for sv suffix
constexpr std::array colorName{"black"sv, "red"sv, "blue"sv};
static_assert(std::size(colorName) == max_colors);

constexpr std::array types{black, red,
                           blue}; // A std::array containing all our enumerators
static_assert(std::size(types) == max_colors);
}; // namespace Color

constexpr std::string_view getColorName(Color::Type color) {
  return Color::colorName[color];
}

// Teach operator<< how to print a Color
// std::ostream is the type of std::cout
// The return type and parameter type are references (to prevent copies from
// being made)!
std::ostream &operator<<(std::ostream &out, Color::Type color) {
  return out << getColorName(color);
}

int main() {
  for (auto c : Color::types) // ok: we can do a range-based for on a std::array
    std::cout << c << '\n';

  return 0;
}
