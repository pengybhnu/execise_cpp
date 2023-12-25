#include <iostream>
#include <boost/asio.hpp>
int num = 0;
void printHello(const boost::system::error_code& /*error*/,
                boost::asio::steady_timer*const timer) {
  std::cout << "hello " << num++ << std::endl;
  if (num > 10) {
   return;
  }
  timer->expires_after(std::chrono::seconds(1));
  timer->async_wait([timer](const boost::system::error_code& error) {
    printHello(error, timer);
  });
}

int main() {
  boost::asio::io_context ioContext;
  auto timer = std::make_unique<boost::asio::steady_timer> (ioContext);
  boost::asio::steady_timer* const t = timer.get();
  timer->expires_after(std::chrono::seconds(1));
  timer->async_wait([t](const boost::system::error_code& error) {
    printHello(error, t);
  });
  ioContext.run();
 
  return 0;
}