
#include <coroutine>
#include <functional>
#include <iostream>
using namespace std;

template <typename T>
class generator {
 public:
  struct promise_type {
    T t_;
    bool returned_with_value_{false};

    promise_type() = default;
    ~promise_type() = default;

    std::suspend_always initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    void unhandled_exception() {}
    generator get_return_object() {
      return {std::coroutine_handle<promise_type>::from_promise(*this)};
    }

    std::suspend_always yield_value(T t) {
      t_ = t;
      return {};
    }
    void return_value(T t) {
      t_ = t;
      returned_with_value_ = true;
    }
    // void return_void() {}
  };

 private:
  std::coroutine_handle<promise_type> h_;

  auto& promise() { return h_.promise(); }

 public:
  generator(std::coroutine_handle<promise_type> h) : h_(h) {}
  ~generator() = default;

  bool operator()() {
    if (promise().returned_with_value_)  // From previous operator() call
    {
      h_.destroy();
      return false;
    }

    h_();

    if (!promise().returned_with_value_ && h_.done()) {
      h_.destroy();
      return false;
    } else {
      return true;
    }
  }

  [[nodiscard]] const T& get() const { return h_.promise().t_; }

  operator const T&() const { return get(); }
};

generator<int> foo() {
  int i = 0;

  while (1) {
    co_yield (i++);
    if (i == 100) co_return i;
  }
}

int main() {
  auto handle = foo();

  while (handle()) {
    cout << "val: " << handle.get() << endl;
  }

  return 0;
}

struct Info{
  std::string name;
  int num;
};