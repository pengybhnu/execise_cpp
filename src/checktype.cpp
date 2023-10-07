
#include <concepts>
#include <string>
template <typename T>
concept has_string_data_member = requires(T v) {
  // { v.name_ } -> std::convertible_to<std::string>;
  { v.name_ } -> std::convertible_to<std::string>;
};

struct Person {
  int age_{0};
  std::string name_;
};

struct Box {
  double weight_{0.0};
  double volume_{0.0};
};
template <class T>
concept has_id_member = requires(T v) {
  { v.id_ } -> std::convertible_to<uint32_t>;
};
class Point {
 public:
  uint32_t id_;
};
class Geoe {
 public:
  uint32_t serial_;
  std::string id_;
};
template <class T>
requires(has_id_member<T>) uint32_t GetId(T v) { return v.id_; };

int main() {
  static_assert(has_string_data_member<Person>);
  static_assert(!has_string_data_member<Box>);
  Point p{90};
  Geoe p2{.serial_ = 3, .id_ = "da"};
  auto id = GetId(p);
  // error
  //   auto id2 = GetId(p2);
}
