// Learncpp.com: section 8.15- Global Random Numbers (Random.h)

/*
What happens if we want to use a random number generator in multiple functions
or files? One way is to create (and seed) our PRNG in our main() function, and
then pass it everywhere we need it. But that’s a lot of passing for something we
may only use sporadically, and in many different places. It would add a lot of
clutter to our code to pass such an object around.

Alternately, you could create a static local std::mt19937 variable in each
function that needs it (static so that it only gets seeded once). However, it’s
overkill to have every function that uses a random number generator define and
seed its own local generator, and the low volume of calls to each generator may
lead to lower quality results.

What we really want is a single PRNG object that we can share and access
anywhere, across all of our functions and files. The best option here is to
create a global random number generator object (inside a namespace!). Remember
how we told you to avoid non-const global variables? This is an exception
*/

#include "Random.h" // defines Random::mt, Random::get(), and Random::generate()
#include <cstddef>  // for std::size_t
#include <iostream>

int main() {
  // We can use Random::get() to generate random numbers

  std::cout << Random::get(1, 6) << '\n'; // returns int between 1 and 6
  std::cout << Random::get(1u, 6u)
            << '\n'; // returns unsigned int between 1 and 6

  // The following uses a template type argument
  // See https://www.learncpp.com/cpp-tutorial/function-template-instantiation/
  std::cout << Random::get<std::size_t>(1, 6u)
            << '\n'; // returns std::size_t between 1 and 6

  // We can access Random::mt directly if we have our own distribution

  // Let's create a reusable random number generator that generates uniform
  // numbers between 1 and 6
  std::uniform_int_distribution die6{
      1, 6}; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };
  for (int count{1}; count <= 10; ++count) {
    std::cout << die6(Random::mt) << '\t'; // generate a roll of the die here
  }

  std::cout << '\n';

  return 0;
}
