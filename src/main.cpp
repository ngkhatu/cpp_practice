#include <iostream>
#include <limits>

int main() {

  std::cout << std::numeric_limits<int>::max() << std::endl;      // 231 − 1
  std::cout << std::numeric_limits<uint16_t>::max() << std::endl; // 65, 535
  std::cout << std::numeric_limits<int>::min() << std::endl;      // −231
  std::cout << std::numeric_limits<unsigned>::min() << std::endl; // 0

  return 0;
}
