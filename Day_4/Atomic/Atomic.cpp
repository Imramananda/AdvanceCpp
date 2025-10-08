//
//  main.cpp
//  30_SI_atomic
//
//  Created by Sathya Babu on 30/05/24.
//

#include <iostream>
#include <atomic>         // std::atomic,
#include <thread>         // std::thread
using namespace std;


int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "atomic !\n";

    std::atomic< int > counter = 0;
    // int counter = 0 ;
    auto work = [&counter]() {

        for (int i = 0; i < 10000; i++)
            counter += 1;
        };

    std::thread t1(work);
    std::thread t2(work);

    t1.join();
    t2.join();

    cout << " Counter = " << counter << endl;

    return 0;
}
//  Counter = 20000
has context menu