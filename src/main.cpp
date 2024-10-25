/* #include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Foo {
private:
  std::string m_a{};
  int m_b{};

public:
  Foo(std::string_view a, int b) : m_a{a}, m_b{b} {}

  explicit Foo(int b) : m_a{}, m_b{b} {};
};

int main() {
  std::vector<Foo> stack{};

  // When we already have an object, push_back and emplace_back are similar in
  // efficiency
  Foo f{"a", 2};
  stack.push_back(f); // prefer this one
  stack.emplace_back(f);

  // When we need to create a temporary object to push, emplace_back is more
  // efficient
  stack.push_back(
      {"a",
       2}); // creates a temporary object, and then copies it into the vector
  stack.emplace_back("a", 2); // forwards the arguments so the object can be
                              // created directly in the vector (no copy made)

  // push_back won't use explicit constructors, emplace_back will
  stack.push_back({2});  // compile error: Foo(int) is explicit
  stack.emplace_back(2); // ok

  return 0;
}
 */
// ################

#include <iostream>
#include <limits>
#include <vector>

int main() {
  std::vector<int> scoreList{};

  while (true) {
    std::cout << "Enter a score (or -1 to finish): ";
    int x{};
    std::cin >> x;

    if (!std::cin) // handle bad input
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    // If we're done, break out of loop
    if (x == -1)
      break;

    // The user entered a valid element, so let's push it on the vector
    scoreList.push_back(x);
  }

  std::cout << "Your list of scores: \n";

  for (const auto &score : scoreList)
    std::cout << score << ' ';

  return 0;
}
