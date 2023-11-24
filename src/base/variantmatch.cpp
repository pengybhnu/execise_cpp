
#include <iostream>
#include <optional>
#include <string>
#include <variant>

#include "boost/optional.hpp"
#include "fmt/format.h"
#include "fmt/ranges.h"
#include "mpark/patterns.hpp"
#include "nonstd/expected.hpp"
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
  exp.transform([](const auto& x) {
       fmt::println("expected transform {}", x);
       return 20;
     })
      .and_then([](const auto& x) {
        fmt::println("expected and_then {}", x);
        tl::expected<uint32_t, str> mm = tl::make_unexpected("error");
        return mm;
      })
      .or_else([](const auto& x) {
        fmt::println("expected or_else");
        return tl::expected<uint32_t, str>{300};
      })
      .map([](const auto& x) {
        fmt::println("expected map {}", x);
        return 3600;
      });

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
  boost::optional<int> opt3{56};

  boost::optional<int> opp = opt3.value_or_eval([]() { return 34; });
  // opt2.map([](auto x) { return boost::optional<int>{34}; });
  auto opp2 = opp.flat_map([](auto x) {
    fmt::println("opt value {}", x);
    return boost::optional<std::string>{"ok"};
    // return 34;
  });
  auto opp3 = opp2.map([](auto x) {
                    fmt::println("opt value {}", x);
                    return 20;
                  })
                  .map([](auto& x) {
                    fmt::println("opt value {}", x);
                    return std::vector{"ok", "online"};
                  })
                  .map([](auto& x) {
                    fmt::println("opt value {}", x);
                    return 45;
                  });
  // if_let(pattern(some(arg)) = opt) = [](auto x) {
  //   fmt::println("has value {}", x);
  // };

  std::vector<Mpair> pairs = {{0, 1}, {1, 1}, {0, 0}, {0, 2}};

  using namespace mpark::patterns;
  for_let(pattern(ds(1, arg)) = pairs) = [](auto x) { std::cout << x << ' '; };
  Mpair couple{
      .x = 90,
      .y = 200,
  };
  // if_let(pattern(ds(200,_)) = couple)=[](auto x){fmt::println("200");};
  // std::cout << std::atan2(1, 0) << std::endl;
  // std::cout << std::atan2(0, 1) << std::endl;

  std::any stg = 1;
  stg = std::string_view("hello");
  fmt::println("-----------------------------------");
  // stg = uint32_t(20);
  match(stg)(
      pattern(as<int>(arg)) = [](auto x) { fmt::println("int {}", x); },
      pattern(as<uint32_t>(arg)) =
          [](auto x) { fmt::println("uint32_t {}", x); },
      pattern(as<std::string>(arg)) =
          [](auto x) { fmt::println("string {}", x); },
      pattern(_) = [] { fmt::println("string"); });

  using str = std::string;
  std::any a = str("hello");

  match(a)(
      pattern(as<int>(_)) = [] { std::cout << "int\n"; },
      pattern(as<str>(_)) = [] { std::cout << "str\n"; });

  // auto p = std::make_unique<int>(1);
  auto p = std::make_shared<int>(1);
  // p = nullptr;
  match(p)(
      pattern(some(_)) = [] { std::cout << "std::unique\n"; },
      pattern(none) = [] { std::cout << "nullptr\n"; });
  // prints: "none"
  {
    fmt::println("-----------------------------------");
    auto start = tl::expected<std::string, int>(tl::unexpect, 1);
    // auto start = tl::expected<std::string, int>("jok");
    auto finals = start.or_else([](auto& x) -> tl::expected<std::string, int> {
      fmt::println("error {}", x);
      if (x == 2)
        return std::string("ok");
      else {
        return tl::expected<std::string, int>(tl::unexpect, 2);
      }
    });
    // .map([](const auto& y)-> tl::expected<std::string, int> {
    //   fmt::println("ok {}", y);
    //   return y;
    // });
    if (finals) {
      fmt::println("has ok {}", finals.value());
    } else {
      fmt::println("has error ", finals.error());
    }
  }
  {
    fmt::println("-----------------------------------");
    // auto start = tl::expected<std::string, int>(tl::unexpect, 2);
    auto start = tl::expected<std::string, int>("jok");
    auto finals = start.or_else([](auto& x) -> tl::expected<std::string, int> {
      fmt::println("error {}", x);
      if (x == 2)
        return std::string("ok");
      else {
        return tl::expected<std::string, int>(tl::unexpect, 2);
      }
    });
    // .map([](const auto& y)-> tl::expected<std::string, int> {
    //   fmt::println("ok {}", y);
    //   return y;
    // });
    if (finals) {
      fmt::println("has ok {}", finals.value());
    } else {
      fmt::println("has error ", finals.error());
    }
  }
}
