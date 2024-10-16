// Learncpp.com: section 13.6- Scoped Enumerations (enum classes)

// Scoped enumerations work similarly to unscoped enumerations (13.2 -- Unscoped
// enumerations), but have two primary differences:
// 1) They won’t implicitly convert to integers,
// 2) and the enumerators are only placed into the scope
// region of the enumeration (not into the scope region where the enumeration is
// defined).

// To make a scoped enumeration, we use the keywords enum class. The rest of the
// scoped enumeration definition is the same as an unscoped enumeration
// definition. To make a scoped enumeration, we use the keywords enum class. The
// rest of the scoped enumeration definition is the same as an unscoped
// enumeration definition.

// * Unlike unscoped enumerations, which place their enumerators in the same
// scope as the enumeration itself, scoped enumerations place their enumerators
// only in the scope region of the enumeration. In other words, scoped
// enumerations act like a namespace for their enumerators. This built-in
// namespacing helps reduce global namespace pollution and the potential for
// name conflicts when scoped enumerations are used in the global scope.

// * Because scoped enumerations offer their own implicit namespacing for
// enumerators, there’s no need to put scoped enumerations inside another scope
// region (such as a namespace), unless there’s some other compelling reason to
// do so, as it would be redundant

// * Unlike non-scoped enumerators, scoped enumerators won’t implicitly convert
// to integers. In most cases, this is a good thing because it rarely makes
// sense to do so, and it helps prevent semantic errors, such as comparing
// enumerators from different enumerations, or expressions such as red + 5

// BEST PRACTICE- Favor scoped enumerations over unscoped enumerations unless
// there’s a compelling reason to do otherwise.
/* #include <iostream>
int main() {
  enum class Color // "enum class" defines this as a scoped enumeration rather
                   // than an unscoped enumeration
  {
    red, // red is considered part of Color's scope region
    blue,
  };

  enum class Fruit {
    banana, // banana is considered part of Fruit's scope region
    apple,
  };

  // Color color{Color::red}; // note: red is not directly accessible, we have
  // to
  //  use Color::red
  Fruit fruit{Fruit::banana}; // note: banana is not directly accessible, we
                              // have to use Fruit::banana

   if (color == fruit) // compile error: the compiler doesn't know how to
  compare
                      // different types Color and Fruit
    std::cout << "color and fruit are equal\n";
  else
    std::cout << "color and fruit are not equal\n";


  // std::cout << red
  //           << '\n'; // compile error: red not defined in this scope region
  // std::cout << Color::red
  //           << '\n'; // compile error: std::cout doesn't know how to print
  //           this
  //  (will not implicitly convert to int)

  Color color{Color::blue}; // okay

  return 0;
} */

// #######################################################
// Scoped enums don't implictly convert to integers

/* #include <iostream>
int main() {
  enum class Color {
    red,
    blue,
  };

  Color shirt{Color::red};

  if (shirt == Color::red) // this Color to Color comparison is okay
    std::cout << "The shirt is red!\n";
  else if (shirt == Color::blue)
    std::cout << "The shirt is blue!\n";

  return 0;
}
 */

/*  #include <iostream>
#include <utility> // for std::to_underlying() (C++23)

int main()
{
    enum class Color
    {
        red,
        blue,
    };

    Color color { Color::blue };

    std::cout << color << '\n'; // won't work, because there's no implicit
conversion to int std::cout << static_cast<int>(color) << '\n';   // explicit
conversion to int, will print 1 std::cout << std::to_underlying(color) << '\n';
// convert to underlying type, will print 1 (C++23)

    return 0;
} */

/*
#include <iostream>

int main()
{
    enum class Pet
    {
        cat, // assigned 0
        dog, // assigned 1
        pig, // assigned 2
        whale, // assigned 3
    };

    std::cout << "Enter a pet (0=cat, 1=dog, 2=pig, 3=whale): ";

    int input{};
    std::cin >> input; // input an integer

    Pet pet{ static_cast<Pet>(input) }; // static_cast our integer to a Pet

    return 0;
}
*/

/*
// using enum class Pet from prior example
Pet pet { 1 }; // okay
*/

// Scoped enumerations are great, but the lack of implicit conversion to
// integers can sometimes be a pain point. If we need to convert a scoped
// enumeration to integers often (e.g. cases where we want to use scoped
// enumerators as array indices), having to use static_cast every time we want a
// conversion can clutter our code significantly.

// If you find yourself in the situation where it would be useful to make
// conversion of scoped enumerators to integers easier, a useful hack is to
// overload the unary operator+ to perform this conversion:
/* #include <iostream>
#include <type_traits> // for std::underlying_type_t

enum class Animals
{
    chicken, // 0
    dog, // 1
    cat, // 2
    elephant, // 3
    duck, // 4
    snake, // 5

    maxAnimals,
};

// Overload the unary + operator to convert Animals to the underlying type
// adapted from https://stackoverflow.com/a/42198760, thanks to Pixelchemist for
the idea
// In C++23, you can #include <utility> and return std::to_underlying(a) instead
constexpr auto operator+(Animals a) noexcept
{
    return static_cast<std::underlying_type_t<Animals>>(a);
}

int main()
{
    std::cout << +Animals::elephant << '\n'; // convert Animals::elephant to an
integer using unary operator+

    return 0;
}

 */
// ######################################################

// Introduced in C++20, a using enum statement imports all of the enumerators
// from an enum into the current scope. When used with an enum class type, this
// allows us to access the enum class enumerators without having to prefix each
// with the name of the enum class.
/*
#include <iostream>
#include <string_view>

enum class Color {
  black,
  red,
  blue,
};

constexpr std::string_view getColor(Color color) {
  using enum Color; // bring all Color enumerators into current scope (C++20)
  // We can now access the enumerators of Color without using a Color:: prefix

  switch (color) {
  case black:
    return "black"; // note: black instead of Color::black
  case red:
    return "red";
  case blue:
    return "blue";
  default:
    return "???";
  }
}

int main() {
  Color shirt{Color::blue};

  std::cout << "Your shirt is " << getColor(shirt) << '\n';

  return 0;
}
 */
// Useful Here...

#include <iostream>
#include <string_view>

enum class Color {
  black,
  red,
  blue,
};

constexpr std::string_view getColor(Color color) {
  using enum Color; // bring all Color enumerators into current scope (C++20)
  // We can now access the enumerators of Color without using a Color:: prefix

  switch (color) {
  case black:
    return "black"; // note: black instead of Color::black
  case red:
    return "red";
  case blue:
    return "blue";
  default:
    return "???";
  }
}

int main() {
  Color shirt{Color::blue};

  std::cout << "Your shirt is " << getColor(shirt) << '\n';

  return 0;
}
