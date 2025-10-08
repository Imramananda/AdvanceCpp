//
//  main.cpp
//  30_SI_ref_wrappers
//
//  Created by Sathya Babu on 30/05/24.
//
/*

Agenda for the day..
1.  ref_wrappers  -> vectors...
2.  enable_shared_this
3.  Visitor vs visit and variant..
4.  threads...

Study code Visitor with enable_shared_this
Observer with lambdas..
Car application.. having a Async thread in a complicated case..




// Afternoon
     structured array
    Aggregate
tupple  - study app on tupple recursion with variadic expressions..
any
optioonal
inline namespace..


5PM MCQ...
Feed back- COnsolidated..
MCQ..



*/

#include <iostream>
#include <vector>
using namespace std;

// Function to print a vector
void printVector(const std::vector<int>& vec) {
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

// Function to increment each element of a vector
void incrementVector(std::vector<int>& vec) {
    for (auto& val : vec) {
        ++val;
    }
}

int main() {
    // Creating a few vectors
    std::vector<int> vec1 = { 5, 3, 4 };
    std::vector<int> vec2 = { 1, 7, 2 };
    std::vector<int> vec3 = { 9, 6, 8 };

    // Store pointers to these vectors
    std::vector< std::reference_wrapper< std::vector<int> >> vectorPtrs = { vec1, vec2, vec3 };

    // Sort each vector
    for (auto& vecRef : vectorPtrs) {
        // std::sort(vecRef->begin(), vecRef->end());
        std::sort(vecRef.get().begin(), vecRef.get().end());
    }

    // Increment each element in each vector
    for (auto& vecRef : vectorPtrs) {
        //        incrementVector( *vecPtr );
        incrementVector(vecRef.get());
    }

    // Print each sorted and incremented vector
    std::cout << "Vectors after sorting and incrementing:\n";
    for (const auto& vecRef : vectorPtrs) {
        //        printVector(*vecRef);
        printVector(vecRef.get());
    }

    return 0;
}


/*



#include <iostream>
#include <vector>
using namespace std ;

// Function to print a vector
void printVector(const std::vector<int>& vec) {
     for (const auto& val : vec) {
         std::cout << val << " ";
     }
     std::cout << "\n";
}

// Function to increment each element of a vector
void incrementVector(std::vector<int>& vec) {
     for (auto& val : vec) {
         ++val;
     }
}

int main() {
     // Creating a few vectors
     std::vector<int> vec1 = {5, 3, 4};
     std::vector<int> vec2 = {1, 7, 2};
     std::vector<int> vec3 = {9, 6, 8};

     // Store pointers to these vectors
     std::vector< std::vector<int>* > vectorPtrs = {&vec1, &vec2, &vec3};

     // Sort each vector
     for (auto vecPtr : vectorPtrs) {
         std::sort(vecPtr->begin(), vecPtr->end());
     }

     // Increment each element in each vector
     for (auto vecPtr : vectorPtrs) {
         incrementVector( *vecPtr );
     }

     // Print each sorted and incremented vector
     std::cout << "Vectors after sorting and incrementing:\n";
     for (const auto vecPtr : vectorPtrs) {
         printVector(*vecPtr);
     }

     return 0;
}

*/