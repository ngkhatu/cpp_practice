#include <iostream>

int main() {

  int *arr{new int[1000000]{}};

  arr[5000] = 50;

  std::cout << arr[5000] << std::endl;

  return 0;
}
