#include <vector>

#include "boost/thread/scoped_thread.hpp"
#include "fmt/format.h"
#include "fmt/ranges.h"
#include "folly/AtomicHashMap.h"
#include "folly/ConcurrentSkipList.h"
#include "folly/Expected.h"
#include "folly/FBString.h"
#include "folly/ProducerConsumerQueue.h"
#include "folly/Synchronized.h"
#include "folly/concurrency/DynamicBoundedQueue.h"

using namespace std::chrono_literals;
using namespace std::string_view_literals;
int main(int argc, char* argv[]) {
  folly::Synchronized<std::string, std::shared_mutex> syn_name;
  folly::Synchronized<std::vector<int>, std::shared_mutex> syn_vec;
  boost::thread write([&]() {
    syn_name.withWLock([](auto& x) {
      x = "write";
      fmt::println("name {}", x);
    });
  });
  write.join();
  std::this_thread::sleep_for(1000ms);
  {
    folly::fbstring fbname;
    fbname.append("read name");
    auto lname = syn_name.wlock();
    *lname = fbname.toStdString();
  }

  boost::strict_scoped_thread<> read((boost::thread([&]() {
    syn_name.withRLock(
        [](const auto& name) { fmt::println("r1 name {}", name); });
  })));
  boost::scoped_thread<> read2([&]() {
    syn_name.withRLock(
        [](const auto& name) { fmt::println("r2 name {}", name); });
  });
  boost::scoped_thread<> read3([&]() {
    syn_vec.withWLock([](auto& vec) {
      vec.reserve(10);
      vec.emplace_back(1);
      vec.emplace_back(2);
      vec.emplace_back(5);
    });
  });
  std::this_thread::sleep_for(2s);

  boost::scoped_thread<> writevec([&]() {
    syn_vec.withRLock([](const auto& vec) { fmt::println("vec {}", vec); });
  });

  folly::ProducerConsumerQueue<int> csqueue(10);

  boost::scoped_thread<> readqueue([&]() {
    bool state = false;
    while (!state) {
      int one;
      state = csqueue.read(one);
      if (state) {
        fmt::println("one {}", one);
        if (one < 300) {
          state = false;
        }
      }
    }
  });
  boost::scoped_thread<> writequeue([&]() {
    csqueue.write(200);
    csqueue.write(203);
    csqueue.write(302);
  });
  std::this_thread::sleep_for(2s);

  folly::Expected<int, std::string> reason =
      3;  //= folly::makeUnexpected<std::string>("failed");

  auto r2 = reason.then([](auto& v) {
    fmt::println("reason {}", v);
    auto r2 = folly::makeUnexpected<std::string>("failed");
    // return r2;
  });

  {
    folly::DynamicBoundedQueue<int, true, true, true> queue(4);
    queue.try_enqueue(20);
    queue.try_enqueue(20);
    queue.try_enqueue(20);
    queue.try_enqueue(20);
    boost::scoped_thread<> t1([&queue]() {
      int x;
      queue.dequeue(x);
      std::this_thread::sleep_for(std::chrono::seconds(1));
      fmt::println("dequeue {}", x);
    });
    boost::scoped_thread<> t2([&queue]() {
      queue.enqueue(20);
      fmt::println("enqueue");
      queue.try_enqueue(20);
      queue.try_enqueue(20);
      queue.try_enqueue(20);
    });
  }
  return 0;
}