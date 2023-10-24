#include "fmt/format.h"

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
  return 0;
}