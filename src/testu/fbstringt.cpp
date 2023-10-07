#include <cstdint>
#include <string>

#include "catch2/benchmark/catch_benchmark.hpp"
#include "catch2/catch_test_macros.hpp"
#include "folly/FBString.h"
#include "folly/FBVector.h"

uint64_t fibonacci(uint64_t number) {
  return number < 2 ? number : fibonacci(number - 1) + fibonacci(number - 2);
}
uint32_t factorial(uint32_t number) {
  return number <= 1 ? number : factorial(number - 1) * number;
}
TEST_CASE("Benchmark Fibonacci1", "[!benchmark]") {
  REQUIRE(fibonacci(5) == 5);

  REQUIRE(fibonacci(20) == 6'765);
  BENCHMARK("fibonacci 20") { return fibonacci(20); };

  REQUIRE(fibonacci(25) == 75'025);
  BENCHMARK("fibonacci 25") { return fibonacci(25); };
}
TEST_CASE("Factorials are computed", "[!benchmark]") {
  REQUIRE(factorial(1) == 1);
  REQUIRE(factorial(2) == 2);
  REQUIRE(factorial(3) == 6);
  REQUIRE(factorial(10) == 3'628'800);
}

TEST_CASE("fbstringt1", "[folly]") {
  folly::fbstring fb{"station"};

  REQUIRE(fb.toStdString() == std::string("station"));
}

TEST_CASE("fbvector", "[folly5]") {
  BENCHMARK("fbvector 25") {
    folly::fbvector<uint32_t> snum{3, 99, 18, 85};
    snum.reserve(200);
    for (auto& ele : snum) {
      ele = ele + 200;
    }
  };

}