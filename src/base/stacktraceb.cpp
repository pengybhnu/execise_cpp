#include <iostream>

#include "boost/stacktrace.hpp"

int nested_func(int c) {
  c += 1;
  std::cout << boost::stacktrace::stacktrace() << '\n';
  return c + 1;
}

int func(int b) { return nested_func(b + 1); }

int main() { std::cout << func(777); }