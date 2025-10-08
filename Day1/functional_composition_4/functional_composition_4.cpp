//
//  main.cpp
//  SI_Functional_Composition_4
//
//  Created by Sathya Babu on 27/05/24.
//

#include <iostream>
#include<functional>
using namespace std;

// not implemented.... FYI
template< typename  Fn, typename T>
struct is_invokable_with : std::is_invocable<Fn, T> {};

template<typename T>
struct is_variable : std::is_object< T > {};

constexpr auto add(const int x, const int y) -> int {
    return x + y;
}

template<typename ... Args>
constexpr auto add(Args... args) -> int {
    return (args + ...);
}
constexpr auto mull(const int x, const int y) -> int {
    return x * y;
}

// way of coding ios depricated...
int (*myFNPTR)(int x, int y) = add;
// C++ 11
//std::function< int (int,int) > func = add ;

template< typename  FN, typename... Args>
auto resultOfCalc_2(const FN& op,
    Args... args
) //-> decltype(op(args...))
{

    return op(args...);
}


int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    cout << " Functional composition : " << resultOfCalc_2(add<int, int, int, int>, 123, 200, 400, 500) << endl;
    return 0;
}
/*
Hello, World!
Functional composition : 1223
Program ended with exit code: 0
*/