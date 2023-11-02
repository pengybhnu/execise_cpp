#include <memory>

#include "fmt/format.h"
#include "fmt/ranges.h"
#include "serdepp/adaptor/fmt.hpp"
#include "serdepp/adaptor/nlohmann_json.hpp"
#include "serdepp/adaptor/rapidjson.hpp"
#include "serdepp/adaptor/reflection.hpp"
#include "serdepp/adaptor/toml11.hpp"
#include "serdepp/adaptor/yaml-cpp.hpp"
#include "serdepp/serde.hpp"

enum class tenum { INPUT, OUTPUT, INPUT_2, OUTPUT_2 };

struct nested {
  DERIVE_SERDE(nested, (&Self::version, "version", value_or_struct)(
                           &Self::opt_desc,
                           "opt_desc")[attributes(default_{"default value"})](
                           &Self::desc, "desc")
                           .no_remain())
  std::string version;
  std::string desc;
  std::optional<std::string> opt_desc;
};

class test {
 public:
  DERIVE_SERDE(test, [attributes(default_{"hello"})](&Self::str, "str")(
                         &Self::i, "i")(&Self::vec, "vec")
                         [attributes(default_{tenum::OUTPUT}, to_lower, under_to_dash)](
                         &Self::io, "MyIo")
                         [attributes(make_optional)](&Self::in, "in")
                         [attributes(to_upper, under_to_dash)](&Self::pri, "pri")
                         (&Self::m, "m")
                         (&Self::nm, "nm"))
  std::optional<std::string> str;
  int i;
  std::optional<std::vector<std::string>> vec;
  tenum io;
  std::vector<nested> in;
  std::map<std::string, std::string> m;
  std::map<std::string, nested> nm;
  std::string pri;
};

struct A {
  DERIVE_SERDE(A, _SF_(a) _SF_(b) _SF_(c) _SF_(d) _SF_(e))
  int a;
  std::string b;
  double c;
  std::vector<int> d;
  int e;
};

int main() {
  nlohmann::json v = R"({
    "i": 10,
    "vec": [ "one", "two", "three" ],
    "io" : "OUTPUT-2",
    "pri" : "PRi-FF",
    "in" : [{ "version" : "hello" }, "single"],
    "m" : { "a" : "1",
            "b" : "2",
            "c" : "3" },
    "nm" : { "a" : {"version" : "hello" },
             "b" : "hello2" }
    })"_json;

  // try {

  test t = serde::deserialize<test>(v);
  fmt::print("{}\n", serde::to_str(t.io));

  YAML::Node y = serde::serialize<YAML::Node>(10);
  std::cout << y << "\n";
  serde::deserialize<int>(y);

  auto v_to_json = serde::serialize<nlohmann::json>(t);
  auto v_to_toml = serde::serialize<serde::toml_v>(t);
  auto v_to_yaml = serde::serialize<serde::yaml>(t);
  auto v_to_rjson = serde::serialize<rapidjson::Document>(t);
  auto print = [](auto& doc) {
    using namespace rapidjson;
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    doc.Accept(writer);
    std::cout << "doc:" << buffer.GetString() << std::endl;
  };
  v_to_json.dump();
  auto sertom = toml::format(v_to_toml,0,std::numeric_limits<double>::max_digits10,true,true);
  
  std::cout << "toml: " << sertom .size() << " "<< v_to_toml << std::endl;
  std::cout << "toml: " << sertom << std::endl;
  fmt::print("json: {}\n", v_to_json.dump());
  std::cout << "yaml: " << v_to_yaml << std::endl;
  print(v_to_rjson);

  test t_from_toml = serde::deserialize<test>(v_to_toml);
  test t_from_yaml = serde::deserialize<test>(v_to_yaml);
  test t_from_rjson = serde::deserialize<test>(v_to_rjson);

  fmt::print("{}\n", t_from_toml);
  fmt::print("{}\n", t_from_yaml);
  fmt::print("{}\n", t_from_rjson);
  std::cout << t << '\n';

  {
    constexpr auto info = serde::type_info<A>;

    static_assert(serde::type_info<A>.size == 5);
    static_assert(serde::tuple_size_v<A> == 5);
    static_assert(std::is_same_v<
                  serde::to_tuple_t<A>,
                  std::tuple<int, std::string, double, std::vector<int>, int>>);
    static_assert(
        std::is_same_v<int, std::tuple_element_t<0, serde::to_tuple_t<A>>>);

    auto a = A{1, "hello", 3., {1, 2}, 2};

    auto to_tuple = serde::make_tuple(a);

    std::string& member_a = info.member<1>(a);
    member_a = "why";

    double& member_b_info = info.member<double>(a, "c");
    member_b_info = 3.14;

    auto member_d_info = info.member_info<3>(a);
    std::string_view member_d_name = member_d_info.name();
    std::vector<int>& member_d = member_d_info.value();

    auto names = info.member_names();
    for (auto& name : names.members()) {
      std::cout << name << "\n";
    }

    return 0;
  }
}