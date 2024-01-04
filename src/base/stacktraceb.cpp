#include <iostream>

#include "boost/stacktrace.hpp"

int nested_func(int c) {
  c += 1;
  volatile int m = c - 9;
  std::cout << m << '\n';
  // std::cout << boost::stacktrace::stacktrace() << '\n';
  boost::stacktrace::stacktrace trace;  // Capture the stack trace

  std::cout << boost::stacktrace::to_string(trace)
            << std::endl;  // Print the stack trace

  return c + 1;
}

int func(int b) { return nested_func(b + 9); }

int main() {
  volatile int result = func(777);
  return 0;
}