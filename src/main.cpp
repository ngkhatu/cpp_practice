// Learncpp.com: section 8.13 and 8.14- Introduction to Random Number Generation

// The randomization capabilities in C++ are accessible via the <random> header
// of the standard library. Within the random library, there are 6 PRNG families
// available for use (as of C++20):

// There is zero reason to use knuth_b, default_random_engine, or rand() (which
// is a random number generator provided for compatibility with C).

// The Mersenne Twister PRNG, besides having a great name, is probably the most
// popular PRNG across all programming languages. Although it is a bit old by
// today’s standards, it generally produces quality results and has decent
// performance. The random library has support for two Mersenne Twister types:

// mt19937 is a Mersenne Twister that generates 32-bit unsigned integers
// mt19937_64 is a Mersenne Twister that generates 64-bit unsigned integers

#include <iostream>
#include <random> // for std::mt19937

/* int main() {
  std::mt19937 mt{}; // Instantiate a 32-bit Mersenne Twister

  // Print a bunch of random numbers
  for (int count{1}; count <= 40; ++count) {
    std::cout << mt() << '\t'; // generate a random number

    // If we've printed 5 numbers, start a new row
    if (count % 5 == 0)
      std::cout << '\n';
  }

  return 0;
} */
// ######################################
/* // Uniform Distribution
int main() {
  std::mt19937 mt{};

  // Create a reusable random number generator that generates uniform numbers
  // between 1 and 6
  std::uniform_int_distribution die6{
      1, 6}; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

  // Print a bunch of random numbers
  for (int count{1}; count <= 40; ++count) {
    std::cout << die6(mt) << '\t'; // generate a roll of the die here

    // If we've printed 10 numbers, start a new row
    if (count % 10 == 0)
      std::cout << '\n';
  }

  return 0;
}
 */
// #########################################
/* //  Seeding with System Clocks
// std::chrono::high_resolution_clock is a popular choice instead of
// std::chrono::steady_clock. std::chrono::high_resolution_clock is the clock
// that uses the most granular unit of time, but it may use the system clock for
// the current time, which can be changed or rolled back by users.
// std::chrono::steady_clock may have a less granular tick time, but is the only
// clock with a guarantee that users cannot adjust it.

#include <chrono> // for std::chrono
#include <iostream>
#include <random> // for std::mt19937

int main() {
  // Seed our Mersenne Twister using steady_clock
  // std::mt19937 mt{static_cast<std::mt19937::result_type>(
  //     std::chrono::steady_clock::now().time_since_epoch().count())};
  std::mt19937 mt{static_cast<std::mt19937::result_type>(
      std::chrono::high_resolution_clock::now().time_since_epoch().count())};

  // Create a reusable random number generator that generates uniform numbers
  // between 1 and 6
  std::uniform_int_distribution die6{
      1, 6}; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

  // Print a bunch of random numbers
  for (int count{1}; count <= 40; ++count) {
    std::cout << die6(mt) << '\t'; // generate a roll of the die here

    // If we've printed 10 numbers, start a new row
    if (count % 10 == 0)
      std::cout << '\n';
  }

  return 0;
}

 */

// #################################################
/* //  Seed with a pseudo random number from the OS
// BEST PRACTICE is to seed PRNG with std::random_device
// BEST PRACTICE Only seed a given pseudo-random number generator once, and do
// not reseed it.
#include <iostream>
#include <random> // for std::mt19937 and std::random_device

int main() {
  std::mt19937 mt{std::random_device{}()};

  // Create a reusable random number generator that generates uniform numbers
  // between 1 and 6
  std::uniform_int_distribution die6{
      1, 6}; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

  // Print a bunch of random numbers
  for (int count{1}; count <= 40; ++count) {
    std::cout << die6(mt) << '\t'; // generate a roll of the die here

    // If we've printed 10 numbers, start a new row
    if (count % 10 == 0)
      std::cout << '\n';
  }

  return 0;
}

 */
// #######################################################

#include <iostream>
#include <random>
// This is pretty straightforward so there isn’t much reason not to do this at a
// minimum. The results from seeding a std::mt_19937 with 8 seed values instead
// of a single value should be much better.

int main() {
  std::random_device rd{};
  std::seed_seq ss{rd(), rd(), rd(), rd(), rd(),
                   rd(), rd(), rd()}; // get 8 integers of random numbers from
                                      // std::random_device for our seed
  std::mt19937 mt{ss}; // initialize our Mersenne Twister with the std::seed_seq

  // Create a reusable random number generator that generates uniform numbers
  // between 1 and 6
  std::uniform_int_distribution die6{
      1, 6}; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

  // Print a bunch of random numbers
  for (int count{1}; count <= 40; ++count) {
    std::cout << die6(mt) << '\t'; // generate a roll of the die here

    // If we've printed 10 numbers, start a new row
    if (count % 10 == 0)
      std::cout << '\n';
  }

  return 0;
}

// Warming up a PRNG
// When a PRNG is given a poor quality seed (or underseeded), the initial
// results of the PRNG may not be high quality. For this reason, some PRNGs
// benefit from being “warmed up”, which is a technique where the first N
// results generated from the PRNG are discarded. This allows the internal state
// of the PRNG to be mixed up such that the subsequent results should be of
// higher quality. Typically a few hundred to a few thousand initial results are
// discarded. The longer the period of the PRNG, the more initial results should
// be discarded.
