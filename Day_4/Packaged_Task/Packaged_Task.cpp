//
//  main.cpp
//  30_SI_packegedTask
//
//  Created by Sathya Babu on 30/05/24.
//
// Please reffer to the study code...

#include <iostream>
#include <thread>
#include <future>

static void extractedDelay() {
    for (int i = 0; i < 80000; i++) {
        for (int ii = 0; ii < 80000; ii++) {
        }
    }
}

int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "task executed is Async.. \n";
    std::packaged_task< int() > task([]() {
        std::this_thread::sleep_for(std::chrono::seconds(3));// blocking for 3 sec..
        return  7;
        });

    std::future< int > result = task.get_future();

    std::thread(std::move(task)).detach();

    std::cout << "waiting...";
    //  result.wait(); // block until future has arrived
      // output result
    std::cout << "done!" << std::endl << "future result is " << result.get() << std::endl; return 0;

    return 0;
}
has context menu