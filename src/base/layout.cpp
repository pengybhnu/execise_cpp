
class Point {
 private:
  double x;
  double y;
  long int num;

 public:
  Point(double x, double y, long int num) {}
  double getX() { return x; }
  double getY() { return y; }
  int getNum() { return num; }
  virtual double getCenter() {return 0;};
  virtual double getEndx() {return 0;};
};

class Base{
  public:
    char type;
    virtual char getTpye() {return type;};
};

class Dpoint : public Point,Base {
 public:
  Dpoint(double x, double y, long int num,  int id) : Point(x, y, num), id(id) {}
  double getCenter() { return getX() * getY(); }
  virtual  int getId() { return id; };

 private:
   int id;
};

int main(int argc, char* argv[]) {
  Dpoint p(1, 2, 3,6);
  return 0;
}
// dump_vtables:
// clang -cc1 -fdump-record-layouts -emit-llvm  $(file) >
// clang-vtable-layout-$(file).txt clang -cc1 -fdump-vtable-layouts -emit-llvm
// $(file) > clang-record-layout-$(file).txt g++ -fdump-lang-class=$(file).txt
// $(file) cl.exe $(file) /d1reportSingleClassLayoutMEOW >
// msvc-single-class-vtable-layout-$(file).txt cl.exe $(file)
// /d1reportAllClassLayout > msvc-all-class-vtable-layout-$(file).txt