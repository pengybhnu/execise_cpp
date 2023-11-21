
#include <boost/config.hpp>
#if !defined BOOST_NO_CXX11_DECLTYPE
#define BOOST_RESULT_OF_USE_DECLTYPE
#endif

#define BOOST_THREAD_VERSION 4
// #define BOOST_THREAD_USES_LOG
#define BOOST_THREAD_USES_LOG_THREAD_ID

#include <boost/thread/executors/basic_thread_pool.hpp>
#include <boost/thread/future.hpp>
#include <boost/thread/thread_pool.hpp>
#include <iostream>
#include <vector>

int main() {
  // boost::basic_thread_pool  pool;

  // auto future = boost::threadpool::schedule(pool, );
  boost::future<void> future = boost::async([]() {
    // Task logic here
    std::cout << "Task executed" << std::endl;
    boost::this_thread::sleep_for(boost::chrono::seconds(2));
  });
  boost::future<int> count = boost::async([]() {
    // Task logic here
    std::cout << "Task executed" << std::endl;
    boost::this_thread::sleep_for(boost::chrono::seconds(2));
    return 2;
  });
  auto f2 = future.then([](boost::future<void> continuationFuture) {
    // Continuation task logic here
    std::cout << "Continuation task executed" << std::endl;
  });
 

  (void)f2.get();

  std::vector<int> nums;
  std::cout << nums.size() << " " << nums.capacity() << std::endl;

  return 0;
}