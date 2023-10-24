#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>

#include "doctest/doctest.h"
#include "fmt/format.h"
#include "fmt/ranges.h"
#include "nonstd/span.hpp"

float factorial(float number) {
  return number <= 1.0 ? number : factorial(number - 1) * number;
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

TEST_CASE("2f factorial function") {
  CHECK(factorial(1.0) == 1.0);
  CHECK(factorial(2.0) == 2.0);
  CHECK(factorial(3.0) == 6.0);
  CHECK(factorial(10.0) == 3628800.0);
}

TEST_CASE("spand test") {
  std::vector<int> s{1, 2, 3, 4, 5};
  CHECK(printlite<int>(s) == 5);
  CHECK(firste<int>(s) == 2);

  SUBCASE("spand string") {
    std::vector<uint32_t> s{9, 20, 31, 14, 65};
    CHECK(firste<uint32_t>(s) == 9);
    SUBCASE("spand string 2") { fmt::println("dispatch"); }
  }
}