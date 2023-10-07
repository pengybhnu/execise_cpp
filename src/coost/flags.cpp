
// xx.cc
#include "co/co.h"
#include "co/cout.h"
#include "co/flag.h"
#include "co/log.h"
#include "co/time.h"
#include "co/tasked.h"

DEF_bool(x, false, "x");
DEF_bool(y, false, "y");
DEF_bool(debug, false, "dbg", d);
DEF_uint32(u, 0, "xxx");
DEF_string(s, "", "xx");
using namespace std::chrono_literals;
int main(int argc, char** argv) {
  flag::parse(argc, argv);
  cout << "x: " << FLG_x << '\n';
  cout << "y: " << FLG_y << '\n';
  cout << "debug: " << FLG_debug << '\n';
  cout << "u: " << FLG_u << '\n';
  cout << FLG_s << "|" << FLG_s.size() << '\n';
  cout << text::red("hello\n");
  cout << text::green("hello\n");
  cout << text::blue("hello\n");
  cout << text::yellow("hello\n");
  cout << text::magenta("hello\n");
  cout << text::cyan("hello\n");
  cout << "hello\n";
  cout << text::bold("hello\n");
  cout << text::bold("hello\n").red();
  cout << text::bold("hello\n").green();
  cout << text::bold("hello\n").blue();
  cout << text::bold("hello\n").yellow();
  cout << "\n" << std::endl;

  // TLOG("xx") << "s" << 23;  // topic log
  DLOG << "log lo " << 23;  // debug
  LOG << "log lo " << 23;   // info
  WLOG << "log lo " << 23;  // warning
  ELOG << "log lo " << 23;  // error
                            // FLOG << "log lo " << 23;   // fatal

  co::wait_group wg;
  wg.add(2);

  go([wg]() {
    LOG << "hello world";
    wg.done();
  });

  go([wg]() {
    LOG << "hello again";
    std::this_thread::sleep_for(4s);
    wg.done();
  });

  wg.wait();
  // auto f = []() { co::print("f lamda"); };
  // co::Tasked s;
  // s.run_in(f, 0);
  // s.run_in(f, 1);
  // s.run_in(f, 2);
  // s.run_in(f, 0);
  // s.run_every(
  //     [i = 0]() mutable {
  //       i++;
  //       co::print("every lamda {}", i);
  //     },
  //     3);
  // sleep::sec(7);
  // s.stop();
  return 0;
}
