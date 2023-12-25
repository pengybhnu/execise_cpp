
struct P {
  double x;
  double y;
};

int main(int argc, char* argv[]) {
  const P* p = new P{.x = 200};
  // p->y = 2000; // Cannot assign to variable 'p' with const-qualified type
  // 'const P *
  p = new P{.x = 300};
  delete p;
  P* const p2 = new P{.x = 200,.y =300};
  // p2 = new P{.x=200}; // Cannot assign to variable 'p2' with const-qualified
  // type 'P *const'
  delete p2;

  return 0;
}