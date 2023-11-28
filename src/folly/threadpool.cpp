#include <folly/Singleton.h>
#include <folly/executors/CPUThreadPoolExecutor.h>
#include <folly/futures/Future.h>
#include "folly/futures/ThreadWheelTimekeeper.h"

#include <iostream>

#include "gflags/gflags.h"
folly::CPUThreadPoolExecutor threadPool(3);  // max threads

folly::CPUThreadPoolExecutor threadother(2);  // max threads

void promiset() {
  std::cout << "Promise--------------------- " << std::endl;

  folly::Promise<int> mint;
  auto res = mint.getFuture();
  std::cout << "Promise " << std::endl;
  std::cout << "Promise " << std::endl;

  res.via(&threadPool)
      .thenValue([](int x) -> int* {
        std::cout << "getFuture " << x << std::endl;
        return nullptr;
      })
      .ensure([]() { std::cout << "finally " << std::endl; });
  std::cout << "Promise " << std::endl;
  mint.setValue(10);
}
void futurethen() {
  std::cout << "Future then via threadpool--------------------- " << std::endl;

  folly::Future<int> future1 = folly::via(&threadPool, []() {
    std::cout << "Task 1 executed in CPU thread pool" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    return 42;
  });

  folly::Future<int> future2 = folly::via(&threadPool, []() {
    std::cout << "Task 2 executed in CPU thread pool "
              << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    return 100;
  });
  folly::Future<int> future3 = folly::via(&threadPool, []() {
    std::cout << "Task 3 executed in CPU thread pool "
              << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    return 100;
  });
  folly::Future<int> future5 = folly::via(&threadPool, []() {
    std::cout << "Task 5 executed in CPU thread pool" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(7000));
    return 100;
  });
  folly::Future<int> future6 = folly::via(&threadother, []() {
    std::cout << "Task 6 executed in CPU thread pool "
              << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    return 100;
  });
  folly::Future<int> future7 = folly::via(&threadPool, []() {
    std::cout << "Task 7 executed in CPU thread pool "
              << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(6));
    return 100;
  });
  folly::Future<void*> notr = folly::via(&threadother, []() -> void* {
    std::cout << "Task notr " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));
    return nullptr;
  });
  auto f5_7 = folly::collect(future5,future7);

  // Use the futures to retrieve the results
  std::move(future1).thenValue([](int result) {
    std::cout << "Task 1 result: " << result << std::endl;
  });

  std::move(future2).via(&threadother).thenValue([](int result) {
    std::cout << "Task 2 result: " << std::this_thread::get_id() << result
              << std::endl;
  });
  std::move(future3)
      .thenValue([](int result) {
        std::cout << "Task 3 result: " << std::this_thread::get_id() << result
                  << std::endl;
        return std::string{"getv"};
      })
      .thenValue([](auto&& result) {
        std::cout << "Task 3 result then2: " << std::this_thread::get_id()
                  << " " << result << std::endl;
        return std::string{"getv2"};
      })
      .thenTry([](folly::Try<std::string> strTry) {
        std::cout << "tryvaule " << std::this_thread::get_id() << " "
                  << strTry.value() << std::endl;
        // std::cout << strTry.exception().what() << std::endl;
        // try {
        //   int* a = nullptr;
        //   *a = 200;
        // } catch (std::exception const& e) {
        // }
        throw std::runtime_error("test");
      })
      .thenError(folly::tag_t<std::exception>{}, [](std::exception const& e) {
        std::cerr << "thenError " << e.what() << std::endl;
      });

  std::this_thread::sleep_for(std::chrono::seconds(10));
}
void futuremap() {

  auto f1 = folly::makeFuture(2);
  std::move(f1).filter([](auto& x){
    std::cout << "filter" << std::endl;
    return x;
  });
}
void futureontime() {
  
  std::vector<folly::Future<int>> futures1;
  futures1.emplace_back(folly::makeFuture(3));
  futures1.emplace_back(folly::makeFuture(3));
  futures1.emplace_back(folly::makeFuture(6));
  // folly::reduce(futures1, 0,[](auto x,auto y){
  //   std::cout << "reduce"<< std::endl;
  //   // return {};
  // });
   folly::Future<int> f3 = folly::via(&threadPool, []()  {
    std::cout << "Task 1 executed in CPU thread pool" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    return 4;
  });
  std::move(f3).delayed(std::chrono::seconds(2)).onTimeout(std::chrono::seconds(2), []() {
    std::cout << "time out" << std::endl;
    return -1;
  });
  folly::futures::sleep(std::chrono::milliseconds(1000)).defer([](auto x){
    std::cout << "defer" << std::endl;

  });
}
void proity() {
  using namespace folly;
  using namespace std::chrono_literals;
  bool tookLopri = false;
  auto completed = 0;
  auto hipri = [&] {
    // EXPECT_FALSE(tookLopri);
    std::cout << "hi \n";
    std::this_thread::sleep_for(10ms);
    completed++;
  };
  auto lopri = [&] {
    tookLopri = true;
    std::cout << "lo \n";

    completed++;
  };
  auto midpri = [&] { std::cout << "mid \n"; };
  auto pool = std::make_shared<CPUThreadPoolExecutor>(0 /*numThreads*/,
                                                      3 /*numPriorities*/);
  {
    auto loPriExecutor = ExecutorWithPriority::create(
        getKeepAliveToken(pool.get()), Executor::LO_PRI);
    auto hiPriExecutor = ExecutorWithPriority::create(
        getKeepAliveToken(pool.get()), Executor::HI_PRI);
    auto midPriExecutor = ExecutorWithPriority::create(
        getKeepAliveToken(pool.get()), Executor::MID_PRI);

    for (int i = 0; i < 5; i++) {
      loPriExecutor->add(lopri);
    }
    for (int i = 0; i < 2; i++) {
      hiPriExecutor->add(hipri);
    }
    for (int i = 0; i < 2; i++) {
      midPriExecutor->add(midpri);
    }
    pool->setNumThreads(1);
  }
  pool->join();
}
int main(int argc, char* argv[]) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  std::cout << "main " << std::this_thread::get_id() << std::endl;
  folly::SingletonVault::singleton()->registrationComplete();
  futurethen();
  proity();
  futureontime();
  futuremap();
  threadPool.join();
  return 0;
}