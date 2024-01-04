#include <iostream>
#include <unordered_map>

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
  std::cout << "--------------------" << std::endl;

  std::unordered_map<int, std::string> kys;
  auto itmi = kys.emplace(1, "da");
    if (itmi.second) {
    std::cout << itmi.first->first << std::endl;
  } else {
    std::cout << "fail emp" << std::endl;
  }
  auto itm = kys.emplace(1, "dump2");
  if (itm.second) {
    std::cout << itm.first->first << std::endl;
  } else {
    std::cout << "fail emp" << std::endl;
  }
  auto iti = kys.insert({1, "dump area"});
  if (iti.second) {
    std::cout << iti.first->first << std::endl;
  } else {
    std::cout << "fail insert" << std::endl;
  }
  for (auto& key : kys) {
    std::cout << key.first << " " << key.second << std::endl;
  }

  return 0;
}
