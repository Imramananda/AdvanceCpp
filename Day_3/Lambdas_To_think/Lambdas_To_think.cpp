//
//  main.cpp
//  29_SI_Lambdas_ToThink
//
//  Created by Sathya Babu on 29/05/24.
//
// A messed up code......

#include <memory>
#include <iostream>
#include <utility>


// Higher order fun Parllel execution...
template <class T>
void run(T&& runnable)
{
    // thread..
    runnable();  // holds lambda.. in
};
//--------------------------
int main()
{
    std::unique_ptr<int> result(new int{ 42 });

    run([&result]() {std::cout << *result << std::endl; });
}