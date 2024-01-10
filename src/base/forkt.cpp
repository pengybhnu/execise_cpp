#include <sys/types.h>
#include <unistd.h>

#include <iostream>
#include <thread>
void init() {
  int x = 0;
  std::cout << "fork one" << std::endl;
  // Create a new session
//   if (setsid() < 0) {
//     fprintf(stderr, "Failed to create a new session\n");
//     exit(1);
//   }
  while (x < 20) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "hello fork" << std::endl;

    ++x;
  }
  exit(0);
}
int main(int argc, char* argv[]) {
  if (!fork()) {
    init();
  }
  int x = 0;
  while (x <5) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "main" << std::endl;
    ++x;
  }
  return 0;
}