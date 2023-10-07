#include <algorithm>
#include <ranges>
#include <vector>

#include "fmt/format.h"
#include "fmt/ranges.h"

int main(int argc, char* argv[]) {
  std::vector<int> ll{1, 3, 6, 9, 6};
  std::vector<int> ll2;
  std::ranges::stable_sort(ll);
  fmt::println("o {}", ll);
  std::erase(ll, 6);
  fmt::println("o {}", ll);
  ll.emplace_back(-5);
  std::ranges::sort(ll);
  fmt::println("stable o {}", ll);
  fmt::println("o {}", ll);
  std::ranges::copy(ll, back_inserter(ll2));
  std::fill_n(ll2.begin(), 2, 212);
  fmt::println("o {}", ll2);

  return 0;
}