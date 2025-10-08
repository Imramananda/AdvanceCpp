//
//  main.cpp
//  29_SI_Lambdas_variadic
//
//  Created by Sathya Babu on 29/05/24.
//
/*
Agenda for the day

Forward..
union - Variant
observer

lambda - various codes - Forward..
???
lambda recursion
tuple
Singleton - legacy way.. with shared_ptr
enabling shared ptr from this..
implementng Observer with a usecase
any
optional
*/
#include <iostream>
using namespace std;


void print() {}

template <typename First, typename... Rest>

void print(const First& first, const Rest... args)
{

    std::cout << first << std::endl;
    print(args...);

}

// regular fold expressions

template< typename ... T>
auto doSomething(T... t)
{
    return(t + ...);
}

int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    // print(1,2,3,4,5);

    auto variadic_generic_lambda = [](auto... param) {   print(param...); };

    variadic_generic_lambda(1, "LOL", 12.22, "Bangalore", 987);
    cout << " fold sum " << doSomething(1, 2, 3, 4, 5) << endl;

    // Fold expressions

    constexpr  auto addSomething = []< class... T >(T... t)
    {
        return(t + ...);
    };

    cout << " fold sum using template" << addSomething(1, 2, 3, 4, 5) << endl;

    return 0;
}