#include <iostream>
#include <vector>

void printCapLen(const std::vector<int> &v) {
  std::cout << "Capacity: " << v.capacity() << " Length:" << v.size() << '\n';
}

int main() {

  std::vector<int> v(1000); // allocate room for 1000 elements
  printCapLen(v);

  v.resize(0); // resize to 0 elements
  printCapLen(v);

  v.shrink_to_fit();
  printCapLen(v);

  return 0;
}
