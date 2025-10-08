//
//  main.cpp
//  30_SI_thread_state_Callback_PB
//
//  Created by Sathya Babu on 30/05/24.
//

#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <functional>
#include <chrono>
#include <iomanip>

enum class ThreadState {
    Running,
    Completed,
    Errored
};

// Define a function that takes a callback and runs it asynchronously
void run_with_callback(const std::function<void(ThreadState, int)>& callback, int val) {
    // Start a new thread and run a task
    std::thread t([callback, val]() {
        try {
            // Simulate some work
            for (int i = 10; i <= val; i += 10) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                callback(ThreadState::Running, i); // Report progress from 10% to 100%
            }
            // Report the task completed
            callback(ThreadState::Completed, 100); // Pass 100 when task completes
        }
        catch (...) {
            // Report the task errored
            callback(ThreadState::Errored, 0);
        }
        });

    // Report the task running
    callback(ThreadState::Running, 0); // Pass 0 when task is running

    // Wait for the thread to finish
    t.join();
}

int main() {
    // Create a vector to hold the futures for each task
    std::vector<std::future<void>> futures;

    // Define a callback function to print the state of each thread
    auto callback = [](ThreadState state, int progress) {
        switch (state) {
        case ThreadState::Running:
            std::cout << "Thread is running... Progress: " << std::setw(3) << progress << "%" << std::endl;
            break;
        case ThreadState::Completed:
            std::cout << "Thread completed successfully." << std::endl;
            break;
        case ThreadState::Errored:
            std::cout << "Thread encountered an error." << std::endl;
            break;
        }
        };

    // Start multiple tasks asynchronously and store their futures
    for (int i = 0; i < 5; ++i) {
        futures.emplace_back(std::async(std::launch::async, run_with_callback, callback, 100));
    }

    // Wait for all the tasks to finish
    for (auto& f : futures) {
        f.get();
    }

    return 0;
}
/*
Thread is running... Progress:   0%
Thread is running... Progress:   0%
Thread is running... Progress:   0%
Thread is running... Progress:   0%
Thread is running... Progress:   0%
Thread is running... Progress:  10Thread is running... Progress:  10%
Thread is running... Progress: Thread is running... Progress:  10%
  10Thread is running... Progress:  10%%

%
Thread is running... Progress: Thread is running... Progress:  20%
  20%
Thread is running... Progress:  20%
Thread is running... Progress:  20%
Thread is running... Progress:  20%
Thread is running... Progress: Thread is running... Progress: Thread is running... Progress:  30%
   30%
30%
Thread is running... Progress:  30%
Thread is running... Progress:  30%
Thread is running... Progress: Thread is running... Progress: Thread is running... Progress:  40Thread is running... Progress: %
  40%
  40%
Thread is running... Progress:  40%
  40%
Thread is running... Progress:  50%
Thread is running... Progress:  Thread is running... Progress: 50%
Thread is running... Progress:  50%
Thread is running... Progress:  50%
  50%
Thread is running... Progress:  60%
Thread is running... Progress:  60%
Thread is running... Progress:  60%Thread is running... Progress:  60%

Thread is running... Progress:  60%
Thread is running... Progress:  70%
Thread is running... Progress:  70%
Thread is running... Progress: Thread is running... Progress:  70%
  70%
Thread is running... Progress:  70%
Thread is running... Progress:  80%
Thread is running... Progress:  Thread is running... Progress: Thread is running... Progress: 80%
  80%80%

Thread is running... Progress:  80%
Thread is running... Progress:  90%
Thread is running... Progress:  90%
Thread is running... Progress:  90%
Thread is running... Progress:  90%
Thread is running... Progress:  90%
Thread is running... Progress: 100%
Thread completed successfully.
Thread is running... Progress: 100%
Thread completed successfully.
Thread is running... Progress: Thread is running... Progress: 100%
Thread completed successfully.
100%
Thread completed successfully.
Thread is running... Progress: 100%
Thread completed successfully.
Program ended with exit code: 0
*/