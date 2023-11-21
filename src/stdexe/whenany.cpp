/*
 * Copyright (c) 2021-2022 NVIDIA Corporation
 *
 * Licensed under the Apache License Version 2.0 with LLVM Exceptions
 * (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 *
 *   https://llvm.org/LICENSE.txt
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <iostream>
#include <thread>
// Pull in the reference implementation of P2300:
#include <exec/inline_scheduler.hpp>
#include <exec/on.hpp>
#include <span>
#include <stdexec/execution.hpp>
#include <tbbexec/tbb_thread_pool.hpp>

#include "exec/static_thread_pool.hpp"

using namespace stdexec;
using stdexec::sync_wait;

int main() {
  {
    exec::static_thread_pool ctx{8};
    scheduler auto sch = ctx.get_scheduler();                               // 1
                                                                            //
    sender auto begin = schedule(sch);                                      // 2
    sender auto hi_again = then(                                            // 3
        begin,                                                              // 3
        [] {                                                                // 3
          std::cout << "Hello world! Have an int.\n";                       // 3
          return 13;                                                        // 3
        });                                                                 // 3
                                                                            //
    sender auto add_42 = then(hi_again, [](int arg) { return arg + 42; });  // 4
                                                                            //
    auto [i] = sync_wait(std::move(add_42)).value();                        // 5
    std::cout << "Result: " << i << std::endl;

    // Sync_wait provides a run_loop scheduler
    std::tuple<run_loop::__scheduler> t = sync_wait(get_scheduler()).value();
    (void)t;

    auto y = let_value(get_scheduler(), [](auto sched) {
      return on(sched, then(just(), [] {
                  std::this_thread::sleep_for(std::chrono::seconds(1));
                  std::cout << "from run_loop\n";
                  return 42;
                }));
    });
    sync_wait(std::move(y));
    // stdexec::start_detached(just(y));
    std::cout << "heh" << std::endl;
    sync_wait(when_all(just(42), get_scheduler(), get_stop_token()));
    std::this_thread::sleep_for(std::chrono::seconds(2));
  }
  {
    auto compute = [](int x) -> int { return x + 1; };

    tbbexec::tbb_thread_pool pool(1);

    exec::static_thread_pool other_pool(1);

    // Get a handle to the thread pool:
    auto other_sched = other_pool.get_scheduler();
    // auto tbb_sched = other_pool.get_scheduler();

    // Get a handle to the thread pool:
    auto tbb_sched = pool.get_scheduler();

    exec::inline_scheduler inline_sched;

    using namespace stdexec;

    // clang-format off
    auto work = when_all(
        on(tbb_sched, just(1))    | then(compute) | then(compute),
        on(other_sched, just(0))  | then(compute) | transfer(tbb_sched)   | then(compute),
        on(inline_sched, just(2)) | then(compute) | transfer(other_sched) | then(compute) | transfer(tbb_sched) | then(compute)
    );
 
    auto [i, j, k] = stdexec::sync_wait(std::move(work)).value();
    std::cout << "after sync_wait" << std::endl;
    auto do_first_work = []() { std::cout << "first" << std::endl; };
    auto do_second_work = []() {
      int x = 20;
      x += 100;
      std::cout << "11111second" << std::endl;
    };
    sender auto start2 = split(schedule(other_sched));
    sender auto c3 = stdexec::when_all(then(start2, [&] { do_first_work(); }),
                                       then(start2, [&] { do_second_work(); }));
    start_detached(c3);
  }
  {
    using namespace stdexec;

    auto snd = bulk(just(19), 2, [](int idx, int val) {
      std::cout << "bk " << idx << " " << val << std::endl;
    });
    stdexec::sync_wait(std::move(snd));
  }
}
