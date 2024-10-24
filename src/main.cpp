// Learncpp.com: Section 16.4- Passing std::vector
#include <iostream>
#include <vector>

/* template <typename T> void passByRef(const std::vector<T> &arr) {
  std::cout << arr[0] << '\n';
} */

void passByRef(const auto &arr) { std::cout << arr[0] << '\n'; }

/*
void passByRef(const std::vector<int> &arr) { std::cout << arr[0] << '\n'; }

void passByRef(
    const std::vector<double>
        &arr) // compile error: CTAD can't be used to infer function parameters
{
  std::cout << arr[0] << '\n';
}
 */
/* void passByRef(const std::vector &arr) // compile error: CTAD can't be used
to
                                       // infer function parameters
{
  std::cout << arr[0] << '\n';
} */

template <typename T> void printElement3(const std::vector<T> &arr) {
  std::cout << arr[3] << '\n';
  // std::cout << arr.at(3) << '\n';
}

int main() {
  std::vector primes{2, 3, 5, 7, 11};
  passByRef(primes); // ok: this is a std::vector<int>

  std::vector dbl{1.1, 2.2, 3.3};
  passByRef(dbl); // compile error: std::vector<double> is not convertible to
                  //  std::vector<int>

  std::vector arr{9, 7}; // a 2-element array (valid indexes 0 and 1)
  printElement3(arr);

  return 0;
}
