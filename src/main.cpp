/* #include <array>
#include <iostream>

int main() {
  std::array arr{9.0, 7.2, 5.4, 3.6, 1.8};
  std::cout
      << "length: " << arr.size()
      << '\n'; // returns length as type `size_type` (alias for `std::size_t`)

  std::cout << "length: "
            << std::size(arr); // C++17, returns length as type `size_type`
                               // (alias for `std::size_t`)

  std::cout
      << "length: "
      << std::ssize(
             arr); // C++20, returns length as a large signed integral type

  constexpr int length{
      std::size(arr)}; // ok: return value is constexpr std::size_t and can be
                       // converted to int, not a narrowing conversion
  std::cout << "length: " << length << '\n';

  return 0;
}
 */

// #############################################################

#include <__atomic/aliases.h>
#include <array>
#include <cstddef>
#include <iostream>

/* void printLength(const std::array<int, 5> &arr)
{
    constexpr int length{ std::size(arr) }; // compile error!
    std::cout << "length: " << length << '\n';
} */

// workaround
template <auto Length> void printLength(const std::array<int, Length> &arr) {
  // constexpr int length{std::size(arr)}; // compile error!
  std::cout << "length: " << Length << '\n';
}

int main() {
  constexpr std::array arr{9, 7, 5, 3, 1};
  constexpr int length{std::size(arr)}; // works just fine

  constexpr int val{arr[3]};

  std::cout << "length: " << length << '\n';

  printLength(arr);

  std::cout << std::get<3>(arr); // print the value of element with index 3
  std::cout << std::get<2>(arr); // invalid index (compile error)

  return 0;
}
