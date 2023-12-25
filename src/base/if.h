#include <memory>

class Pif {
 private:
  class Pimpl;
  std::unique_ptr<Pimpl> pi_;

 public:
  explicit Pif();
  int Get();
  void Set(double x);
  ~Pif();
};