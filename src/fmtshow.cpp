#include <vector>

#include "boost/container/small_vector.hpp"
#include "boost/container/static_vector.hpp"
#include "boost/optional.hpp"
#include "fmt/format.h"
#include "fmt/ranges.h"
int main(int argc, char *argv[]) {
  std::vector<int> vec = {1, 2, 3};
  boost::container::small_vector<int, 4> vec2{1, 2, 3, 9};
  fmt::println("vec {}", vec);
  fmt::println("vec2 {}", vec2);
  boost::container::static_vector<int, 4> vec3{1, 2, 3, 19};
  fmt::println("vec3 {}", vec3);

  boost::optional<int> opt{56};
  opt.map([](int x) { fmt::println("opt {}", x); return boost::optional<int>{x + 1}; });
  return 0;
}
