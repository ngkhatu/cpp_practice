#include <iostream>
#include <vector>

// Function template to calculate the average of the values in a std::vector
template <typename T> T calculateAverage(const std::vector<T> &arr) {
  std::size_t length{arr.size()};

  T average{0}; // if our array has elements of type T, our average should have
                // type T too
  for (std::size_t index{0}; index < length;
       ++index)            // iterate through all the elements
    average += arr[index]; // sum up all the elements
  average /= static_cast<int>(length);

  return average;
}

int main() {
  std::vector class1{84, 92, 76, 81, 56};
  std::cout << "The class 1 average is: " << calculateAverage(class1)
            << '\n'; // calc average of 5 ints

  std::vector class2{93.2, 88.6, 64.2, 81.0};
  std::cout << "The class 2 average is: " << calculateAverage(class2)
            << '\n'; // calc average of 4 doubles

  return 0;
}
