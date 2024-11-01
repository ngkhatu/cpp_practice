#include <algorithm> // for std::copy

int main() {
  int arr[]{1, 2, 3};
  int src[]{5, 6, 7};

  // Copy src into arr
  std::copy(std::begin(src), std::end(src), std::begin(arr));

  return 0;
}
