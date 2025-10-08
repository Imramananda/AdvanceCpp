//
//  main.cpp
//  30_SI_Producer_Consumer_Pro
//
//  Created by Sathya Babu on 30/05/24.
//

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>

std::mutex mutex;
std::condition_variable condVar;
std::queue<int> buffer;
const int maxSize = 5;
bool finished = false;


void producer() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mutex);
        condVar.wait(lock, [] { return buffer.size() < maxSize; });
        buffer.push(i);
        std::cout << "Produced: " << i << std::endl;
        lock.unlock();
        condVar.notify_one();
    }

    std::lock_guard<std::mutex> lock(mutex);
    finished = true;
    condVar.notify_all();
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mutex);
        condVar.wait(lock, [] { return !buffer.empty() || finished; });

        if (!buffer.empty()) {
            int data = buffer.front();
            buffer.pop();
            std::cout << "Consumed: " << data << std::endl;
            lock.unlock();
            condVar.notify_one();
        }
        else if (finished) {
            break;
        }
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}
has context menu