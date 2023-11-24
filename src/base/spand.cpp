#include <iostream>
#include <list>
#include <span>
#include <thread>
#include <vector>

#include "base/point.pb.h"
#include "fmt/format.h"
#include "fmt/ranges.h"
#include "nonstd/span.hpp"
#include "tcb/span.hpp"

template <class T>
void printv(tcb::span<T> s) {
  fmt::println("tcb {}", s.size());
  for (auto &&s : s) {
    fmt::print("{}", s);
  }
  fmt::print("\n{0} {1} {2}\n", s[0], s.first(2), s.back());
  fmt::println("subspan{0}", s.subspan(1, 2));
}

template <class T>
void printlite(nonstd::span<T> s) {
  fmt::println("\n------------nonstd {}", s.size());
  for (auto &&s : s) {
    fmt::print("{}", s);
  }
  fmt::print("\n{0} {1} {2}\n", s.front(), s.first(2), s.back());
  fmt::println("subspan{0}", s.subspan(1, 2));
}
void printlite(nonstd::span<char> s) {
  fmt::println("\n------------nonstd {}", s.size());
  for (auto &&s : s) {
    fmt::print("{}", s);
  }
  fmt::print("\n{0} {1} {2}\n", s.front(), s.first(2), s.back());
  fmt::println("subspan{0}", s.subspan(1, 2));
}
// void printstd(std::span<int> s) {
//   fmt::println("\n------------std {}", s.size());
//   for (auto &&s : s) {
//     fmt::print("{}", s);
//   }
//   fmt::print("\n{0} {1} {2}\n",s.front(),s.first(2),s.back());
//   fmt::println("subspan{0}",s.subspan(1,2));

// }

int main(int argc, char *argv[]) {
#if __has_include("span")
  std::cout << "found " << std::endl;
#endif

  std::vector<int> s{1, 2, 3, 4, 5};
  std::list<int> sl{1, 2, 3, 4, 5};
  std::array<int, 3> arr{1, 8, 9};
  auto span = tcb::make_span(s);

  std::string sta{"station"};
  //   fmt::println("{}", span);
  printv<int>(s);
  printlite<int>(s);
  printlite<int>(arr);
  //   printstd(arr);
  printlite<char>(sta);
  dispatch::Geo geo;
  geo.add_lines(1);
  geo.add_lines(102);
  geo.add_lines(56);

  fmt::println("lines {}", geo.lines());
  // tcb::span<const uint32_t> lines(geo.mutable_lines()->mutable_data(),
  // geo.lines().size()); tcb::span<const uint32_t> lines(geo.lines());
  printv<const uint32_t>(geo.lines());

  std::vector<int> a = {23, 89};
  std::vector<int> vp{23, 26};
  std::jthread([&geo]() {
    fmt::println("lines agian {}", geo.lines());
  });
}