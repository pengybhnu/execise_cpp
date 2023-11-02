#include <folly/executors/CPUThreadPoolExecutor.h>
#include <folly/futures/Future.h>

#include <iostream>

#include "gflags/gflags.h"

int main(int argc, char* argv[]) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  std::cout << "main " << std::this_thread::get_id() << std::endl;

  folly::CPUThreadPoolExecutor threadPool(3);   // max threads
  folly::CPUThreadPoolExecutor threadother(2);  // max threads

  // Submit tasks to the CPU thread pool for execution
  folly::Future<int> future1 = folly::via(&threadPool, []() {
    std::cout << "Task 1 executed in CPU thread pool" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::this_thread::sleep_for(std::chrono::seconds(5));

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
    std::this_thread::sleep_for(std::chrono::seconds(5));

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
    std::this_thread::sleep_for(std::chrono::seconds(10));
    return 100;
  });
  folly::Future<void*> notr = folly::via(&threadother, []() -> void* {
    std::cout << "Task notr " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(8));
    return nullptr;
  });

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
      .thenValue([](std::string result) {
        std::cout << "Task 3 result then2: " << std::this_thread::get_id()
                  << " " << result << std::endl;
        return std::string{"getv2"};
      })
      .thenTry([](folly::Try<std::string> strTry) {
        std::cout << "try " << strTry.value() << std::endl;
        // try {
        //   int* a = nullptr;
        //   *a = 200;
        // } catch (std::exception const& e) {
        // }
      })
      .thenError(folly::tag_t<std::exception>{}, [](std::exception const& e) {
        std::cerr << "get " << e.what() << std::endl;
      });
  std::this_thread::sleep_for(std::chrono::seconds(10));

  if (true) {
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
  return 0;
}