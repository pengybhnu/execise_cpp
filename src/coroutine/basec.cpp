#include <coroutine>  // The caller-level type
#include <iostream>
// use each other in cpp, struct contian other for defination

struct Task {
  // The coroutine level type
  struct promise_type {
    int x;
    // Task get_return_object() { return {}; }
    Task get_return_object() { return Task{handle_type::from_promise(*this)}; }
    std::suspend_always initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    // void return_void() {}
    auto return_value(int v) {
      std::cout << "Got an answer of " << v << std::endl;
      x = v;
      //   return std::suspend_never{};
      return std::suspend_always{};
    }
    void unhandled_exception() {}
  };
  using handle_type = std::coroutine_handle<promise_type>;
  handle_type coro;
};
Task myCoroutine() {
  co_return 2;  // make it a coroutine
}
int main() {
  auto x = myCoroutine();
  x.coro.resume();
  auto m = x.coro.promise().x;
  std::cout << "xp " << m << std::endl;

  x.coro.destroy();
}