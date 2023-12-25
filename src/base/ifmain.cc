#include <iostream>

#include "base/if.h"
struct T1 {};
template <class T, class Tag = T1>
int& Create() {
  static int i = sizeof(T);
  return i;
}

int main(int argc, char* argv[]) {
  Pif p;
  p.Set(1);
  std::cout << p.Get() << " ";
  p.Set(2);
  std::cout << p.Get() << " ";
  p.Set(3);
  std::cout << p.Get() << " ";
  p.Set(4);
  std::cout << p.Get() << " ";
  p.Set(13);
  std::cout << p.Get() << " ";
  p.Set(501);
  std::cout << p.Get() << " ";

  using tp = std::conditional_t<false, bool, std::string>;
  tp a = {"dada"};
  std::cout << a << " " << std::endl;

  using Bp = std::conditional_t<true, bool, std::string>;
  auto& t = Create<int>();
  std::cout << " " << Create<int>() << " ";
  t = 200;

  std::cout << " " << Create<int>() << " ";
  std::cout << " " << Create<std::string>() << " ";
  return 0;
}
