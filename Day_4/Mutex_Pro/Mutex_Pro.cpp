//
//  main.cpp
//  30_SI_mutex_Pro
//
//  Created by Sathya Babu on 30/05/24.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

std::mutex mtx;
std::condition_variable condition;
double balance = 0;


void addCash(int cash) {
    std::this_thread::sleep_for(std::chrono::seconds(3)); // Simulate some work
    {
        std::lock_guard<std::mutex> lock(mtx);
        balance += cash;
        std::cout << " Cash added to the bank balance : " << balance << std::endl;
    }
    // mtx.unlock();
    condition.notify_one(); // Notify waiting thread
}


// 1/4th ms keeps calling
void withDrawCash(int cash) {
    std::unique_lock<std::mutex> lock(mtx);

    cout << " About to withdraw cash.." << endl;
    cout << " waiting for lock to open .." << endl;
    condition.wait(lock, [] {


        cout << " lock is open now .." << endl;

        return  (balance != 0) ? true : false;
        }

    );

    if (balance > cash)
    {
        balance -= cash;
        std::cout << "cash withdrawn  : " << cash << std::endl;

    }
    else {
        balance -= cash;
        std::cout << "Requested cash is less than the balance.  " << cash << std::endl;
    }


    std::cout << "current balance is : " << balance << std::endl;

}

int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::thread t2(withDrawCash, 500);
    std::thread t1(addCash, 900);
    std::thread t3(withDrawCash, 100);  // you ghave to be notifyed to withdraw else u have to wait until addCash complets the depositing process..


    t1.join();
    t2.join();
    t3.join();

    return 0;
}
has context menu