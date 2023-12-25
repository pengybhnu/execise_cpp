#include <string.h>

#include <iostream>
#include <memory>

#include "http.pb.h"

int main(int argc, char* argv[]) {
  example::Point p;
  auto p2 = new example::Point();
  std::atomic<int> p3;
  p.set_m(1.9);
  p.set_y(10.03);
  //   p.mutable_z()->Clear();
  p.mutable_z()->set_name("p1");
  p.mutable_z()->set_num(10);
  example::Get g;
  //   g.CopyFrom(p); // error runtime
  //   g = *(reinterpret_cast<example::Get*>(&p));
  memcpy(&g, &p, sizeof(p));  // with mutable_z() segment fault
  std::cout << sizeof(p) << std::endl;
  std::cout << sizeof(p2) << std::endl;
  std::cout << sizeof(p3) << std::endl;
  std::cout << p.GetCachedSize() << std::endl;

  std::cout << g.DebugString();
  std::unique_ptr<example::Point> np(p2);
  auto p4 = np.release();
  delete p4;
  auto gz = g.release_z();
  // delete gz;
  example::Infos infos;
  for (auto& p : {1, 2, 3}) {
    auto ps = infos.add_points();
    ps->set_m(3);
  }
  auto& pp = infos.points();
  std::cout<< "p size " << pp.size() << std::endl;
  infos.clear_points();
  std::cout<< "p size " << pp.size() << std::endl;
  std::cout<< "infop size " << infos.points().size() << std::endl;
  return 0;
}