#include <iostream>

int findMissingNumber(int arr[], int n) {
    int total = (n * (n + 1)) / 2;
    for (int i = 0; i < n - 1; i++) {
        total -= arr[i];
    }
    return total;
}

int main() {
    int n = 5;
    int arr[] = {1, 3, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (size == n) {
        std::cout << "No missing number" << std::endl;
    } else {
        int missingNumber = findMissingNumber(arr, n);
        std::cout << "Missing number is: " << missingNumber << std::endl;
    }


    return 0;
}