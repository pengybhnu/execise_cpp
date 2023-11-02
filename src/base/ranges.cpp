#include "fmt/ranges.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <range/v3/action/slice.hpp>
#include <range/v3/action/sort.hpp>
#include <range/v3/algorithm/copy.hpp>
#include <range/v3/algorithm/permutation.hpp>
#include <range/v3/all.hpp>
#include <range/v3/core.hpp>
#include <range/v3/numeric/accumulate.hpp>
#include <range/v3/view/all.hpp>
#include <range/v3/view/chunk_by.hpp>
#include <range/v3/view/cycle.hpp>
#include <range/v3/view/enumerate.hpp>
#include <range/v3/view/filter.hpp>
#include <range/v3/view/generate.hpp>
#include <range/v3/view/iota.hpp>
#include <range/v3/view/join.hpp>
#include <range/v3/view/map.hpp>
#include <range/v3/view/slice.hpp>
#include <range/v3/view/sliding.hpp>
#include <range/v3/view/split.hpp>
#include <range/v3/view/stride.hpp>
#include <range/v3/view/take.hpp>
#include <range/v3/view/take_last.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/view/zip.hpp>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "fmt/format.h"
#include "fmt/ranges.h"

int main(int argc, char* argv[]) {
  using namespace ranges;
  std::cout << "-------------values " << std::endl;

  std::map<std::string, int> m = {{"this", 0}, {"that", 1}, {"other", 2}};
  auto keys = m | views::values | ranges::to<std::vector<int>>();
  keys.emplace_back(9);
  fmt::print("values: {}\n", keys);
  std::cout << "-------------keys " << std::endl;

  auto keys2 = m | ranges::views::keys | ranges::to<std::set<std::string>>();
  fmt::print("keys: {}\n", keys2);
  auto to_string = [](int i) {
    std::stringstream str;
    str << i;
    return str.str();
  };

  std::cout << "-------------zip " << std::endl;

  auto map1 =
      views::zip(views::ints, views::ints | views::transform(to_string)) |
      views::take(5) | to<std::map<int, std::string>>();

  fmt::print("map: {}\n", map1);

  // cycle
  std::cout << "-------------cycle " << std::endl;

  std::vector<int> v{1, 2, 3};
  auto r = v | ranges::views::cycle | ranges::views::take(6);
  std::cout << ranges::views::all(r) << "\n";
  // enumerate
  std::cout << "-------------enumerate " << std::endl;

  std::vector<int> ev{5, 4, 3, 2, 1, 1, 1};
  for (auto&& [i, e] : ev | ranges::views::enumerate) {
    std::cout << i << ", " << e << "\n";
  }

  std::vector<int> x{5, 4, 3, 2, 1};
  std::cout << "-------------slice [1,3]" << std::endl;

  auto y = x | ranges::copy | ranges::actions::slice(1, 3);
  std::cout << ranges::views::all(y) << "\n";
  // [4,3]
  std::cout << "-------------slice [4,3]" << std::endl;
  for (auto&& e : x | ranges::views::slice(2, 4)) {
    std::cout << e << "\n";
  }
  std::cout << "-------------iota 5 8" << std::endl;
  auto seq = ranges::views::iota(5, 8);
  std::cout << ranges::views::all(seq) << "\n";
  for (auto&& e : seq) {
    std::cout << e << "\n";
  }
  std::cout << "-------------generate " << std::endl;

  auto fib = ranges::views::generate([i = 0, j = 1]() mutable {
    int tmp = i;
    i += j;
    j = i;
    return tmp;
  });

  auto vt = fib | ranges::views::take(5);
  //   std::cout << ranges::views::all(vt) << std::endl;
  for (auto&& e : vt) {
    std::cout << e << std::endl;
  }

  std::cout << "-------------permutation " << std::endl;

  std::vector<int> pv{1, 6, 3};
  // auto pv2 = ranges::next_permutation(pv);
  do {
    std::cout << ranges::views::all(pv) << "\n";
  } while (ranges::next_permutation(pv));
  fmt::println("pv {}", pv);
  do {
    std::cout << ranges::views::all(pv) << "\n";
  } while (ranges::next_permutation(pv));
  pv.emplace_back(-1);
  std::cout << "-------------sort " << std::endl;

  fmt::println("pv {}", pv);
  ranges::sort(pv, [](auto a, auto b) { return a > b ? false : true; });
  fmt::println("pv {}", pv);

  std::cout << "-------------filter " << std::endl;

  std::vector<int> bv{1, 2, 3, 4, 5};
  auto br = bv | ranges::views::filter([](auto&& x) { return x > 3; }) |
            ranges::to<std::vector>();
  br.emplace_back(1009);
  std::cout << ranges::views::all(br) << "\n";
  std::cout << "-------------group_by chunk_by" << std::endl;
  std::vector<int> serl{1, 2, 9, 7, 8, 3, 4, 5, 26, 31};

  auto gr = serl |
            ranges::views::chunk_by([](auto&& x, auto&& y) { return x < y; }) |
            ranges::to<std::vector<std::vector<int>>>();
  // std::cout << ranges::views::all(gr) << "\n";
  for (auto& p : gr) {
    fmt::println("{}", p);
  }
  std::cout << "-------------accumulate" << std::endl;

  auto acc = ranges::accumulate(serl, 0);

  std::cout << acc << std::endl;

  {
    std::cout << "-------------zip_with" << std::endl;

    auto const v1 = std::vector<int>{4, 2, 7};
    auto const v2 = std::vector<int>{3, 2, 1};
    auto rng1 = ranges::views::zip_with([](int a, int b) { return a + b; }, v1,
                                        v2);  // [7,4,8]
    std::cout << ranges::views::all(rng1) << "\n";
  }

  {
    std::cout << "-------------zip" << std::endl;

    const auto v_ar = std::vector<int>{1, 10, 100, 1000, 10000};
    const auto v_cn = std::vector<std::string>{"一", "十", "百", "千", "万"};
    auto rng =
        ranges::views::zip(v_ar, v_cn) | ranges::to<std::map<int, std::string>>;
    for (auto&& [first, second] : rng) {
      std::cout << first << ", " << second << '\n';
    }
  }

  {
    std::cout << "-------------split" << std::endl;

    auto const s = std::string{"hello world"};
    auto srng = s | ranges::views::split(' ') |
                ranges::to<std::vector<std::string>>();  // materialization
    std::cout << ranges::views::all(srng) << "\n";
  }

  {
    std::string v = "/devices/tr1555/hdmap/mapinfo";
    auto fun = [](char x, char y) { return not(x == '/' or y == '/'); };
    auto view = v | ranges::views::chunk_by(fun);
    std::cout << ranges::views::all(view) << "\n";
  }
  {
    std::cout << "-------------split" << std::endl;
    std::string v = "/devices/tr1555/hdmap/mapinfo";
    auto view = v | ranges::views::split('/') |
                ranges::views::filter([](auto&& x) { return !x.empty(); }) |
                ranges::to<std::vector<std::string>>;
    auto view2 =
        v | ranges::views::split('/') | ranges::to<std::vector<std::string>>;
    std::cout << ranges::views::all(view) << "\n";
    std::cout << ranges::views::all(view2) << "\n";
  }

  {
    std::vector<std::string> s1{"S1", "S3", "S2"};
    std::vector<std::string> s2{"S11", "S3", "S2", "S5"};
    // ranges::diff(s1,s2);
  }
  {
    std::string s{"hello"};

    // output: h e l l o
    ranges::for_each(s, [](char c) { std::cout << c << ' '; });
  }
  {
    std::map<std::string, std::vector<std::string>> groupedStrings;
    std::vector<std::string> s1{"A-space1",   "A-park1",    "B-parkin2",
                                "D-park3",    "A-parking4", "AF-parking4",
                                "B-parking5", "D-parking88"};
    // std::sort(s1.begin(), s1.end());
    ranges::sort(s1);
    ranges::for_each(s1, [&groupedStrings](auto& s) {
      std::string prefix = ranges::views::split(s, '-') |
                           ranges::views::take(1) | ranges::views::join |
                           ranges::to<std::string>();
      groupedStrings[prefix].emplace_back(s);
    });
    // std::cout << ranges::views::all(gr) << "\n";

    for (const auto& p : groupedStrings) {
      fmt::print("{} ==> ", p);
    }
  }
  {
    std::vector<std::string> ss{"A-space1",   "A-park1",    "B-parkin2",
                                "D-park3",    "A-parking4", "AF-parking4",
                                "B-parking5", "D-parking88"};
    auto gr = ss | ranges::views::chunk_by([](auto&& x, auto&& y) {
                auto f = x | ranges::views::split('-') |
                         ranges::views::take(1) | ranges::views::join;
                auto p = y | ranges::views::split('-') |
                         ranges::views::take(1) | ranges::views::join;
                return *p.begin() == *f.begin();
              }) |
              ranges::to<std::vector<std::vector<std::string>>>;
    for (const auto& p : gr) {
      fmt::print("{} ==> ", p);
    }
  }
  {
    std::cout << "\n";
    std::string station{"ad-jjiiida"};
    auto v2 = station | ranges::view::stride(2);
    std::cout << ranges::views::all(v2) << "\n";
    auto v3 = station | ranges::view::sliding(6);
    std::cout << ranges::views::all(v3) << "\n";
  }
  {
    auto numbers = ranges::views::ints(2, 7);

    std::cout << numbers << '\n';
  }

  return 0;
}
