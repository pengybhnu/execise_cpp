#include <mp-units/format.h>
#include <mp-units/ostream.h>
#include <mp-units/systems/international/international.h>
#include <mp-units/systems/isq/isq.h>
#include <mp-units/systems/si/si.h>

#include <iostream>

#include "fmt/format.h"
using namespace mp_units;

constexpr QuantityOf<isq::speed> auto avg_speed(QuantityOf<isq::length> auto d,
                                                QuantityOf<isq::time> auto t) {
  return d / t;
}

int main() {
  using namespace mp_units::si::unit_symbols;
  using namespace mp_units::international::unit_symbols;

  constexpr quantity v1 = 110 * (km / h);
  constexpr quantity v2 = 70 * mph;
  constexpr quantity v3 = avg_speed(220. * isq::distance[km], 2 * h);
  constexpr quantity v4 = avg_speed(isq::distance(140. * mi), 2 * h);
  constexpr quantity v5 = v3.in(m / s);
  constexpr quantity v6 = value_cast<m / s>(v4);
  constexpr quantity v7 = value_cast<int>(v6);

  std::cout << v1 << '\n';                                   // 110 km/h
  std::cout << v2 << '\n';                                   // 70 mi/h
  std::cout << fmt::format("{}", v3) << '\n';                // 110 km/h
  std::cout << fmt::format("{:*^14}", v4) << '\n';           // ***70 mi/h****
  std::cout << fmt::format("{:%Q in %q}", v5) << '\n';       // 30.5556 in m/s
  std::cout << fmt::format("{0:%Q} in {0:%q}", v6) << '\n';  // 31.2928 in m/s
  std::cout << fmt::format("{:%Q}", v7) << '\n';             // 31
  int num = 1;
  std::string id = "Mark_Point";
  for (auto num : {1, 18, 125, 1255}) {
    auto pid = fmt::format("{0}-{1:0>4}", id, num);
    std::string dump_id = pid.substr(0, pid.size() - 5);
    std::cout << pid << '\n';
    std::cout << dump_id << '\n';
  }
}