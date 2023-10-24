#define _USE_MATH_DEFINES
#include <bit>
#include <boost/variant2/variant.hpp>
#include <cmath>
#include <iostream>
#include <vector>
using namespace boost::variant2;

struct Rectangle {
  double width_, height_;
  double area() const { return width_ * height_; }
};

struct Circle {
  double radius_;
  double area() const { return M_PI * radius_ * radius_; }
};

double total_area(std::vector<variant<Rectangle, Circle>> const& v) {
  double s = 0.0;

  for (auto const& x : v) {
    s += visit([](auto const& y) { return y.area(); }, x);
  }

  return s;
}

class Baseeq {
 public:
  bool operator==(Baseeq const& other) const { return i_ == other.i_; }
  explicit operator bool() const { return i_ != 0; }
  Baseeq(int i) : i_(i) {}

 private:
  int i_;
};

int main() {
  std::vector<variant<Rectangle, Circle>> v;

  v.push_back(Circle{1.0});
  v.push_back(Rectangle{2.0, 3.0});
  auto& cir = v[0];
  // visit([&](Circle const& y) { std::cout << "circle " << y.area() <<
  // std::endl; },
  //       v[0]);
  std::cout << "Total area: " << total_area(v) << std::endl;
  float f = 123.0;
  int i = std::bit_cast<int>(f);

  Baseeq b(0);
  Baseeq ba(1);
  if (b) {
    // cout not zero
    std::cout << "not zero" << std::endl;

  } else {
    std::cout << "zero" << std::endl;
  }
  if (ba) {
    // cout not zero
    std::cout << "not zero" << std::endl;

  } else {
    std::cout << "zero" << std::endl;
  }
}