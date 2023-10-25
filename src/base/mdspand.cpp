
#include <iostream>

#include "experimental/mdspan"

int main() {
  std::array d{
      0, 5, 1, 3, 8, 4, 2, 7, 6,
  };

  std::experimental::mdspan m{d.data(), std::experimental::extents{3, 3}};
  m(1, 1, 1) = 10;

  for (std::size_t i = 0; i < m.extent(0); ++i)
    for (std::size_t j = 0; j < m.extent(1); ++j)
      std::cout << "m(" << i << ", " << j << ") == " << m(i, j) << "\n";
}
