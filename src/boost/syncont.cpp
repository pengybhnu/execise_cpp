#include <vector>
#include <thread>

#include "boost/thread/barrier.hpp"
#include "boost/thread/concurrent_queues/sync_deque.hpp"
#include "boost/thread/latch.hpp"
#include "boost/thread/scoped_thread.hpp"
#include "boost/thread/sync_bounded_queue.hpp"
#include "boost/thread/synchronized_value.hpp"
#include "boost/timer/timer.hpp"
#include "fmt/format.h"
#include "fmt/ranges.h"

using namespace std::chrono_literals;
int main(int argc, char* argv[]) {
  boost::timer::auto_cpu_timer t;

  boost::sync_bounded_queue<int> message(6);
  boost::scoped_thread<> writequeue([&]() { message.push_back(1); });
  boost::scoped_thread<> writequeue2([&]() { message.push_back(2); });
  boost::scoped_thread<> rqueue([&]() {
    auto m = message.pull();
    fmt::println("rqueue {}", m);
  });

  boost::synchronized_value<std::vector<int>> ids;
  {
    auto vsyn = ids.synchronize();
    vsyn->push_back(200);
    vsyn->push_back(203);
  }
  {
    auto usyn = ids.try_to_synchronize();
    usyn->push_back(59);
  }

  boost::latch lat(3);
  boost::scoped_thread<> brr([&]() {
    fmt::println("barrier 1-1");
    lat.count_down_and_wait();
    fmt::println("barrier 1-2");
  });
  boost::scoped_thread<> brr2([&]() {
    fmt::println("barrier 2-1");
    lat.count_down_and_wait();
    fmt::println("barrier 2-2");
  });
  boost::scoped_thread<> brr3([&]() {
    fmt::println("barrier 3-1");
    lat.count_down_and_wait();
    fmt::println("barrier 3-2");
  });
  boost::barrier bar(3);

  boost::sync_deque<int> queue;

  boost::scoped_thread<> bqueue(

      [&]() {
        bar.wait();
        fmt::println("queue1 {}", queue.pull_front());
      });
  boost::scoped_thread<> bqueue2(

      [&]() {
        bar.wait();
        fmt::println("queue2 {}", queue.pull_front());
      });
  queue.push_back(56);
  queue.push_back(89);
  bar.wait();
  std::this_thread::sleep_for(2s);
  fmt::println("escaple {}", t.format_string());
  boost::shared_ptr<int> p = boost::make_shared<int>(100);
  return 0;
}