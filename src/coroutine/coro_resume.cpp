#include <coroutine>
#include <iostream>
 
struct promise;
 
struct coroutine : std::coroutine_handle<promise>
{
    using promise_type = ::promise;
};
 
struct promise
{
    coroutine get_return_object() { return {coroutine::from_promise(*this)}; }
    std::suspend_always initial_suspend() noexcept { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    void return_void() {}
    void yield_value(){}
    void unhandled_exception() {}
};
 
// struct S
// {
//     int i;
//     coroutine f()
//     {
//         std::cout << i;
//         co_return;
//     }
// };

 
int main(int argc, char* argv[])
{
   coroutine h = [](int i) -> coroutine // make i a coroutine parameter
    {
        std::cout << i << "\n";
        co_return;
    }(3);
    // lambda destroyed
    // h.resume(); 
    h.destroy();
    return 0;
}
 