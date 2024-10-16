// Learncpp.com: section 13.4- Converting an enumeration to and from a string

// Getting the name of an enumerator

// typical way to get the name of an enumerator is to write a function that
// allows us to pass in an enumerator and returns the enumerator’s name as a
// string. But that requires some way to determine which string should be
// returned for a given enumerator
// 1) use a switch statement
// 2) use an array
#include <iostream>
#include <optional> // for std::optional
#include <string>
#include <string_view>

enum Pet {
  cat,   // 0
  dog,   // 1
  pig,   // 2
  whale, // 3
};

constexpr std::string_view getPetName(Pet pet) {
  switch (pet) {
  case cat:
    return "cat";
  case dog:
    return "dog";
  case pig:
    return "pig";
  case whale:
    return "whale";
  default:
    return "???";
  }
}

constexpr std::optional<Pet> getPetFromString(std::string_view sv) {
  if (sv == "cat")
    return cat;
  if (sv == "dog")
    return dog;
  if (sv == "pig")
    return pig;
  if (sv == "whale")
    return whale;

  return {};
}

int main() {
  std::cout << "Enter a pet: cat, dog, pig, or whale: ";
  std::string s{};
  std::cin >> s;

  std::optional<Pet> pet{getPetFromString(s)};

  if (!pet)
    std::cout << "You entered an invalid pet\n";
  else
    std::cout << "You entered: " << getPetName(*pet) << '\n';

  return 0;
}
