
#include <folly/fibers/FiberManagerMap.h>
#include <folly/init/Init.h>

#include <iostream>
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
  folly::init(&argc, &argv);

  folly::EventBase evb;
  //   folly::fibers::getFiberManager(evb).addTask([&]() { f(nullptr); });
  folly::fibers::getFiberManager(evb).addTask(
      [&]() { std::cout << "fib 1\n"; });
  folly::fibers::getFiberManager(evb).addTask(
      [&]() { std::cout << "fib 2\n"; });
  folly::fibers::getFiberManager(evb).addTask([]() { std::cout << "fib 3\n"; });
  evb.loopForever();
}