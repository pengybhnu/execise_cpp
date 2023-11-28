#include <folly/Singleton.h>
#include <folly/executors/GlobalExecutor.h>
#include <folly/experimental/coro/BlockingWait.h>
#include <folly/experimental/coro/Task.h>
#include <folly/futures/Future.h>
#include <folly/portability/GTest.h>
using namespace folly::coro;

Task<int> co_generateFortyTwo() { co_return 42; }

Task<int> co_answerToLife() {
  int answer = co_await co_generateFortyTwo();
  co_return answer;
}

int main(int argc, char* argv[]) {
  folly::SingletonVault::singleton()->registrationComplete();
  auto executor = folly::getGlobalCPUExecutor().get();
  int lit1 = blockingWait(co_answerToLife().scheduleOn(executor));
  std::cout << lit1 << "\n";
  int a = 29;
  auto t1 = makeTask(5);

  auto r1 = blockingWait(std::move(t1).scheduleOn(executor));
  std::cout << r1 << "\n";

  return 0;
}