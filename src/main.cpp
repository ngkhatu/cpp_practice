#include <iostream>
#include <vector>

int main() {
  std::vector<bool> v{true, false, false, true, true};

  for (int i : v)
    std::cout << i << ' ';
  std::cout << '\n';

  // Change the Boolean value with index 4 to false
  v[4] = false;

  for (int i : v)
    std::cout << i << ' ';
  std::cout << '\n';

  return 0;
}
