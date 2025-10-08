#include <memory>
#include <iostream>
#include <utility>

template <class T> void run(T&& runnable)
{
    runnable();
};

template <class T> struct smart_wrap
{
    T payload;
    smart_wrap(T&& payload) : payload(std::forward<T>(payload)) {}  // (a)
    smart_wrap(smart_wrap& other) : payload(std::move(other.payload)) {} // (b)
}
;

int main() {

    int myVal = 393; // rvalue
    smart_wrap<std::unique_ptr<int>> result{ std::unique_ptr<int>{new int{myVal}} };  // (a)  rvalue
    run([result]() {std::cout << *result.payload << std::endl; });

    smart_wrap<std::unique_ptr<int>> result2{ std::unique_ptr<int>{new int{42} } }; //lvalue
    run([result2]() {std::cout << *result2.payload << std::endl; });

}
// 393
// 42