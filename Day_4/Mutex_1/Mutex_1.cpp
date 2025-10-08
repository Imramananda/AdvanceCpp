//
//  main.cpp
//  30_SI_mutex_1
//
//  Created by Sathya Babu on 30/05/24.
//

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

int myCash = 0;


std::mutex m;

void addMoney() {    // can be delt with Atomic..
    m.lock();
    ++myCash;
    m.unlock();
}

int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    std::thread t1(addMoney);  // 1
    std::thread t2(addMoney);  // 2


    t1.join();
    t2.join();

    cout << " My cash : " << myCash << endl;
    return 0;
}
has context menu