#include <iostream>

#include "cppcoro/generator.hpp"
#include "cppcoro/async_generator.hpp"
#include "cppcoro/static_thread_pool.hpp"
#include "cppcoro/task.hpp"
// #include <ranges>
#include "range/v3/range.hpp"
#include "range/v3/view/iota.hpp"
// #include <views>
using namespace std::chrono_literals;
cppcoro::generator<char> hello() {
  co_yield 'h';
  co_yield 'e';
  co_yield 'l';
  co_yield 'l';
  co_yield 'o';
}
cppcoro::generator<int> fib() {
  co_yield 0;  // (1)
  auto a = 0;
  auto b = 1;
  for (auto n : ranges::views::iota(0)) {
    auto next = a + b;
    a = b;
    b = next;
    std::cout << __func__ << " " << __FILE__ << " " << __LINE__ << "\n\n";
    co_yield next;  // (2)
  }
}


// cppcoro::task<> consumer(cppcoro::static_thread_pool& tp) {
//   auto sequence = ticker(10, tp);
//   for co_await (std::uint32_t i : sequence) {
//     std::cout << "Tick " << i << std::endl;
//   }
// }

cppcoro::generator<const long long> fibonacci() {
  long long a = 0;
  long long b = 1;
  while (true) {
    co_yield b;  // (2)
    std::cout << __func__ << " " << __FILE__ << " " << __LINE__ << "\n\n";

    auto tmp = a;
    a = b;
    b += tmp;
  }
}

int main() {
  std::cout << std::endl;

  for (auto c : hello()) std::cout << c;

  std::cout << "\n\n";

  for (auto i : fibonacci()) {
    if (i > 1'000'000) break;
    std::cout << i << " ";
  }
  std::cout << "<------------->"
            << "\n";
  for (auto i : fib()) {
    if (i > 1'000'000) break;
    std::cout << i << " --> ";
  }
  std::cout << "\n\n";

 
}