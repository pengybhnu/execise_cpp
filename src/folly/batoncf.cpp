#include <iostream>
#include <thread>

#include "folly/synchronization/Baton.h"
using std::chrono_literals::operator""s;
int main(int argc, char* argv[]) {
    std::cout << "sss>>>>>>>>>> s" << std::endl;

  folly::Baton<> baton;
  volatile  int m;
    std::cout << "fff>>>>>>>>>> s" << std::endl;

  std::thread t([&] {
    // b1.post();
    std::cout << ">>>>>>>>>>bnum" << std::endl;
    volatile int x = 1;
    m = x+8;
    std::this_thread::sleep_for(1s);
    baton.post();
    std::cout << "post------------" << std::endl;

  });
//   baton.wait();
baton.try_wait_for(5s);
  std::cout << "after";
  m = m +200;
  t.join();
  return m;
}