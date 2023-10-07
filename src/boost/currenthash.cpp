#include <iostream>
#include <string>
#include <thread>

#include "boost/unordered/concurrent_flat_map.hpp"
#include "boost/unordered/unordered_flat_map.hpp"
#include "boost/unordered/unordered_node_set.hpp"

int main(int argc, char* argv[]) {
  boost::unordered::concurrent_flat_map<int, std::string> maps;
  std::vector<std::thread> threads;
  for (auto i : {1, 2, 3, 4}) {
    std::thread f([&maps, i]() { maps.emplace(i, "station"); });
    threads.emplace_back(std::move(f));
  }
  for (auto& t : threads) {
    t.join();
  }
  maps.visit(1, [](auto& value) { value.second = "shovel"; });
  maps.cvisit(1, [](auto value) { std::cout << value.second << std::endl; });
  maps.cvisit_all([](auto& content) {
    std::cout << content.first << " " << content.second << std::endl;
  });
  boost::unordered::unordered_flat_map<int, char> randchar{
      {1, 'b'}, {3, 'c'}, {4, 'd'}};

  if (randchar.contains(1)) {
    std::cout << randchar[1] << std::endl;
  } else {
    randchar.emplace(8, 'f');
  }
  randchar.try_emplace(8, 'f');
  for (auto& [key, value] : randchar) {
    std::cout << key << " " << value << std::endl;
  }
  return 0;
}