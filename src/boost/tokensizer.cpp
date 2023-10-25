#include <boost/tokenizer.hpp>
#include <iostream>
#include <string>

#include "fmt/format.h"
#include "fmt/ranges.h"
using tokenizer = boost::tokenizer<boost::char_separator<char>>;
std::vector<std::string> Topictokenizer(const std::string &str) {
  boost::char_separator<char> sep("/");
  tokenizer tokens(str, sep);
  std::vector<std::string> re(tokens.begin(), tokens.end());
  return re;
}

int main() {
  std::string str = " /devices/dispatch/|dada_truckid||//jijdad";

  boost::char_separator<char> sep(" /|");
  tokenizer tokens(str, sep);
  for (auto p : tokens) {
    std::cout << "<" << p << "> ";
  }
  std::vector<std::string> re(tokens.begin(), tokens.end());
  fmt::println("re {}", re);

  std::string topic = "/devices/dispatch/dada_truckid/jijdad";

  fmt::println("topic {}", Topictokenizer(topic));

  return EXIT_SUCCESS;
}
