
#include <folly/system/ThreadName.h>

#include <iostream>

#include "folly/fibers/FiberManagerMap.h"
#include "folly/futures/Future.h"
#include "folly/init/Init.h"
#include "folly/io/async/ScopedEventBaseThread.h"
using namespace std::chrono_literals;
using namespace folly;
void f(int* p) {
  LOG(INFO) << "f()";
  // Make sure recursion is not optimized out
  int a[100];
  for (size_t i = 0; i < 100; ++i) {
    a[i] = i;
    ++(a[i]);
    if (p) {
      a[i] += p[i];
    }
  }
  f(a);
}

int main(int argc, char* argv[]) {
  {
    constexpr StringPiece kThreadName{"my_thread"};
    ScopedEventBaseThread t2(kThreadName);
    Optional<std::string> createdThreadName;
    Baton<> done;

    t2.getEventBase()->runInEventBaseThread([&] {
      auto createdThreadName = folly::getCurrentThreadName();
      std::cout << createdThreadName.value() << "\n";
      std::cout << "runInEventBaseThread: " << std::this_thread::get_id();

      done.post();
    });
  }
  folly::EventBase evb;
  //   folly::fibers::getFiberManager(evb).addTask([&]() { f(nullptr); });
  folly::fibers::getFiberManager(evb).addTask([&]() {
    std::cout << "fib 1\n";
    std::cout << "fib 1: " << std::this_thread::get_id();

    std::this_thread::sleep_for(4s);
    // auto rp = folly::fibers::await([](folly::Future<int> x) {});
  });
  folly::fibers::getFiberManager(evb).addTask([&]() {
    std::cout << "fib 2\n";
    std::this_thread::sleep_for(4s);
  });
  folly::fibers::getFiberManager(evb).addTask([]() { std::cout << "fib 3\n"; });
  evb.loopForever();
}