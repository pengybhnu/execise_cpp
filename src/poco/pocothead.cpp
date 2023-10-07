#include <iostream>

#include "Poco/RunnableAdapter.h"
#include "Poco/Thread.h"
#include "Poco/ThreadPool.h"
#include "Poco/Timer.h"
using Poco::Timer;
using Poco::TimerCallback;
class TimerExample {
 public:
  void onTimer(Poco::Timer& timer) {
    std::cout << "onTimer called." << std::endl;
  }
};
class Greeter {
 public:
  void greet() {
    std::cout << "poco" << std::endl;

    Poco::Thread::sleep(2000);
  }
};
int main(int argc, char** argv) {
  Greeter greeter;
  Poco::RunnableAdapter<Greeter> runnable(greeter, &Greeter::greet);
  Poco::Thread thread;
  thread.start(runnable);
  thread.join();

  Poco::Thread thread3;
  thread3.startFunc([]() {
    Poco::Thread::current()->setName("da");
    std::cout << "poco!" << std::endl;
    Poco::Thread::sleep(2000);
  });
  thread3.join();
  auto pool = Poco::ThreadPool(7);
  pool.start(runnable, "poc");
  pool.start(runnable, "poc");
  pool.stopAll();

  TimerExample te;
  Timer timer(250, 500);  // fire after 250ms, repeat every 500ms
  timer.start(TimerCallback<TimerExample>(te, &TimerExample::onTimer));

  Poco::Thread::sleep(5000);
  timer.stop();
  return 0;
}
