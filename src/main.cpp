#include <array>
#include <cstddef>
#include <iostream>

int main() {

  const int numStudents{6};

  constexpr std::array<int, numStudents> arr{0, 1, 2};
  constexpr std::array a1{9, 7, 5, 3,
                          1}; // The type is deduced to std::array<int, 5>
  constexpr std::array a2{9.7,
                          7.31}; // The type is deduced to std::array<double, 2>
  // constexpr std::array<int> a3{9, 7, 5, 3, 1}; // error: too few template
  // arguments (length missing)
  // constexpr std::array<5> a4{9, 7, 5, 3, 1}; // error: too few template
  // arguments (type missing)

  constexpr auto myArray1{
      std::to_array<int, 5>({9, 7, 5, 3, 1})}; // Specify type and size
  constexpr auto myArray2{
      std::to_array<int>({9, 7, 5, 3, 1})}; // Specify type only, deduce size
  constexpr auto myArray3{
      std::to_array({9, 7, 5, 3, 1})}; // Deduce type and size

  if (!arr.empty())
    std::cout << "NOT EMPTY!" << std::endl;
  for (auto i : arr) {
    std::cout << i << '\t';
  }
  std::cout << '\n';

  constexpr auto shortArray{std::to_array<short>({9, 7, 5, 3, 1})};
  std::cout << sizeof(shortArray[0]) << '\n';

  constexpr std::array<int, 5> prime{2, 3, 5, 7, 11};

  std::cout << prime[3]; // print the value of element with index 3 (7)
  std::cout << prime[9]; // invalid index (undefined behavior)

  return 0;
}
