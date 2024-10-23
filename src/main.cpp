// 16.2- Introduction to containers and arrays

#include <iostream>
#include <vector>

int main() {
  // Value initialization (uses default constructor)
  std::vector<int> empty{}; // vector containing 0 int elements
  std::vector<int> data(
      10); // vector containing 10 int elements, value-initialized to 0
  // List construction (uses list constructor)
  std::vector<int> primes{
      2, 3, 5, 7,
      11}; // vector containing 4 int elements with values 2, 3, 5, and 7
  std::vector vowels{'a', 'e', 'i', 'o',
                     'u'}; // vector containing 5 char elements with values 'a',
                           // 'e', 'i', 'o', and 'u'.  Uses CTAD (C++17) to
                           // deduce element type char (preferred).

  // Copy init
  // std::vector<int> v1 = 10; // 10 not an initializer list, copy init won't
  // match
  // explicit constructor: compilation error

  // Direct init
  std::vector<int> v2(10); // 10 not an initializer list, matches explicit
                           // single-argument constructor

  // List init
  std::vector<int> v3{
      10}; // { 10 } interpreted as initializer list, matches list constructor

  // Copy list init
  std::vector<int> v4 = {
      10}; // { 10 } interpreted as initializer list, matches list constructor
  std::vector<int> v5(
      {10}); // { 10 } interpreted as initializer list, matches list constructor

  for (int x = 0; x < 5; x++) {
    std::cout << primes[x] << std::endl;
    std::cout << vowels[x] << std::endl;
  }
  std::cout << "The first prime number is: " << primes[0] << '\n';
  std::cout << "The second prime number is: " << primes[1] << '\n';
  std::cout << "The sum of the first 5 primes is: "
            << primes[0] + primes[1] + primes[2] + primes[3] + primes[4]
            << '\n';
  std::cout << primes[10] << std::endl; // Index is out of bounds

  std::cout << "An int is " << sizeof(int) << " bytes\n";
  std::cout << &primes[0] << '\n';
  std::cout << &(primes[1]) << '\n';
  std::cout << &(primes[2]) << '\n';
  std::cout << &(primes[3]) << '\n';
  return 0;
}
