#include "base/if.h"
// #include "base/imp.h"
#include <iostream>
class Pif::Pimpl {
 public:
  double x{300};
  int Get();
  ~Pimpl();
};
int Pif::Pimpl::Get() { return x; }
Pif::Pimpl::~Pimpl() { std::cout<< " " << std::endl; }
int Pif::Get() { return pi_->Get(); }
void Pif::Set(double x) { pi_->x = x; }

Pif::Pif() {
  pi_ = std::make_unique<Pimpl>();
  pi_->x = 200;
}
Pif::~Pif()=default;

