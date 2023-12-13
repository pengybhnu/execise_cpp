
#include <folly/synchronization/Baton.h>

#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

using folly::Baton;
using std::chrono_literals::operator""s;

int main(int argc, char* argv[]) {
  Baton<true, std::atomic> baton;
  std::thread waiter([&]() {
    // wait for an event before proceeding
    std::cout << "g-->";
    auto posted = baton.try_wait_for(5s);
    std::cout << " end\n";
  });
  std::thread poster([&]() {
    std::this_thread::sleep_for(6s);
    std::cout << "--b-->";
    baton.post();
  });
  waiter.join();
  poster.join();

  return 0;
}