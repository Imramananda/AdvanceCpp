//
//  main.cpp
//  30_SI_thread_state_Callback
//
//  Created by Sathya Babu on 30/05/24.
//


#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <functional>
using namespace std;

enum class ThreadState {
    Running,
    Completed,
    Errored
};

void run_with_callback(const std::function<void(ThreadState)>& callback) {
    // Start a new thread and run a task
    std::thread t([callback]() {
        try {
            // Simulate some work
            std::this_thread::sleep_for(std::chrono::seconds(2));
            // Report the task completed
            callback(ThreadState::Completed);
        }
        catch (...) {
            // Report the task errored
            callback(ThreadState::Errored);
        }
        });

    // Report the task running
    callback(ThreadState::Running);

    // Wait for the thread to finish
    t.join();
}
int main(int argc, const char* argv[]) {

    std::vector< std::future< ThreadState >  > futures;

    // Define a callback function to print the state of each thread
    auto callback = [](ThreadState state) {
        switch (state) {
        case ThreadState::Running:
            std::cout << "Thread is running..." << std::endl;
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
        // following line can get into For_each( async /  defered ,  run_with_callback, callback);

        decltype(auto) f = std::async(std::launch::async, run_with_callback, callback);
        //  futures.push_back(std::move(f));
         // futures.emplace_back(std::move(f));
         // futures.push_back( f ) ;
    }

    // Wait for all the tasks to finish and print their states
    for (auto& f : futures) {
        auto state = f.get();
        callback(state);
    }

    return 0;
}
/*
 Thread is running...
 Thread completed successfully.
 Thread is running...
 Thread completed successfully.
 Thread is running...
 Thread completed successfully.
 Thread is running...
 Thread completed successfully.
 Thread is running...
 Thread completed successfully.
 Program ended with exit code: 0
 */
has context menu