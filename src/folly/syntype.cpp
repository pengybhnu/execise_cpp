#include <folly/MPMCPipeline.h>

#include <vector>

#include "boost/thread/scoped_thread.hpp"
#include "fmt/format.h"
#include "fmt/ranges.h"
#include "folly/AtomicHashMap.h"
#include "folly/ConcurrentSkipList.h"
#include "folly/Expected.h"
#include "folly/FBString.h"
#include "folly/PackedSyncPtr.h"
#include "folly/ProducerConsumerQueue.h"
#include "folly/Synchronized.h"
#include "folly/SynchronizedPtr.h"
#include "folly/concurrency/DynamicBoundedQueue.h"
#include "folly/executors/task_queue/PriorityLifoSemMPMCQueue.h"
#include "folly/executors/task_queue/UnboundedBlockingQueue.h"
#include "folly/portability/GTest.h"
#include "folly/synchronization/Baton.h"
#include "range/v3/view/all.hpp"
#include "range/v3/view/iota.hpp"

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
  {
    folly::PriorityLifoSemMPMCQueue<int, folly::QueueBehaviorIfFull::THROW>
        queue(3, 10);
    queue.addWithPriority(1001, 0);
    queue.addWithPriority(2, 0);
    queue.addWithPriority(191, 1);
    queue.addWithPriority(14, 1);
    queue.addWithPriority(115, 2);
    queue.addWithPriority(112, 2);
    std::cout << "num " << queue.getNumPriorities() << "\n";
    std::cout << "num " << queue.take() << " ";
    std::cout << "num " << queue.take() << " ";
    std::cout << "num " << queue.take() << " ";
    // for (const auto& i :  ranges::views::iota(0, 10)) {

    // }
  }
  {
    folly::UnboundedBlockingQueue<int> q;
    folly::Baton<> b1, b2;
    std::thread t([&] {
      // b1.post();
      std::cout << "bnum " << q.take() << " ";
      b2.post();
    });
    // b1.wait();
    q.add(42);
    b2.wait();
    t.join();
  }
  {
    folly::SynchronizedPtr<std::shared_ptr<int>> pInt{std::make_shared<int>(0)};
    pInt.withWLock([](auto&& value) { value = 20.0; });
    pInt.wlockPointer()->reset(new int(200));

    pInt.withRLock([](auto&& value) { fmt::println("\n---- p {}", value); });

    folly::PackedSyncPtr<int> packint;
    packint.init(new int(20));
    packint.lock();
    packint.get();
  }

  {
    folly::MPMCPipeline<int> pline(20);

    boost::scoped_thread<> read([&pline]() {
      int x;
      pline.blockingRead(x);
      fmt::println("read1 {}", x);
      pline.blockingRead(x);
      fmt::println("read2 {}", x);
    });

    boost::scoped_thread<> write([&pline]() {
      int x;
      pline.blockingWrite(200);
      pline.blockingWrite(202);
      pline.blockingWrite(369);
    });
  }

  return 0;
}