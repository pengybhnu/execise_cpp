#include "fmt/format.h"
#include <chrono>
int main(int argc, char* argv[]) {
  {

    int base = 3;
    if (not(236 > base)) {
      fmt::print("not false\n");
    }
    if (1260 not_eq base) {
      fmt::print("not_eq\n");
    }
    if (5600 not_eq base) {
      fmt::print("v not_eq\n");
    }
    if ((base > 200) or (base < 9000)) {
      fmt::print("v or\n");
    }

    auto sf = std::make_shared<int>(base);
    if (sf) fmt::print("sf {}\n", *sf);
    if (sf not_eq nullptr) fmt::print("sf {}\n", *sf);
    sf.reset();
    if (sf) fmt::print("sf reset{}\n", *sf);
  }
  auto time = std::chrono::steady_clock::now();
  time.time_since_epoch().count();
  fmt::print("time {0} {1}\n", time.time_since_epoch().count(),time.time_since_epoch().zero());
}