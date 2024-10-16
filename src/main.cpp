// Learncpp.com: section 13.5- Introduction to Overloading the I/O Operator

// Introduction to Operator Overloading

/*
Basic operator overloading is fairly straightforward:

Define a function using the name of the operator as the function’s name.
Add a parameter of the appropriate type for each operand (in left-to-right
order). One of these parameters must be a user-defined type (a class type or an
enumerated type), otherwise the compiler will error. Set the return type to
whatever type makes sense. Use a return statement to return the result of the
operation.
*/

//  implement an overload of operator<< to print a Color
/*
#include <iostream>
#include <string_view>

// A std::ostream object already knows how to print a std::string_view using
// operator<< (this comes as part of the standard library)
enum Color {
  black,
  red,
  blue,
};

constexpr std::string_view getColorName(Color color) {
  switch (color) {
  case black:
    return "black";
  case red:
    return "red";
  case blue:
    return "blue";
  default:
    return "???";
  }
}

// Teach operator<< how to print a Color
// std::ostream is the type of std::cout, std::cerr, etc...
// The return type and parameter type are references (to prevent copies from
// being made)

// A std::ostream object already knows how to print a std::string_view using
// operator<< (this comes as part of the standard library)
std::ostream &operator<<(std::ostream &out, Color color) {
  out << getColorName(
      color); // print our color's name to whatever output stream out
  return out; // operator<< conventionally returns its left operand

  // The above can be condensed to the following single line:
  // return out << getColorName(color)
}

int main() {
  Color shirt{blue};
  std::cout << "Your shirt is " << shirt << '\n'; // it works!

  return 0;
}
 */

// A std::ostream object already knows how to print a std::string_view using
// operator<< (this comes as part of the standard library)

#include <iostream>
#include <limits>
#include <optional>
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

// pet is an in/out parameter
std::istream &operator>>(std::istream &in, Pet &pet) {
  std::string s{};
  in >> s; // get input string from user

  std::optional<Pet> match{getPetFromString(s)};
  if (match) // if we found a match
  {
    pet = *match; // dereference std::optional to get matching enumerator
    return in;
  }

  // We didn't find a match, so input must have been invalid
  // so we will set input stream to fail state
  in.setstate(std::ios_base::failbit);

  // On an extraction failure, operator>> zero-initializes fundamental types
  // Uncomment the following line to make this operator do the same thing
  // pet = {};

  return in;
}

int main() {
  std::cout << "Enter a pet: cat, dog, pig, or whale: ";
  Pet pet{};
  std::cin >> pet;

  if (std::cin) // if we found a match
    std::cout << "You chose: " << getPetName(pet) << '\n';
  else {
    std::cin.clear(); // reset the input stream to good
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Your pet was not valid\n";
  }

  return 0;
}
