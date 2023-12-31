#include "fmt/format.h"
#include "fmt/ranges.h"
#include "folly/Expected.h"
#include "folly/FBString.h"
#include "folly/FBVector.h"
#include "folly/FixedString.h"
#include "folly/Function.h"
#include "folly/Optional.h"
#include "folly/ProducerConsumerQueue.h"
#include "folly/ScopeGuard.h"
#include "folly/Synchronized.h"
#include "folly/UTF8String.h"
#include "folly/dynamic.h"
#include "folly/small_vector.h"
int main(int argc, char* argv[]) {
  {
    folly::Synchronized<std::string, std::shared_mutex> syn_name;
    syn_name.withWLock([](auto& x) {
      x = "write";
      fmt::println("name {}", x);
    });

    syn_name.withRLock(
        [](const auto& name) { fmt::println("r1 name {}", name); });

    {
      auto write = syn_name.wlock();
      write->append(" cidi complete");
    }
    {
      auto read = syn_name.rlock();
      fmt::println("len {0} {1}", read->size(), *read);
    }
  }

  {
    folly::FixedString<60> name{"read name"};
    name.append(" cidi complete");
    name = "best station";
    // name.append(" cidi complete");
    fmt::println("FixedString {0} {1} {2}", name.length(), name.size(),
                 name.toStdString());
  }
  {
    folly::fbvector<int> fbint{90, 100, 256, 300};

    fmt::println("fbvec {}", fbint);
  }
  {
    // folly::Expected<int, std::string> exp = 9;
    folly::Expected<int, std::string> exp =
        folly::makeUnexpected(std::string("voer"));
    auto f = exp.then([](auto& x) { return 20; }).then([](auto& y) {
      return std::string{"good"};
    });
    if (f.hasValue()) {
      fmt::println("has {}", f.value());
    }
  }
  {
    folly::small_vector<int, 6, folly::small_vector_policy::NoHeap> smallv{
        56, 59, 59, 99, 100};
    // smallv.emplace_back(26);
    // smallv.emplace_back(26);
    // smallv.reserve(10);
  }
  {
    folly::small_vector<int, 5> smallv{56, 59, 59, 99, 100};
    smallv.emplace_back(26);  // push to heap
    // smallv.emplace_back(26);
    smallv.reserve(10);
  }
  {
    folly::Optional<int> p = 20;
    folly::Function<int(int)> f = [p](int i) {
      if (p.hasValue()) {
        return p.value() * i;
      }
      return i * i;
    };
    folly::Function<int(int)> f2 = std::move(f);
    // std::function<int(int)> stdf = f2;
    fmt::println("func {}", f2(2));
  }
  {
    folly::dynamic varf;
    varf = 12;
    fmt::println("var {}", varf.typeName());
    varf = std::string("nm");
    fmt::println("var {}", varf.typeName());
    varf = folly::fbstring{"d"};
    fmt::println("var {}", varf.typeName());

    // switch (varf.type()) {

    // }
  }
  {
    int init = 0;
    {
      auto gd = folly::makeGuard([&]() { init += 1; });
      fmt::println("inter {}", init);
      // gd.dismiss();
      gd.rehire();
    }
    fmt::println("out {}", init);
  }
  return 0;
}