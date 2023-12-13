
#include <iostream>

#include "folly/futures/Future.h"
using namespace folly;
//  using folly::collect;

Future<int> fooFuture(int x) { return x + 2; }
SemiFuture<std::vector<int>> multiFooFuture(std::vector<int> inputs) {
  std::vector<Future<int>> futures;
  for (auto input : inputs) {
    futures.push_back(fooFuture(input));
  }
  return collect(futures);
}

int main(int argc, char* argv[]) {
  std::vector<int> input{1, 2, 3};
  multiFooFuture(input).wait();
  int i = 0;
  auto thunk = [&] { return makeFuture().thenValue([&](auto&&) { i += 1; }); };

  // false
  //   auto f1 = folly::when(false, thunk);
  auto f1 = folly::when(true, thunk);
  f1.wait();
  std::cout << i << std::endl;

  std::vector<Promise<int>> promises(10);
  std::vector<Future<int>> futures;

  for (auto& p : promises) {
    futures.push_back(p.getFuture());
  }

  auto allf = collect(futures);
  return 0;
}