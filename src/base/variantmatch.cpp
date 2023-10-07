
#include <iostream>
#include <optional>
#include <string>
#include <variant>

#include "boost/optional.hpp"
#include "fmt/format.h"
#include "mpark/patterns.hpp"
#include "tl/expected.hpp"
using str = std::string;

struct Mpair {
  int x;
  int y;
};
int main(int argc, char* argv[]) {
  std::variant<int, str> v = 42;
  boost::optional<int> opt = 12;
  std::optional<int> optt = std::nullopt;
  tl::expected<int, str> exp{20};
  tl::expected<int, str> exp2 = tl::make_unexpected("error");
  // exp.has_value()
  if (exp) {
    std::cout << "exp ok \n";
  }
  using namespace mpark::patterns;
  match(v)(
      pattern(as<int>(_)) = [] { std::cout << "int type\n"; },
      pattern(as<str>(_)) = [] { std::cout << "str\n"; });
  if_let(pattern(as<int>(_)) = v) = [] { std::cout << "int type\n"; };
  // IDENTIFIERS(x);
  match(opt)(
      pattern(some(58)) = [] { std::cout << "some int other\n"; },
      pattern(some(44)) = [] { std::cout << "some int 42 \n"; },
      pattern(some(arg)) =
          [](int m) {
            WHEN(m < 44) { std::cout << "some less 44 " << m << "  \n"; };
          },
      pattern(some(arg)) =
          [](int m) {
            WHEN(m < 24) { std::cout << "some less 24" << m << "  \n"; };
          },
      pattern(none) = [] { std::cout << "none str\n"; });
  if_let(pattern(some(arg)) = optt) = [](auto x) {
    fmt::println("if let value {}", x);
  };
  if_let(pattern(none) = optt) = []() { fmt::println("if let none"); };
  boost::optional<int> opt2 = boost::none;
  auto opp = opt2.value_or_eval([]() { return 4; });
  opt2.map([](auto x) { return boost::optional<int>{34}; });
  auto opp2 = opt2.flat_map([](auto x) {
    fmt::println("opt value {}", x);
    return boost::optional<std::string>{"ok"};
    // return 34;
  });
  // if_let(pattern(some(arg)) = opt) = [](auto x) {
  //   fmt::println("has value {}", x);
  // };

  std::vector<Mpair> pairs = {{0, 1}, {1, 1}, {0, 0}, {0, 2}};

  using namespace mpark::patterns;
  for_let(pattern(ds(1, arg)) = pairs) = [](auto x) { std::cout << x << ' '; };
  Mpair couple{.x = 90,.y = 200,};
  // if_let(pattern(ds(200,_)) = couple)=[](auto x){fmt::println("200");};

  return 0;
}
