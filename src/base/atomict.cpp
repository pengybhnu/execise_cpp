#include <atomic>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>

int main(int argc, char* argv[]) {
  std::atomic<int> num{2};
  std::cout << "start\n";
  std::mutex mt;
  std::condition_variable cond;
  std::thread t1([&]() {
    volatile int lv;
    lv = num.load();
    std::cout << lv << std::endl;
    std::unique_lock<std::mutex> lk(mt);
    cond.wait(lk);
    std::cout << "wait\n";
  });
  std::thread t2([&]() {
    std::cout << num.load() << std::endl;
    num.store(9);
    // mt.try_lock();
    // std::unique_lock<std::mutex> lk(mt);
    // cond.wait(lk);
    std::cout << "again wait\n";
  });
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::thread t3([&]() {
    // std::this_thread::sleep_for(std::chrono::seconds(10));
    for (uint32_t i = 0; i < 3000000000; i++) {
      if (i%1000000 == 0) {
      std::cout << "r ";  // mt.unlock();
      
      }
    }
    std::cout << "post\n";  // mt.unlock();
    // cond.notify_one();
        for (uint32_t i = 0; i < 3000000000; i++) {
      if (i%1000000 == 0) {
      std::cout << "r ";  // mt.unlock();
      
      }
    }
    // cond.notify_one();

  });
  t1.join();
  t2.join();
  t3.join();

  return 0;
}