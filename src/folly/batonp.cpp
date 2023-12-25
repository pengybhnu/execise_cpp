
#include <folly/stop_watch.h>
#include <folly/synchronization/Baton.h>

#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

#include "folly/ScopeGuard.h"
#include "folly/Singleton.h"

using folly::Baton;
using std::chrono_literals::operator""s;
struct Tag {};
int main(int argc, char* argv[]) {
  Baton<true, std::atomic> baton;
  folly::stop_watch<std::chrono::milliseconds> watch;
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
  auto d2 = folly::makeGuard([&]() {
    std::cout << "guard elapsed" << std::endl;
    std::cout << watch.elapsed().count() << std::endl;
    auto const ttl = 5s;
    if (watch.elapsed(ttl)) {
      std::cout << "aad ";
    }
  });
  auto d1 = folly::makeGuard([&]() {
    waiter.join();
    poster.join();
    std::cout << "guard " << std::endl;
  });
  auto single = folly::Singleton<int>([]() { return new int(200); });
  auto f = folly::Singleton<int, Tag>([]() { return new int(6200); });
  auto tc1 = folly::SingletonVault::singleton<Tag>()->livingSingletonCount();
  std::cout << "count " << tc1 << std::endl;

  // Define three distinct tags
  struct Tag1 {};
  struct Tag2 {};
  struct Tag3 {};

  // Define the singleton objects
  struct SingletonObject {
    public:
    int code{100};
    SingletonObject() { std::cout << "SingletonObject created!" << std::endl; }
  };

  // Access the singleton objects
  folly::Singleton<SingletonObject, Tag1>();
  folly::Singleton<SingletonObject, Tag2>();

  folly::SingletonVault::singleton()->registrationComplete();

  auto op = single.try_get();
  if (op) {
    std::cout << *op << std::endl;
  }
  {
    auto op2 = folly::Singleton<int>::try_get();

    if (op2) {
      std::cout << "2 " << *op2 << std::endl;
    }
  }
  {
    auto op2 = folly::Singleton<int, Tag>::try_get();

    if (op2) {
      std::cout << "tag " << *op2 << std::endl;
    }
  }
  {
    auto op = folly::Singleton<SingletonObject, Tag1>::try_get();
    if (op) {
      std::cout << "Tag1 " << op->code << std::endl;
      op->code= 1123;
    }
    auto op2 = folly::Singleton<SingletonObject, Tag1>::try_get();
    if (op2) {
      std::cout << "Tag1 " << op2->code << std::endl;
      
    }
    folly::Singleton<SingletonObject, Tag2>::try_get();
    // folly::Singleton< SingletonObject, Tag3>::try_get();

    return 0;
  }
}