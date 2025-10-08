#include <iostream>

size_t allocationCount = 0;

void* operator new(size_t size) {
    allocationCount++;
    return malloc(size);
}

void operator delete(void* ptr) noexcept {
    allocationCount--;
    free(ptr);
}

int main() {
    int* leak = new int[10]; // Simulate leak
    std::cout << "Allocations remaining: " << allocationCount << std::endl;
    return 0;
}
