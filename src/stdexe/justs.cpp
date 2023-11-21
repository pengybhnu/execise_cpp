#include <iostream>
#include <span>
#include <stdexec/execution.hpp>
#include <thread>

#include "exec/static_thread_pool.hpp"
int main(int argc, char* argv[]) {
  {
    auto ju = stdexec::just(10.0);

    auto res = stdexec::sync_wait(ju);
    auto [x] = res.value();
    std::cout << x << "\n";
  }
  exec::static_thread_pool pool{5};
  stdexec::execute(pool.get_scheduler(),
                   []() { std::cout << "exc" << std::endl; });

  return 0;
}