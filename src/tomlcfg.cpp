#include <iostream>
#include <optional>
#include <sstream>

#include "toml.hpp"
using namespace std::string_view_literals;
class Table {
 public:
  std::string name;
  double value;
};
int main() {
  static constexpr std::string_view some_toml = R"(
        [library]
        name = "toml++"
        authors = ["Mark ","cidi"]
        cpp = 17
    )"sv;

  try {
    // parse directly from a string view:
    {
      toml::parse_result tbl = toml::parse(some_toml);
      std::cout << tbl << "\n";
    }

    // parse from a string stream:
    {
      std::stringstream ss{std::string{some_toml}};
      toml::table tbl = toml::parse(ss);
      // std::cout << tbl << "\n";
      std::cout << "library.name " << tbl["library"]["name"] << "\n";
      std::cout << "library.authors " << tbl.at_path("library.authors")[0]
                << "\n";
      auto authors = tbl["library"]["authors"].as_array();

      authors->for_each([](auto &&el) {
        if constexpr (toml::is_number<decltype(el)>)
          (*el)++;
        else if constexpr (toml::is_string<decltype(el)>)
          std::cout << "library.author " << el << "\n";
      });
    }
  } catch (const toml::parse_error &err) {
    std::cerr << "Parsing failed:\n" << err << "\n";
    return 1;
  }
  auto tbl = toml::table{
      {"lib", "toml++"},
      {"cpp", toml::array{17, 20, "and beyond"}},
      {"toml", toml::array{"1.0.0", "and beyond"}},
      {"repo", "https://github.com/marzer/tomlplusplus/"},
      {"author", toml::table{{"name", "Mark Gillard"},
                             {"github", "https://github.com/marzer"},
                             {"twitter", "https://twitter.com/marzer8789"}}},
  };

  // serializing as TOML
  std::cout << "###### TOML ######"
            << "\n\n";
  std::cout << tbl << "\n\n";

  // serializing as JSON using toml::json_formatter:
  std::cout << "###### JSON ######"
            << "\n\n";
  std::cout << toml::json_formatter{tbl} << "\n\n";

  // serializing as YAML using toml::yaml_formatter:
  std::cout << "###### YAML ######"
            << "\n\n";
  std::cout << toml::yaml_formatter{tbl} << "\n\n";

  Table t1{.name = tbl["lib"].value<std::string>().value(),
           .value = tbl["cpp"][8].value<double>().value_or(3.69)};
  std::cout << " " << t1.name << ":" << t1.value << std::endl;
  auto repo = tbl["repo"].value<std::string>();
  auto result = repo.transform([](auto v) -> std::optional<int> {
                      std::cout << "repo: " << v << std::endl;
                      return {};
                    })
                    .transform([](auto v) -> std::optional<int> {
                      std::cout << "int: " << v.value_or(56) << std::endl;
                      if (v.has_value()) {
                        return {59};
                      }else {
                      return {5023};
                      }
                    })
                    ->and_then([](auto v) -> std::optional<std::string_view> {
                      std::cout << "int: " << v << std::endl;
                      return {"ok"};
                    });

  std::cout << "repo: " << result.value_or("null") << std::endl;
  return 0;
}