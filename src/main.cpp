// Learncpp.com Section 16.3- std::vector and the unsigned lenght and subscript
// problem

#include <iostream>
#include <vector>

int main() {
  std::vector prime{2, 3, 5, 7, 11};

  // ------------- prime.size() vs std::size(prime)-------------
  std::cout
      << "length: " << prime.size()
      << '\n'; // returns length as type `size_type` (alias for `std::size_t`)
  std::cout << "length: "
            << std::size(prime); // C++17, returns length as type `size_type`
                                 // (alias for `std::size_t`)

  int lengthint{static_cast<int>(prime.size())}; // static_cast return value to
                                                 // int
  unsigned long int length{prime.size()}; // static_cast return value to int
  std::cout << "length: " << length;
  std::cout << "length: " << lengthint;

  // -------------- ssize()-----------------------------------
  std::cout
      << "length: "
      << std::ssize(
             prime); // C++20, returns length as a large signed integral type

  int lengt{
      static_cast<int>(std::ssize(prime))}; // static_cast return value to int
  std::cout << "length: " << lengt;

  // use cast because the int type may be smaller than the signed type returned
  // by std::ssize()
  long int leng{(std::ssize(prime))}; // static_cast return value to int
  std::cout << "length: " << leng;

  //----------------------- auto----------------------------------
  auto len_a{std::ssize(
      prime)}; // use auto to deduce signed type, as returned by std::ssize()
  std::cout << "length_len_a: " << len_a;

  std::cout << prime.at(3)
            << std::endl; // print the value of element with index 3
  // std::cout << prime.at(9); // invalid index (throws exception)

  // ---------------------------
  std::cout << prime[3] << '\n'; // okay: 3 converted from int to std::size_t,
                                 // not a narrowing conversion

  constexpr int index{3}; // constexpr
  std::cout << prime[index]
            << '\n'; // okay: constexpr index implicitly converted to
                     // std::size_t, not a narrowing conversion

  std::size_t ind{3};              // non-constexpr
  std::cout << prime[ind] << '\n'; // operator[] expects an index of type
                                   // std::size_t, no conversion required
  // ----------------- index the data() member function------------------
  // --------------returns pointer to first element in array ------------------
  int indx{3}; // non-constexpr
  std::cout << prime[indx]
            << '\n'; // possible warning: index implicitly converted to
                     // std::size_t, narrowing conversion

  std::cout << prime.data()[indx] << '\n'; // okay: no sign conversion warnings
  // ---------------------------------------------
  // Correct way- use std::size_t
  for (std::size_t i = 0; i < 4; i++) {

    std::cout << prime[i] << std::endl;
  }

  return 0;
}
