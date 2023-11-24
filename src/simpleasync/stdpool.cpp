#include <stdexec/execution.hpp>
#include <exec/static_thread_pool.hpp>

using namespace std::chrono_literals;
int main()
{
    // Declare a pool of 3 worker threads:
    exec::static_thread_pool pool(3);

    // Get a handle to the thread pool:
    auto sched = pool.get_scheduler();

    auto fun = [](int i) { return i*i; };
    auto work = stdexec::when_all(
        stdexec::on(sched, stdexec::just(0) | stdexec::then(fun)),
        stdexec::on(sched, stdexec::just(1) | stdexec::then(fun)),
        stdexec::on(sched, stdexec::just(2) | stdexec::then(fun))
    );

    // Launch the work and wait for the result
    auto [i, j, k] = stdexec::sync_wait(std::move(work)).value();
    std::this_thread::sleep_for(10s);
    // Print the results:
    std::printf("%d %d %d\n", i, j, k);
}