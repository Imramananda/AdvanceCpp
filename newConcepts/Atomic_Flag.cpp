#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
using namespace std;

std::atomic<bool> stopFlag{false};

//std::cout<<" Ramaglobal stopFLag : "<<stopFlag<<endl;


void worker() {
    while (!stopFlag.load()) {
        std::cout<<"Rama int worked function stopFLag : "<<stopFlag<<endl;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout<<"Rama int worked function stopFLag : "<<stopFlag<<endl;
    std::cout << "\nWorker stopped.\n";
}

int main() {
    std::thread t(worker);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    stopFlag.store(true); // safely signal thread to stop
    cout<<"Rama in main function stopFLag : "<<stopFlag<<endl;
    t.join();
}
