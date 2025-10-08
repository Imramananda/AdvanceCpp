//
//  main.cpp
//  30_SI_AsyncDeffred
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

typedef long ull;


ull EvenSum = 0;

ull OddSum = 0;

ull findEven(ull start, ull end)
{
    ull EvenSum = 0;

    cout << "  Find Even Async Thread  ID : " << std::this_thread::get_id() << endl;

    for (ull i = start; i <= end; i++) {
        if (i % 2) {
            EvenSum += i;
        }
    }
    return EvenSum;
}



ull findODD(ull start, ull end)
{
    ull EvenSum = 0;
    cout << "  Find ODD Async Thread  ID : " << std::this_thread::get_id() << endl;

    for (ull i = start; i <= end; i++) {
        if (!(i % 2)) {
            OddSum += i;
        }
    }
    return  OddSum;
}


int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Just about t hreads...!\n";

    ull start = 0, end = 1900000000;

    // Co routines.. Faster..
    auto startTime = high_resolution_clock::now();

    //    cout << " Async thread ID " << std::this_thread::get_id() << endl ;
    //    
    //    std::future< ull > EvenSum = std::async(std::launch::async,findEven,start,end);
    //    std::future< ull > EvenOdd= std::async(std::launch::async,findODD,start,end);
    //    

        // deffred thread are blocking threads...

    cout << " Deffred  thread ID " << std::this_thread::get_id() << endl;
    std::future< ull > EvenSum = std::async(std::launch::deferred, findEven, start, end);
    std::future< ull > EvenOdd = std::async(std::launch::deferred, findODD, start, end);
    std::cout << "Just for fun...\n";

    // following line is not t1.join()
    // WRONG... bring in an observer..
    cout << "even sum " << EvenSum.get() << endl;
    cout << "Odd sum " << EvenOdd.get() << endl;


    cout << " Job done... " << endl;


    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout << " Sec : " << duration.count() / 1000000 << endl;  // count()⁄1,000,000) of a second.


    return 0;
}
has context menu