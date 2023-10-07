#include "taskflow/taskflow.hpp"
// #include <function>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;
// class FlowPool{
//     tl::Executor executor;

// };

int main(int argc, char *argv[]) {
  tf::Executor executor;
  std::function<void(int x)> add = [](int x) {
    std::cout << "async task 1 returns 1\n " << x;
  };

  // create asynchronous tasks from the executor
  // (using executor as a thread pool)
  std::future<int> fu = executor.async([]() {
    std::cout << "async task 1 returns 1\n";
    return 1;
  });

  executor.silent_async([]() { // silent async task doesn't return
    std::cout << "async task 2 does not return (silent)\n";
  });

  // create asynchronous tasks with names (for profiling)
  executor.async("async_task", []() {
    std::cout << "named async task returns 1\n";
    return 1;
  });
  {
    auto fts = std::make_shared<tf::Taskflow>();

    auto [A, B, C] = fts->emplace(
        [] {
          std::cout << "1,find route" << std::endl;
          std::this_thread::sleep_for(300ms);
        },
        [] { std::cout << "2,get same station " << std::endl; },
        [] { std::cout << "3,get best station " << std::endl; });
    A.precede(B);
    auto D = fts->emplace([](tf::Subflow &sub) {
      auto [A, B, C] = sub.emplace(
          [] {
            std::cout << " S1,find routes" << std::endl;
            std::this_thread::sleep_for(300ms);
          },
          [] { std::cout << " S2,get avalib station " << std::endl; },
          [] { std::cout << " S3,get target station " << std::endl; });
      A.precede(B);
      C.succeed(B);
    });
    D.succeed(B);
    C.succeed(D);

    executor.silent_async(

        [flow = fts, &executor, i = 0]() { executor.run(*flow).wait(); });
  }
  std::this_thread::sleep_for(2s);

  tf::Taskflow taskflow;
  auto [init, cond, yes, no] =
      taskflow.emplace([]() { std::cout << "init "; },
                       []() {
                         std::cout << "cond ";
                         return 1;
                       },
                       []() { std::cout << "cond returns 0"; },
                       []() { std::cout << "cond returns 1"; });

  cond.succeed(init).precede(yes, no);

  executor.run(taskflow).wait();

 
  std::this_thread::sleep_for(3s);
}
