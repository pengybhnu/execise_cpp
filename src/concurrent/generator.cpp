#include <coro/coro.hpp>
#include <iostream>

int main() {
  auto task = [](uint64_t count_to) -> coro::task<void> {
    // Create a generator function that will yield and incrementing
    // number each time its called.
    auto gen = []() -> coro::generator<uint64_t> {
      uint64_t i = 0;
      while (true) {
        i += 2;
        co_yield i;
      }
    };
    auto it = gen();

        std::cout<< *(it.begin()) << std::endl;
        std::cout<< *(it.begin()) << std::endl;
        std::cout<< *(it.begin()) << std::endl;

    // Generate the next number until its greater than count to.
    for (auto val : it) {
      std::cout << val << ", ";

      if (val >= count_to) {
        std::cout << std::endl;
        break;
      }
    }

    co_return;
  };

  coro::sync_wait(task(100));
}