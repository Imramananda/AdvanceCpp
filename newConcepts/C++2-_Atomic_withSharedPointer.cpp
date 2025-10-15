#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

std::atomic<int> counter = 0;

//int counter = 0;

void increment()
{

    cout<<"Rama increament "<<endl;
    for (int i = 0; i < 1000; ++i)
        ++counter; // atomic increment
}

int main()
{
    cout<<"Rama Start main function "<<endl;
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final counter: " << counter << "\n"; // 2000 guaranteed
}
