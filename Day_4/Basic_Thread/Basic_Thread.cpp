//
//  main.cpp
//  30_SI_basicThreads
//
//  Created by Sathya Babu on 30/05/24.
//

#include <iostream>
#include <thread>
#include <algorithm>
#include <mutex>
#include <chrono>
#include <future>
using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull EvenSum = 0;

ull OddSum = 0;

void findEven(ull start, ull end)
{
    for (ull i = start; i <= end; i++) {
        if (i % 2) {
            EvenSum += i;
        }
    }
}


void findODD(ull start, ull end)
{
    for (ull i = start; i <= end; i++) {
        if (!(i % 2)) {
            OddSum += i;
        }
    }
}


int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Threads.... \n";

    ull start = 0, end = 1900000000;

    auto startTime = high_resolution_clock::now();

    // Phase I

//       findEven(start, end);  // 6 sec..
//       findODD( start,end);

    // Phase II

//    std::thread t1( findEven,  start,end );  // 1/4th of a ms..
//    std::thread t2( findODD,  start,end );
//    
//    t1.join();
//    t2.join();   // 3 sec...

    // Phase III Lambdas..
    std::thread t1([&] { (findEven, start, end);    });
    std::thread t2([&] { (findODD, start, end);   });
    t1.join();
    t2.join();

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    cout << " Sec : " << duration.count() / 1000000 << endl;
    return 0;
}
has context menu