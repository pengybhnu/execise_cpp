#include <folly/Singleton.h>
#include <folly/executors/CPUThreadPoolExecutor.h>
#include <folly/executors/GlobalExecutor.h>
#include <folly/futures/Future.h>
#include <folly/futures/Promise.h>
#include <folly/synchronization/Baton.h>

#include <iostream>
// #include <chrono>
// #include <thread>
using namespace std::chrono_literals;
std::shared_ptr<folly::CPUThreadPoolExecutor> cpuExec;
int main(int argc, char **argv) {
  if(false){
    int count = 0;
    folly::Baton b;
    // folly::SingletonVault::singleton()->registrationComplete();

    // auto cpuExec = folly::getGlobalCPUExecutor();
    cpuExec = std::make_shared<folly::CPUThreadPoolExecutor>(10, 3);

    auto f = [&]() {
      count++;
      fmt::println("f {}", count);
      std::this_thread::sleep_for(3s);
      return count;
    };

    // Verify execution
    cpuExec->add(f);
    cpuExec->add(f);
    cpuExec->add(f);
    cpuExec->add(f);
    cpuExec->add(f);
    cpuExec->add(f);
    folly::Future<int> future1 = folly::via(cpuExec.get(), []() {
      fmt::println("Task 1 executed in CPU thread pool");
      std::this_thread::sleep_for(std::chrono::seconds(5));

      return 42;
    });
    auto fil = std::move(future1).thenValue(
        [](int result) { return std::string{"getv2"}; });
    fil.wait();
  }
  {
    // Create a Future that resolves to an integer value
    folly::Future<int> future = folly::makeFuture(42);

    // Chain a callback to the Future to print the value when it resolves
    // std::move(future).thenValue([](int value) {
    //   std::cout << "Future resolved with value: " << value << std::endl;
    //         std::this_thread::sleep_for(std::chrono::seconds(5));
    // });

    // std::move(future).wait();
  }
  {
      // future from a promise
    std::promise<int> p;
    std::future<int> f3 = p.get_future();
    std::thread( [&p]{ p.set_value_at_thread_exit(9); }).detach();
    f3.wait();
  }
  return 0;
}