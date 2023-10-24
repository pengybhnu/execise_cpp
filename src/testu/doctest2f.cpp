#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>

#include "doctest/doctest.h"
#include "fmt/format.h"
#include "fmt/ranges.h"
#include "nonstd/span.hpp"

int factorial(int number) {
  return number <= 1 ? number : factorial(number - 1) * number;
}
template <class T>
std::size_t printlite(nonstd::span<T> s) {
  fmt::println("\n------------nonstd {}", s.size());
  return s.size();
}

template <class T>
T firste(nonstd::span<T> s) {
  fmt::println("\n------------nonstd {}", s.size());
  return s.front();
}

TEST_CASE("testing the factorial function") {
  CHECK(factorial(1) == 1);
  CHECK(factorial(2) == 2);
  CHECK(factorial(3) == 6);
  CHECK(factorial(10) == 3628800);
}

TEST_CASE("span test") {
  std::vector<int> s{1, 2, 3, 4, 5};
  CHECK(printlite<int>(s) == 5);
  CHECK(firste<int>(s) == 2);

  SUBCASE("span string") {
    std::vector<uint32_t> s{9, 20, 31, 14, 65};
    CHECK(firste<uint32_t>(s) == 3);
    SUBCASE("span string 2") { fmt::println("dispatch"); }
  }
}