#include <optional>
#include <type_traits>

#include "fmt/format.h"
#include "mpark/patterns.hpp"
#include "tl/optional.hpp"

int main(int argc, char* argv[]) {
  tl::optional<int> opt1 = tl::nullopt;
  tl::optional<int> opt = {58'0000};

  auto finalstate = opt.map([](auto x) {
                         fmt::println("opt {}", x);
                         return tl::optional<int>{x + 1};
                         //  return tl::nullopt;
                       })
                        .transform([](auto x) {
                          fmt::println("transform {}", x.value());
                          // return tl::optional<int>{x + 1};
                          return 10;
                        })
                        .and_then([](auto x) {
                          fmt::println("and_then {}", x);
                          return tl::optional<std::string>{"ok"};
                          //   return 90;
                        })
                        .map([](auto x) -> char {
                          fmt::println("map {}", x);
                          return 'C';
                          // return tl::nullopt;
                        })
                        .and_then([](auto x) {
                          fmt::println("and_then {}", x);
                          return tl::optional<char>{x + 1};
                        })
                        .or_else([]() {
                          fmt::println("or_else");
                          return tl::nullopt;
                        });
  fmt::println("-----------------------");
  std::optional<int> opt2{100};
  auto finalt = opt2.and_then([](auto x) {
                      fmt::println("and_then {}", x);
                      return std::optional<std::string>{"get value"};
                    })
                    .transform([](auto x) -> char {
                      fmt::println("std transform {}", x);
                      return 'c';
                    })
                    .and_then([](const auto& x) -> std::optional<int> {
                      fmt::println("std and_then {}", x);
                      return std::optional<int>{10};
                      //   return 100;
                    })
                    .transform([](auto x) -> int {
                      fmt::println("std transform {}", x);
                      return 100;
                    })
                    .and_then([](const auto x) -> std::optional<int> {
                      fmt::println("and_then {}", x);
                      return std::nullopt;
                    })
                    .or_else([] {
                      fmt::println("or_else");
                      return std::optional<int>{1006};
                    });
  using namespace mpark::patterns;

  match(opt)(
      pattern(some(arg)) = [](const auto& v) { fmt::println("value {}", v); },
      pattern(none) = [] { fmt::println("none"); });
  match(opt1)(
      pattern(some(arg)) = [](const auto& v) { fmt::println("value {}", v); },
      pattern(none) = [] { fmt::println("none"); });
  if_let(pattern(some(arg)) = opt1) = [](auto x) {
    fmt::println("if let value {}", x);
  };
  // std::variant<int,double,char> p{90};
  // std::variant<int,double,char> p{106.39};
  std::variant<int, double, char> p{'F'};
  p = 259;

  match(p)(
      pattern(as<double>(arg)) = [](auto x) { fmt::println("double {}", x); },
      pattern(as<int>(arg)) = [](auto x) { fmt::println("int {}", x); },
      pattern(as<char>(arg)) = [](auto x) { fmt::println("char {}", x); });
  int base = 10;
}

template <class T>
class Tloptional {
  static bool GetType() { return std::is_integral<T>::value; }
};