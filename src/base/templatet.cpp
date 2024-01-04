
// #include <iostream>
#include <cstdint>
template <typename T>
T Mystest(T a) {
   return  a + (T)789;
}
int add(int a, int b){
    return a + b;
}

int main(int argc, char **argv){
    std::uint32_t x;
    auto f1 = Mystest(3);
    auto f2 = Mystest(3.39);
    Mystest(x);
    return 0;
}