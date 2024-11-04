#include <array>
#include <iostream>
#include <mdspan>

// An alias template to allow us to define a one-dimensional std::array using
// two dimensions
template <typename T, std::size_t Row, std::size_t Col>
using ArrayFlat2d = std::array<T, Row * Col>;

int main() {
  // Define a one-dimensional std::array of int (with 3 rows and 4 columns)
  ArrayFlat2d<int, 3, 4> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

  // Define a two-dimensional span into our one-dimensional array
  // We must pass std::mdspan a pointer to the sequence of elements
  // which we can do via the data() member function of std::array or std::vector
  std::mdspan mdView{arr.data(), 3, 4};

  // print array dimensions
  // std::mdspan calls these extents
  std::size_t rows{mdView.extents().extent(0)};
  std::size_t cols{mdView.extents().extent(1)};
  std::cout << "Rows: " << rows << '\n';
  std::cout << "Cols: " << cols << '\n';

  // print array in 1d
  // The data_handle() member gives us a pointer to the sequence of elements
  // which we can then index
  for (std::size_t i = 0; i < mdView.size(); ++i)
    std::cout << mdView.data_handle()[i] << ' ';
  std::cout << '\n';

  // print array in 2d
  // We use multidimensional [] to access elements
  for (std::size_t row = 0; row < rows; ++row) {
    for (std::size_t col = 0; col < cols; ++col)
      std::cout << mdView[row, col] << ' ';
    std::cout << '\n';
  }
  std::cout << '\n';

  return 0;
}
